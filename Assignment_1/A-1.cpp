
// Aryan Nirala 25/DA/015

#include <iostream>
using namespace std;

// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Recursive Merge Sort
void recursiveMergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        recursiveMergeSort(arr, left, mid);
        recursiveMergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Iterative Merge Sort
void iterativeMergeSort(int arr[], int n)
{
    for (int width = 1; width < n; width *= 2)
    {
        for (int left = 0; left < n; left += 2 * width)
        {
            int mid = min(left + width - 1, n - 1);
            int right = min(left + 2 * width - 1, n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

// Display array
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

    int* arr1 = new int[n];
    int* arr2 = new int[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    cout << "\nOriginal Array: ";
    display(arr1, n);

    // Recursive method
    recursiveMergeSort(arr1, 0, n - 1);

    cout << "\nSorted Array using Recursive Merge Sort: ";
    display(arr1, n);

    // Iterative method
    iterativeMergeSort(arr2, n);

    cout << "Sorted Array using Iterative Merge Sort: ";
    display(arr2, n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}

