#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node *next;
};

class Queue
{
public:
    Node *front, *tail;
    Queue()
    {
        front = tail = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void enqueue(int val)
    {

        Node *newNode = new Node();
        newNode->data = val;

        if (isEmpty())
        {
            front = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display()
    {
        Node *temp = front;
        if (isEmpty())
        {
            cout << "Queue is empty, no items to show" << endl;
        }
        else
        {
            cout << "Queue items : ";

            while (temp)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int getFront()
    {
        if (!isEmpty())
        {
            return front->data;
        }
        else
        {
            return 0;
        }
    }

    int getTail()
    {
        if (!isEmpty())
        {
            return tail->data;
        }
        else
        {
            return 0;
        }
    }
    int count()
    {
        int counter = 0;
        Node *temp = front;

        while (temp)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool search(int val)
    {
        bool isFound = false;
        Node *temp = front;

        while (temp)
        {
            if (temp->data == val)
            {
                isFound = true;
            }
            temp = temp->next;
        }
        return isFound;
    }

    void dequeue()
    {
        Node *temp = front;

        if (temp)
        {
            cout << "Item " << temp->data << " is deleted from queue " << endl;
            front = front->next;
            delete temp;
        }
    }

    void clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    Queue newQueue;
    int numOfItems;
    cout << "Enter num of items : ";
    cin >> numOfItems;

    for (int i = 0; i < numOfItems; i++)
    {
        int newItem;
        cout << "Enter item num " << i << " : ";
        cin >> newItem;
        newQueue.enqueue(newItem);
    }
    newQueue.display();
    cout << "Top of the Queue is " << newQueue.getFront() << endl;
    cout << "Last item of the Queue is " << newQueue.getTail() << endl;
    cout << "Number of items in the Queue is " << newQueue.count() << endl;

    newQueue.dequeue();
    newQueue.dequeue();

    int serachItem;
    cout << "Enter item to search for "
         << " : ";
    cin >> serachItem;

    if (newQueue.search(serachItem))
    {
        cout << "Items is found in the Queue" << endl;
    }
    else
    {
        cout << "Items is not found in the Queue" << endl;
    }
    newQueue.clear();
    cout << "Number of items in the Queue is " << newQueue.count() << endl;
}