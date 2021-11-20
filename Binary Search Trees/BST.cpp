#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BST b;

    b.insertData(10);
    b.insertData(5);
    b.insertData(20);
    b.insertData(3);
    b.insertData(7);
    b.insertData(15);

    b.deleteData(10);

    b.PrintTree();

    return 0;
}