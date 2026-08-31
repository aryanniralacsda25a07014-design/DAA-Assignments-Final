
// Aryan Nirala 25/DA/015

#include <iostream>
#include <iomanip>
using namespace std;

struct Item
{
    int weight;
    int value;
    double ratio;
};

// Function to sort items by value/weight ratio
void sortItems(Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Fractional Knapsack using Greedy approach
double fractionalKnapsack(Item items[], int n, int capacity)
{
    sortItems(items, n);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    cout << "\nItems selected:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (remainingCapacity == 0)
            break;

        if (items[i].weight <= remainingCapacity)
        {
            // Take the complete item
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;

            cout << "Item " << i + 1 << ": 100% taken"
                 << " (Weight = " << items[i].weight
                 << ", Value = " << items[i].value << ")" << endl;
        }
        else
        {
            // Take the fraction of the item
            double fraction = (double)remainingCapacity / items[i].weight;

            totalValue += items[i].value * fraction;

            cout << "Item " << i + 1 << ": "
                 << fixed << setprecision(2)
                 << fraction * 100 << "% taken"
                 << " (Weight = " << remainingCapacity
                 << ", Value = " << items[i].value * fraction << ")" << endl;

            remainingCapacity = 0;
        }
    }

    return totalValue;
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of items." << endl;
        return 0;
    }

    Item* items = new Item[n];

    cout << "Enter weight and value of each item:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;

        if (items[i].weight <= 0)
        {
            cout << "Weight must be greater than 0." << endl;
            delete[] items;
            return 0;
        }

        items[i].ratio =
            (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity <= 0)
    {
        cout << "Invalid knapsack capacity." << endl;
        delete[] items;
        return 0;
    }

    double maxValue =
        fractionalKnapsack(items, n, capacity);

    cout << "\nMaximum value in knapsack = "
         << fixed << setprecision(2)
         << maxValue << endl;

    delete[] items;

    return 0;
}

