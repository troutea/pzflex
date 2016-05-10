// file: BST.h

#pragma once

//class
class BST
{
    struct Node    //struct for nodes
    {
        int key;
        Node* pLeft;
        Node* pRight;
    };

private:
    Node* m_pRoot; // m_ Denotes that the variable belong to the class (e.g. My variable)

    void AddLeaf(int key, Node* pLeaf); // Overloaded function
    void PrintInOrder(Node* Ptr); // Overloaded function

public:
    BST();  //constructor
    static bool AreTreesEqual(const Node* pRoot1, const Node* pRoot2);

    Node* GetRootNode(){ return m_pRoot; } // Getter

    static Node* CreateLeaf(int key);

    void AddLeaf(int key);

    void PrintInOrder();
};
