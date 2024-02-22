#include <iostream>

using namespace std;

bool isFibonacci(int num) 
{
    int a = 0, b = 1, c;

    while (a <= num) 
    {
        if (a == num) 
        {
            return true;
        }
        c = a + b;
        a = b;
        b = c;
    }

    return false;
}

int findMaximalIndexForFibonacci(const int a[], int n) 
{
    if (n == 0) 
    {
        cerr << "Error: Array is empty!" << endl;
        return -1;
    }

    int maximalIndex = -1;
    int prevFibonacci = -1;

    for (int i = 0; i < n; ++i) 
    {
        if (isFibonacci(a[i])) 
        {
            if (prevFibonacci != a[i]) 
            {
                // If the current element is a new Fibonacci number, update maximalIndex
                maximalIndex = i;
                prevFibonacci = a[i];
            }
        }
    }

    return maximalIndex;
}

void generateFibonacciSeries(int n) 
{
    int first = 0, second = 1;

    cout << "Fibonacci Series up to " << n << " numbers: ";

    for (int i = 0; i < n; ++i) 
    {
        cout << first << " ";

        int next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
}

int main() 
{
    // Get user input for the number of elements in the Fibonacci series
    cout << "Enter the number of elements for the Fibonacci series: ";
    int n;
    cin >> n;

    // Generate and display the Fibonacci series
    generateFibonacciSeries(n);

    // Get user input for a sorted array
    cout << "Enter the size of the sorted array: ";
    int arraySize;
    cin >> arraySize;

    int sortedArray[arraySize];
    cout << "Enter sorted elements for the array: ";
    for (int i = 0; i < arraySize; ++i) 
    {
        cin >> sortedArray[i];
    }

    // Find the maximal index for the Fibonacci series in the array
    int maximalIndex = findMaximalIndexForFibonacci(sortedArray, arraySize);

    if (maximalIndex != -1) 
    {
        cout << "Maximal Index k for Fibonacci numbers in the array: " << maximalIndex << endl;
    } else {
        cout << "No index found for Fibonacci numbers in the array." << endl;
    }

    return 0;
}

