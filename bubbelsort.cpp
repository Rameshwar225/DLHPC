#include <iostream>
#include <omp.h>

using namespace std;

void simpleBubble(int arr[], int n)
{
    double start_time = omp_get_wtime();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    double end_time = omp_get_wtime();

    cout << "Simple Bubble Sort Time: " << (end_time - start_time) * 1000 << " milliseconds" << endl;
}

void parallelBubble(int arr[], int n)
{
    double start_time = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    double end_time = omp_get_wtime();

    cout << "Parallel Bubble Sort Time: " << (end_time - start_time) * 1000 << " milliseconds" << endl;
}

int main()
{
    int arr[] = {8, 4, 5, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    simpleBubble(arr, n);
    parallelBubble(arr, n);

    return 0;
}
