// Aryan Nirala 25/DA/015

#include <iostream>
using namespace std;

// Function to swap two elements
void swapElements(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swapElements(arr[i], arr[j]);
        }
    }

    swapElements(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to display the array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of elements." << endl;
        return 0;
    }

    int *arr = new int[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    display(arr, n);

    // Applying Quick Sort
    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    display(arr, n);

    delete[] arr;

    return 0;
}

