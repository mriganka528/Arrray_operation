#include <iostream>
using namespace std;
void showArray(int *arr, int size)
{
    cout << "Elements of the array are...." << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] is :" << arr[i] << endl;
    }
}
void insertAt(int *arr, int &size, int position, int element)
{
    size++;
    for (int i = size - 1; i >= position - 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
}
void deleteFrom(int *arr, int position, int &size)
{
    for (int i = position - 1; i <= size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
void sortArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}
void insertInSortedArray(int *arr, int &size, int element)
{
    size++;
    int i;
    for (i = size - 1; arr[i - 1] > element; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[i] = element;
}
int main()
{

    int size, position, element;
    bool ret = true;
    cout << "\nEnter Size of the array :";
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter arr[" << i << "] :";
        cin >> arr[i];
    }
    cout << endl;
    while (ret)
    {
        cout << "Select operation :";
        cout << "\n1)Insertion.\n2)Deletion.\n3)Sort Array.\n4)Insertion in sorted array." << endl;
        int ch;
        cout << "\nEnter your choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter The position and element to enter in the array :";
            cin >> position >> element;
            insertAt(arr, size, position, element);
            cout << "\nAfter inserting ";
            ret = false;
            break;
        case 2:
            deleteFrom(arr, 3, size);
            cout << "\nAfter deletion ";
            ret = false;
            break;
        case 3:
            sortArray(arr, size);
            cout << "\nAfter sorting ";
            ret = false;
            break;
        case 4:
            sortArray(arr, size);
            cout << "\nEnter element to enter in the array :";
            cin >> element;
            insertInSortedArray(arr, size, element);
            cout << "\nAfter inserting ";
            ret = false;
            break;
        default:
            cout << "Wrong choice!!! Select again.....";
            ret = true;
            break;
        }
    }

    showArray(arr, size);
    delete[] arr;
    return 0;
}