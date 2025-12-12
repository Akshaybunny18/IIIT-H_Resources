#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j)
{
    arr[i] = arr[i] + arr[j] - (arr[j] = arr[i]);
}

int MedianofThree(int *arr, int low, int high)
{
    int middle = (low + high) / 2;

    if (arr[high] < arr[middle])
    {
        swap(arr, high, middle);
    }

    if (arr[low] > arr[middle])
    {
        swap(arr, low, middle);
    }

    return arr[middle];
}

int QPartition(int *arr, int low, int high, int pivotValue)
{
    int pivotIndex = (low + high) / 2;
    swap(arr, pivotIndex, high - 1);

    int left = low;
    int right = high - 1;

    while (left < right)
    {
        while (arr[++left] < pivotValue)
        {
        };
        while (arr[--right] > pivotValue)
        {
        };
        if (left < right)
        {
            swap(arr, left, right);
        }
    }
    swap(arr, left, high - 1);
    return left;
}

void QsortRec(int *arr, int low, int high)
{
    if (high <= low)
    {
        return;
    }

    int pivotValue = MedianofThree(arr, low, high);
    int pivotIndexFinal = QPartition(arr, low, high, pivotValue);

    QsortRec(arr, low, pivotIndexFinal - 1);
    QsortRec(arr, pivotIndexFinal + 1, high);
}

void QSort(int *arr, int len)
{
    QsortRec(arr, 0, len - 1);
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 2, 5, 100, 0};

    QSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void selectionSort(int array[], int size)
{
    int i, j, minIndex, temp;
    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap array[i] and array[minIndex]
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}
void permutationSort(int array[], int size)
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        j = i;
        while (j > 0 && array[j] < array[j - 1])
        {
            // Swap array[j] and array[j-1]
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
}
void bubbleSort(int array[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // Swap array[j] and array[j+1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void merge(int array[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    int Left[n1], Right[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        Left[i] = array[left + i];
    for (j = 0; j < n2; j++)
        Right[j] = array[middle + 1 + j];
    // Merge the temporary arrays back into array[left..right]
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            array[k] = Left[i];
            i++;
        }
        else
        {
            array[k] = Right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of Left[], if any
    while (i < n1)
    {
        array[k] = Left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of Right[], if any
    while (j < n2)
    {
        array[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Merge the sorted halves
        merge(array, left, middle, right);
    }
}

void shellSort(int array[], int size)
{
    int gap, i, j, temp;

    // Start with a large gap and reduce it
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size
        for (i = gap; i < size; i++)
        {
            // Add array[i] to the elements that have been gap sorted
            // Save array[i] in temp and make a hole at position i
            temp = array[i];
            // Shift earlier gap-sorted elements up until the correct location for array[i] is found
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            // Put temp (the original array[i]) in its correct location
            array[j] = temp;
        }
    }
}

void insertionSort(int array[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        /* Move elements of array[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
