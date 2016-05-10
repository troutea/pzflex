#include <iostream>
#include <cstdlib>

#include "BST.h"


using namespace std;

int main()
{
    //test values for tree
    int TreeKeysA[8] = { 50, 76, 29, 6, 33, 65, 16, 15 };
    int TreeKeysB[8] = { 51, 77, 28, 7, 34, 66, 17, 16 };

    BST myTreeA;
    BST myTreeB;



    for (int i = 0; i < 8; i++)
    {
        myTreeA.AddLeaf(TreeKeysA[i]);
        myTreeB.AddLeaf(TreeKeysB[i]);
    }

    // Comparing the trees
    bool bEqual = BST::AreTreesEqual(myTreeA.GetRootNode(), myTreeB.GetRootNode());

    if (bEqual)
    {
        cout << "The binary trees are equal.\n";
    }
    else
    {
        cout << "The binary trees are different.\n";
    }


    cout << "Printing the Binary Tree A in order\n After adding numbers\n";


    myTreeA.PrintInOrder();

    cout << "Printing the Binary Tree B in order\n After adding numbers\n";


    myTreeB.PrintInOrder();



    return 0;
}
