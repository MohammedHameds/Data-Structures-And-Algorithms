#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node *next = NULL;
};

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        return (top == NULL);
    }
    void push(int val)
    {

        Node *newNode = new Node();
        newNode->data = val;

        if (isEmpty())
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
    void display()
    {
        Node *temp = top;

        cout << "Items of the Stack : ";
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty, no items to delete" << endl;
        }
        else
        {
            Node *delptr = top;
            cout << delptr->data << " was deleted from the Stack" << endl;
            top = top->next;
            delete delptr;
        }
    }
    int peak()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        else
        {
            return 0;
        }
    }
    int count()
    {
        int counter = 0;
        Node *temp = top;

        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    int search(int val)
    {
        bool isFound = false;
        Node *temp = top;

        while (temp != NULL)
        {
            if (temp->data == val)
            {
                isFound = true;
            }
            temp = temp->next;
        }
        return isFound;
    }
};

int main()
{
    Stack s;
    int numOfItems;
    cout << "Enter num of items : ";
    cin >> numOfItems;

    for (int i = 0; i < numOfItems; i++)
    {
        int newItem;
        cout << "Enter item num " << i << " : ";
        cin >> newItem;
        s.push(newItem);
    }
    s.display();
    cout << "Top of the Stack is " << s.peak() << endl;
    cout << "Number of items in the Stack is " << s.count() << endl;

    s.pop();
    s.pop();
    s.display();

    int serachItem;
    cout << "Enter item to search for "
         << " : ";
    cin >> serachItem;

    if (s.search(serachItem))
    {
        cout << "Items is found in the Stack" << endl;
    }
    else
    {
        cout << "Items is not found in the Stack" << endl;
    }
}