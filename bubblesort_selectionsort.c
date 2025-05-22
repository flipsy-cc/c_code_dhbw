#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {              // Outer loop: goes through the entire array
        for (int j = 0; j < n - i - 1; j++) {      // Inner loop: compares adjacent elements
            if (arr[j] > arr[j + 1]) {             // Swap if the element is greater than the next
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {              // Move the boundary of the unsorted subarray
        int minIndex = i;                          // Assume the current element is the minimum
        for (int j = i + 1; j < n; j++) {          // Find the index of the smallest element
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first unsorted element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int data1[] = {64, 34, 25, 12, 22, 11, 90};
    int data2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data1) / sizeof(data1[0]);

    printf("Original array:\n");
    printArray(data1, n);

    // Bubble Sort
    bubbleSort(data1, n);
    printf("\nArray after Bubble Sort:\n");
    printArray(data1, n);

    // Selection Sort
    selectionSort(data2, n);
    printf("\nArray after Selection Sort:\n");
    printArray(data2, n);

    return 0;
}
