
// Aryan Nirala 25/DA/015

#include <iostream>
using namespace std;

// Function to heapify a subtree
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to display the array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

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

    int* arr = new int[n];

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal Array: ";
    display(arr, n);

    // Apply Heap Sort
    heapSort(arr, n);

    cout << "Sorted Array using Heap Sort: ";
    display(arr, n);

    delete[] arr;

    return 0;
}

