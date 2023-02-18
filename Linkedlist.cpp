#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linkedlist
{

public:
    Node *head;

    Linkedlist()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void insertFirst(int newValue)
    {
        Node *newNode = new Node();
        newNode->data = newValue;
        if (isEmpty())
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertLast(int newValue)
    {

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        Node *newNode = new Node();
        newNode->data = newValue;
        temp->next = newNode;
        newNode->next = NULL;
    }

    void insertIndex(int index, int newValue)
    {

        Node *temp = head;
        int tempIndex = 0;

        while (tempIndex != index - 1)
        {
            temp = temp->next;
            tempIndex++;
        }
        cout << temp->data << endl;
        Node *newNode = new Node();
        newNode->data = newValue;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    int length()
    {
        int counter = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool search(int searchValue)
    {
        Node *temp = head;
        bool valueFound = false;

        while (temp != NULL)
        {
            if (temp->data == searchValue)
            {
                valueFound = true;
            }
            temp = temp->next;
        }

        return valueFound;
    }

    void deleteItem(int deleteValue)
    {
        if (isEmpty())
        {
            cout << "Linkedlist is empty, no items to delete" << endl;
        }

        Node *deltptr = head;

        if (head->data == deleteValue)
        {

            head = head->next;
            delete deltptr;
        }
        else
        {

            Node *prev = NULL;
            deltptr = head;

            while (deltptr->data != deleteValue)
            {
                {
                    prev = deltptr;
                    deltptr = deltptr->next;
                }
            }
            prev->next = deltptr->next;
            delete deltptr;
        }
    }
};

int main()
{
    Linkedlist lst;
    if (lst.isEmpty())
    {
        cout << "Linkedlist is empty" << endl;
    }
    else
    {
        cout << "Linkedlist is not empty" << endl;
    }

    int numOfItems;
    cout << "Enter num of items to insert in the list: ";
    cin >> numOfItems;

    for (int i = 0; i < numOfItems; i++)
    {
        int newItem;
        cout << "Enter item num " << i << ": ";
        cin >> newItem;
        lst.insertFirst(newItem);
    }

    cout << "List items : ";
    lst.display();

    cout << "Length of the list = " << lst.length() << endl;

    int searchItem;
    cout << "Enter item to search for: ";
    cin >> searchItem;
    if (lst.search(searchItem))
    {
        cout << "Item is found in the list " << endl;
        ;
    }

    else
    {
        cout << "Item is not found in the list " << endl;
        ;
    }

    int deleteItem;
    cout << "Enter item to delete for: ";
    cin >> deleteItem;
    lst.deleteItem(deleteItem);

    cout << "List items : ";
    lst.display();
}
