#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int array[],int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}
 
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
 
int main()
{
    int array[] = { 10,15,6,8,65};
    int N = sizeof(array) / sizeof(array[0]);
    bubble_sort(array, N);
    cout << "Sorted array: \n";
    printArray(array, N);
    return 0;
}