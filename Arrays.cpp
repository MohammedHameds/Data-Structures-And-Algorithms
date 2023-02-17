#include <iostream>
using namespace std;

class Array
{

private:
    int size;
    int length;
    int *items;

public:
    Array(int arrSize)
    {
        items = new int[arrSize];
        length = 0;
        size = arrSize;
    };

    void Fill()
    {
        int numOfItems;
        cout << "How many items you want to fill : ";
        cin >> numOfItems;
        if (numOfItems > size)
        {
            cout << "You can\'t exceed the array size!" << endl;
            return;
        }

        else
        {
            for (int i = 0; i < numOfItems; i++)
            {
                cout << "Enter item number " << i << " : ";
                cin >> items[i];
                length++;
            }
        }
    }

    void Display()
    {
        cout << "Element of the Array : ";

        for (int i = 0; i < length; i++)
        {
            cout << items[i] << "\t";
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }

    int getLength()
    {
        return length;
    }

    int Search(int item)
    {
        int index = -1;

        for (int i = 0; i < length; i++)
        {
            if (items[i] == item)
            {
                index = i;
                break;
            }
        }
        return index;
    }

    void Append(int newItem)
    {
        if (length >= size)
        {
            cout << "Array is full\n";
        }
        else
        {
            items[length] = newItem;
            length++;
        }
    }

    void Insert(int index, int newItem)
    {
        if (index >= size && index >= 0)
        {
            cout << "Array is full\n";
        }

        else
        {
            for (int i = length; i > index; i--)
            {
                items[i] = items[i - 1];
            }
            items[index] = newItem;
            length++;
        }
    }

    void Delete(int deletedIndex)
    {
        if (deletedIndex >= 0 && deletedIndex < size)
        {
            for (int i = deletedIndex; i < length - 1; i++)
            {
                items[i] = items[i + 1];
            }
            length--;
        }
        else
        {
            cout << "Index is out of range\n";
        }
    }

    void Enlarg(int newSize)
    {
        if (newSize <= size)
        {
            cout << "New size must be larger than current size \n";
        }
        else
        {
            size = newSize;
            int *temp = items;
            items = new int[newSize];

            for (int i = 0; i < length; i++)
            {
                items[i] = temp[i];
            }
        }
    }

    void Merge(Array newArr)
    {
        int *oldArr = items;
        int newsize = size + newArr.getSize();
        size = newsize;
        items = new int[size];

        for (int i = 0; i < length; i++)
        {
            items[i] = oldArr[i];
        }
        delete[] oldArr;

        int newLength = length + newArr.getLength();

        int j = length;
        for (int i = 0; i < newArr.getLength(); i++)
        {
            items[j] = newArr.items[i];
            j++;
        }

        length = newLength;
    }
};

int main()
{
    cout << "Hello This is Array ADT demo\n";

    int arrSize;
    cout << "Enter the Array size : ";
    cin >> arrSize;
    Array arr(arrSize);
    arr.Fill();
    arr.Display();
    cout << "Array size is " << arr.getSize() << " ... While Array length is " << arr.getLength() << endl;

    /*Search function */
    int searchKey, searchIndex;
    cout << "Enter item to search for:\n";
    cin >> searchKey;
    searchIndex = arr.Search(searchKey);
    if (searchIndex == -1)
    {
        cout << "Can\'t find element\n";
    }
    else
    {
        cout << "Element found @ index " << searchIndex << endl;
    }

    /*Append function */
    int appendItem;
    cout << "Enter element to add to the Array : ";
    cin >> appendItem;
    arr.Append(appendItem);

    /*Insert function */
    int isertIndex, isertItem;
    cout << "Enter index to insert item : ";
    cin >> isertIndex;
    cout << "Enter new item to insert : ";
    cin >> isertItem;
    arr.Insert(isertIndex, isertItem);

    /*Delete function */
    int deleteIndex;
    cout << "Enter index to delete item : ";
    cin >> deleteIndex;
    arr.Delete(deleteIndex);

    /*Enlarg function */
    int newSize;
    cout << "Enter Array new size : ";
    cin >> newSize;
    arr.Enlarg(newSize);
    cout << "Array size is " << arr.getSize() << " ... While Array length is " << arr.getLength() << endl;

    int newArraySize;
    cout << "Enter the new Array size : ";
    cin >> newArraySize;
    Array newArr(newArraySize);
    newArr.Fill();
    newArr.Display();
    cout << "--------------------------" << endl;

    arr.Merge(newArr);
    arr.Display();
    cout << "Merged Array size is " << arr.getSize() << " ... While Array length is " << arr.getLength() << endl;

    return 0;
}