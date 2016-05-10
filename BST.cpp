
#include <iostream>
#include <cstdlib>

#include "BST.h"


using namespace std;

BST::BST() : m_pRoot(NULL) //  initialization
{
}

//check if the tress are equal
bool BST::AreTreesEqual(const Node* pRoot1, const Node* pRoot2)
{
    if (pRoot1 == NULL && pRoot2 == NULL)
    {
        return true;
    }

    if ((pRoot1 == NULL && pRoot2 != NULL) || (pRoot1 != NULL && pRoot2 == NULL))
    {
        return false;
    }

    if (pRoot1->key != pRoot2->key)
    {
        return false;
    }

    return AreTreesEqual(pRoot1->pLeft, pRoot2->pLeft) &&
        AreTreesEqual(pRoot1->pRight, pRoot2->pRight);
}


//create a leaf for each node
BST::Node* BST::CreateLeaf(int key)
{
    Node* n = new Node;
    n->key = key;
    n->pLeft = NULL;
    n->pRight = NULL;

    return n;
}

void BST::AddLeaf(int key)
{
    AddLeaf(key, m_pRoot);
}


//add a leaf
void BST::AddLeaf(int key, Node* pLeaf)
{
    if (m_pRoot == NULL)
    {
        m_pRoot = CreateLeaf(key);
    }
    else if (key < pLeaf->key)
    {
        if (pLeaf->pLeft != NULL)
        {
            AddLeaf(key, pLeaf->pLeft);
        }
        else
        {
            pLeaf->pLeft = BST::CreateLeaf(key);
        }
    }
    else if (key > pLeaf->key)
    {
        if (pLeaf->pRight != NULL)
        {
            AddLeaf(key, pLeaf->pRight);
        }
        else
        {
            pLeaf->pRight = BST::CreateLeaf(key);
        }
    }
}

void BST::PrintInOrder()
{
    PrintInOrder(m_pRoot);

}

void BST::PrintInOrder(Node* Ptr)
{
    if (m_pRoot != NULL)
    {
        if (Ptr->pLeft != NULL)
        {
            PrintInOrder(Ptr->pLeft);
        }
        cout << Ptr->key << " \n";

        if (Ptr->pRight != NULL)
        {
            PrintInOrder(Ptr->pRight);
        }
    }
    else
    {
        cout << "The tree is empty\n";
    }
}
