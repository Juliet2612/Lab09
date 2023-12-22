#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void genArr(int arr[], int n);
void swap(int *tab, int i, int j);
void bubbleSort1(int tab[], int n);
void bubbleSort2(int tab[], int n);
void measureTime(int arr[], int n, void (*sortFunction)(int[], int), char *sortName);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    int sizes[] = {25000, 50000, 100000};

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));

        genArr(arr, n);
        measureTime(arr, n, bubbleSort1, "BubbleSort1");

        genArr(arr, n);
        measureTime(arr, n, bubbleSort2, "BubbleSort2");

        free(arr);
    }

    return 0;
}

void genArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
}

void measureTime(int arr[], int n, void (*sortFunction)(int[], int), char *sortName) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunction(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s - Rozmiar tablicy: %d, Czas sortowania: %f sekundy\n", sortName, n, cpu_time_used);
}

void swap(int *tab, int i, int j) {
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

void bubbleSort1(int tab[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (tab[j] > tab[j + 1])
                swap(tab, j, j + 1);
}

void bubbleSort2(int tab[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
}
