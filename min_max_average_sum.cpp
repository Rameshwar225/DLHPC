#include <iostream>

using namespace std;

int min(int arr[], int size_of_arry)
{
    int min = arr[0];

    #pragma omp parallel for reduction(min: min)
    for (int i = 0; i < size_of_arry; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    return min;
}

int max(int arr[], int size)
{
    int max = arr[0];
    #pragma omp parallel for reduction(max: max)
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
}

int sum(int arr[], int size)
{
    int sum = arr[0];

    #pragma omp parallel for reduction(+: sum)

    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int avg(int arr[], int size)
{
    float avg = sum(arr, size) / size;
    return avg;
}

int main()
{
    int arr[] = {2, 4, 1, 5, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << "Minimum element is " << min(arr, arr_size);
    cout << "\nMaximum element is " << max(arr, arr_size);
    cout << "\nSum of elements is: " << sum(arr, arr_size);
    cout << "\nAverage of the elements is: " << avg(arr, arr_size);

    return 0;
}