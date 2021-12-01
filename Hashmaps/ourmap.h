#include <string>
using namespace std;

template <typename V>
class Node
{
public:
    string key;
    V value;
    Node<V> *next;

    Node(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    Node<V> **buckets;
    int count;
    int bucketsize;

public:
    ourmap()
    {
        count = 0;
        bucketsize = 10;
        buckets = new Node<V> *[bucketsize];

        for (int i = 0; i < bucketsize; i++)
            buckets[i] = NULL;
    }

    ~ourmap()
    {
        for (int i = 0; i < bucketsize; i++)
            delete buckets[i];
        delete[] buckets;
    }

private:
    int hash(string key)
    {
        int ans = 0;

        int currBase = 1;
        for (int i = key.size() - 1; i >= 0; i--)
        {
            ans += currBase * key[i];
            ans = ans % bucketsize;
            currBase *= 37;
            currBase = currBase % bucketsize;
        }

        return ans % bucketsize;
    }

    void rehashing()
    {
        Node<V> **temp = buckets;

        buckets = new Node<V> *[2 * bucketsize];

        for (int i = 0; i < 2 * bucketsize; i++)
            buckets[i] = NULL;

        int oldBucketSize = bucketsize;
        bucketsize = bucketsize * 2;
        count = 0;

        for (int i = 0; i < oldBucketSize; i++)
        {
            Node<V> *head = temp[i];

            while (head != NULL)
            {
                insert(head->key, head->value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketSize; i++)
        {
            delete temp[i];
        }
        delete[] temp;
    }

public:
    int size()
    {
        return count;
    }

    void insert(string key, V value)
    {
        int hashCode = hash(key);

        Node<V> *head = buckets[hashCode];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        Node<V> *newNode = new Node<V>(key, value);
        newNode->next = buckets[hashCode];

        buckets[hashCode] = newNode;
        count++;

        double loadFactor = (1.0 * count) / bucketsize;

        if (loadFactor > 0.7)
        {
            rehashing();
        }
    }

    V getValue(string key)
    {
        int hashCode = hash(key);

        Node<V> *head = buckets[hashCode];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }

        return 0;
    }

    V removeKey(string key)
    {
        int hashCode = hash(key);

        Node<V> *head = buckets[hashCode];
        Node<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[hashCode] = head->next;
                }
                else
                {
                    prev = head->next;
                }
                V output = head->value;
                head->next = NULL;
                delete head;
                count--;
                return output;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};