#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node *left = NULL;
    Node *right = NULL;
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    Node *insert(Node *pnode, int newValue)
    {
        if (pnode == NULL)
        {
            Node *newnode = new Node();
            newnode->data = newValue;

            pnode = newnode;
        }
        else if (newValue < pnode->data)
        {
            pnode->left = insert(pnode->left, newValue);
        }
        else
        {
            pnode->right = insert(pnode->right, newValue);
        }

        return pnode;
    }

    void insert(int newValue)
    {
        root = insert(root, newValue);
    }

    void DisplayPreOrder(Node *r) // root-> left-> right
    {
        if (r == NULL)
            return;

        cout << r->data << "\t";
        DisplayPreOrder(r->left);
        DisplayPreOrder(r->right);
    }

    void DisplayINOrder(Node *r) // left -> root-> right
    {
        if (r == NULL)
            return;

        DisplayINOrder(r->left);
        cout << r->data << "\t";
        DisplayINOrder(r->right);
    }

    void DisplayPostOrder(Node *r) // left-> right ->root
    {
        if (r == NULL)
            return;

        DisplayPostOrder(r->left);
        DisplayPostOrder(r->right);
        cout << r->data << "\t";
    }

    Node *search(Node *r, int val)
    {
        if (r == NULL)
            return NULL;
        else if (r->data == val)
            return r;
        else if (r->data > val)
            return search(r->left, val);
        else
            return search(r->right, val);
    }

    bool search(int val)
    {
        Node *result = search(root, val);
        if (result == NULL)
            return false;
        else
            return true;
    }

    Node *findMin(Node *r)
    {
        if (r == NULL)
            return NULL;
        else if (r->left == NULL)
            return r;
        else
            return findMin(r->left);
    }

    void findMin()
    {
        Node *tempNode = findMin(root);
        if (tempNode == NULL)
        {
            cout << "Binary search tree is empty" << endl;
        }
        else
        {
            cout << "Minimum item is " << tempNode->data << endl;
        }
    }

    Node *findMax(Node *r)
    {
        if (r == NULL)
            return NULL;
        else if (r->right == NULL)
            return r;
        else
            return findMax(r->right);
    }

    void findMax()
    {
        Node *tempNode = findMax(root);
        if (tempNode == NULL)
        {
            cout << "Binary search tree is empty" << endl;
        }
        else
        {
            cout << "Maximum item is " << tempNode->data << endl;
        }
    }

    Node *deleteNode(Node *r, int val)
    {
        if (r == NULL) // Empty tree
            return NULL;
        else if (val < r->data) // Item exists in left sub tree
            r->left = deleteNode(r->left, val);
        else if (val > r->data) // Item exists in right sub tree
            r->right = deleteNode(r->right, val);

        else
        {
            if (r->left == NULL && r->right == NULL) // leaf node
            {
                r = NULL;
            }

            else if (r->left != NULL && r->right == NULL) // One child on the left
            {
                r->data = r->left->data;
                delete r->left;
                r->left = NULL;
            }

            else if (r->left == NULL && r->right != NULL) // One child on the right
            {
                r->data = r->right->data;
                delete r->right;
                r->right = NULL;
            }
            else
            {
                Node *max = findMax(r->left);
                r->data = max->data;
                r->left = deleteNode(r->left, max->data);
            }
        }
        return r;
    }

    void deleteItem(int val)
    {
        root = deleteNode(root, val);
    }
};

int main()
{

    BST btree;

    int numOfItems;
    cout << "Enter num of items to insert : ";
    cin >> numOfItems;

    for (int i = 0; i < numOfItems; i++)
    {
        int newItem;
        cout << "Enter item to insert : ";
        cin >> newItem;
        btree.insert(newItem);
    }

    cout << "\nPreOrder : ";
    btree.DisplayPreOrder(btree.root);

    cout << "\nInOrder : ";
    btree.DisplayINOrder(btree.root);

    cout << "\nPostOrder : ";
    btree.DisplayPostOrder(btree.root);

    cout << endl;
    btree.findMin();
    btree.findMax();

    cout << "Enter item to search for : ";
    int searchedItem;
    cin >> searchedItem;
    int searchedResult = btree.search(searchedItem);
    if (searchedResult)
    {
        cout << "Items found in Binary Search Tree" << endl;
    }
    else
    {
        cout << "Items not found in Binary Search Tree" << endl;
    }

    cout << "Enter item to delete : ";
    int deletedItem;
    cin >> deletedItem;
    btree.deleteItem(deletedItem);

    cout << "InOrder : ";
    btree.DisplayINOrder(btree.root);

    system("pause");
}