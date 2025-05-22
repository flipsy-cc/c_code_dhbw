// heap.c - einfache Max-Heap Implementierung in C

#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

// Hilfsfunktionen
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }
int parent(int i) { return (i - 1) / 2; }

// Einfügen in den Heap
void insert(int value) {
    if (size >= MAX_SIZE) {
        printf("Heap ist voll!\n");
        return;
    }
    heap[size] = value;
    int index = size;
    size++;

    // Versickern nach oben
    while (index > 0 && heap[parent(index)] < heap[index]) {
        int temp = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = temp;
        index = parent(index);
    }
}

// Entfernen des Maximums (Wurzel)
int extractMax() {
    if (size == 0) {
        printf("Heap ist leer!\n");
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;

    // Versickern nach unten
    int index = 0;
    while (1) {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest == index) break;

        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        index = largest;
    }
    return max;
}

// Löschen eines Knotens an beliebigem Index
void deleteAtIndex(int index) {
    if (index >= size) {
        printf("Index außerhalb des Bereichs!\n");
        return;
    }
    heap[index] = heap[size - 1];
    size--;

    // Versickern nach unten
    while (1) {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest == index) break;

        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        index = largest;
    }
}

// Hilfsfunktion: Ausgabe des Heaps
void printHeap() {
    printf("Heap-Inhalt: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Hauptprogramm zur Demonstration
int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(30);
    insert(15);

    printHeap();

    printf("Max: %d\n", extractMax());
    printHeap();

    deleteAtIndex(1);
    printHeap();

    return 0;
}
