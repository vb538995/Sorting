//insertion sort
//In c language
#include <stdio.h>
#include <stdlib.h>
void insertionSort(int arr[], int n, int *comparisonCount) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*comparisonCount)++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    FILE *inputFile, *outputFile;
    int choice;
    int data[500];
    int dataSize, comparisonCount = 0;
    while (1) {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputFile = fopen("inAsce.txt", "r");
                outputFile = fopen("outInsAsce.txt", "w");
                break;
            case 2:
                inputFile = fopen("inDesc.txt", "r");
                outputFile = fopen("outInsDesc.txt", "w");
                break;
            case 3:
                inputFile = fopen("inRand.txt", "r");
                outputFile = fopen("outInsRand.txt", "w");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                continue;
        }
        if (inputFile == NULL || outputFile == NULL) {
            printf("Error opening files.\n");
            exit(1);
        }
        dataSize = 0;
        while (fscanf(inputFile, "%d", &data[dataSize]) != EOF) {
            dataSize++;
        }
        comparisonCount = 0;
        insertionSort(data, dataSize, &comparisonCount);
        for (int i = 0; i < dataSize; i++) {
            fprintf(outputFile, "%d ", data[i]);
        }
        printf("Sorted Data: ");
        printArray(data, dataSize);
        printf("Number of Comparisons: %d\n", comparisonCount);
        fclose(inputFile);
        fclose(outputFile);
    }
    return 0;
}
