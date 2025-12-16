#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initializeArray(int *arr, int size_arr, int min, int max)
{
    for (int i = 0; i < size_arr; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}
int findMaxProduct(int *arr, int size_arr, int *assignment, int *steps)
{
    int max;
    max = arr[0] * arr[1];
    (*assignment) = 0;
    (*steps) = 0;
    for (int i = 0; i < size_arr - 1; i++)
    {
        for (int j = i + 1; j < size_arr; j++)
        {
            (*steps)++;
            int product = arr[i] * arr[j];
            if (product > max)
            {
                max = product;
                (*assignment)++;
            }
        }
    }
    return max;
}
float steps_avg(int fre_comps[], int size_fre_comps, int k)
{
    float avg = 0;
    for (int i = 0; i < size_fre_comps; i++)
    {
        avg += fre_comps[i] * i;
    }
    avg = avg * 1.0 / k;
    return avg;
}
float assignment_avg(int fre_comps[], int size_fre_comps, int k)
{
    float avg = 0;
    for (int i = 0; i < size_fre_comps; i++)
    {
        avg += fre_comps[i] * i;
    }
    avg = avg * 1.0 / k;
    return avg;
}
int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int arr[4];
    int k = 10000;
    int assignment = 0;
    int steps = 0;
    int fre_assignments[11] = {0};
    int fre_steps[11] = {0};
    for (int i = 0; i < k; i++)
    {
        initializeArray(arr, 4, 1, 100);
        findMaxProduct(arr, 4, &assignment, &steps);
        fre_assignments[assignment]++;
        fre_steps[steps]++;
    }
    printf("\nObservation   assignments     Steps\n");
    for (int h = 0; h <= 10; h++)
    {
        printf("%d: %15d  %15d\n", h, fre_assignments[h], fre_steps[h]);
    }
    printf("average steps:%.2f\n", steps_avg(fre_steps, 11, k));
    printf("average assignments:%.2f\n", assignment_avg(fre_assignments, 11, k));
    printf("so steps theo n la: (n(n-1))/2\n");
    printf("so step theo big o la: O(n^2)\n");
}
