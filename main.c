#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure for package details.
typedef struct {
    int priority; // The priority level of the package.
    char code[7]; // The code identifying the package.
} Package;


/**
 * Partitions the array of packages for quicksort.
 *
 * @param packages An array of Package structures.
 * @param low The starting index of the array to partition.
 * @param high The ending index of the array to partition.
 * @return The partition index.
 */
int partition(Package* packages, int low, int high) {
    int pivot = packages[high].priority;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (packages[j].priority < pivot) {
            i++;
            Package temp = packages[i];
            packages[i] = packages[j];
            packages[j] = temp;
        }
    }

    Package temp = packages[i + 1];
    packages[i + 1] = packages[high];
    packages[high] = temp;
    return (i + 1);
}

/**
 * Performs a quick sort on the array of packages.
 *
 * @param packages An array of Package structures to be sorted.
 * @param low The starting index of the segment of the array to be sorted.
 * @param high The ending index of the segment of the array to be sorted.
 */
void quickSort(Package* packages, int low, int high) {
    if (low < high) {
        int pi = partition(packages, low, high);

        quickSort(packages, low, pi - 1);
        quickSort(packages, pi + 1, high);
    }
}

/**
 * Loads packages from a file into an array.
 *
 * @param filename The name of the file to read from.
 * @param packages A pointer to the array of Package structures.
 * @param count A pointer to an integer tracking the number of packages loaded.
 * @param maxCount The maximum number of packages to load.
 */
void loadPackages(const char* filename, Package** packages, int* count, int maxCount) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *packages = malloc(sizeof(Package) * maxCount);

    while ((*count < maxCount) && (fscanf(file, "%d %6s", &((*packages)[*count].priority), (*packages)[*count].code) == 2)) {
        (*count)++;
    }

    fclose(file);
}

/**
 * Saves packages to a file from an array.
 *
 * @param filename The name of the file to write to.
 * @param packages An array of Package structures to be saved.
 * @param count The number of packages to save.
 */
void savePackages(const char* filename, Package* packages, int count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s\n", packages[i].priority, packages[i].code);
    }

    fclose(file);
}

/**
 * Performs a bubble sort on the array of packages.
 *
 * @param packages An array of Package structures to be sorted.
 * @param count The number of packages in the array.
 */
void bubbleSort(Package* packages, int count) {
    int i, j;
    for (i = 0; i < count-1; i++)
        for (j = 0; j < count-i-1; j++)
            if (packages[j].priority > packages[j+1].priority) {
                Package temp = packages[j];
                packages[j] = packages[j+1];
                packages[j+1] = temp;
            }
}

/**
 * Heapifies a subtree rooted with node i.
 *
 * @param packages An array of Package structures.
 * @param count The size of the heap.
 * @param i The index of the root node of the subtree.
 */
void heapify(Package* packages, int count, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < count && packages[left].priority > packages[largest].priority)
        largest = left;

    if (right < count && packages[right].priority > packages[largest].priority)
        largest = right;

    if (largest != i) {
        Package temp = packages[i];
        packages[i] = packages[largest];
        packages[largest] = temp;

        heapify(packages, count, largest);
    }
}

/**
 * Performs a heap sort on the array of packages.
 *
 * @param packages An array of Package structures to be sorted.
 * @param count The number of packages in the array.
 */
void heapSort(Package* packages, int count) {
    for (int i = count / 2 - 1; i >= 0; i--)
        heapify(packages, count, i);

    for (int i=count-1; i>=0; i--) {
        Package temp = packages[0];
        packages[0] = packages[i];
        packages[i] = temp;

        heapify(packages, i, 0);
    }
}

/**
 * Performs an insertion sort on the array of packages.
 *
 * @param packages An array of Package structures to be sorted.
 * @param count The number of packages in the array.
 */
void insertionSort(Package *packages, int count) {
  int temp;
    for (int i = 1; i < count; i++) {
        temp = packages[i].priority;
        int j = i-1;
        while (j >= 0 && packages[j].priority > temp) {
            packages[j+1].priority = packages[j].priority;
            j--;
        }
        packages[j + 1].priority = temp;
    }
}

/**
 * Returns the name of the sorting algorithm based on the given choice.
 *
 * @param choice The choice of sorting algorithm.
 * @return A string representing the name of the sorting algorithm.
 */
const char* getSortName(int choice) {
    switch(choice) {
        case 1: return "Quick Sort";
        case 2: return "Bubble Sort";
        case 3: return "Heap Sort";
        case 4: return "Insertion sort";
        default: return "Quick Sort";
    }
}


/**
 * The main function. Handles user input, sorts packages, and displays execution time.
 *
 * @return Exit status.
 */
int main() {
    char filename[256];
    int choice;
    int maxValues;

    printf("Enter the filename: ");
    scanf("%255s", filename);

    printf("How many values would you like to sort? (min = 0, max = 100000) : ");
    scanf("%d", &maxValues);

    printf("Choose a sorting algorithm: 1 for Quick Sort, 2 for Bubble Sort, 3 for Heap Sort, 4 for Insertion Sort: ");
    scanf("%d", &choice);

    Package* packages = NULL;
    int count = 0;

    loadPackages(filename, &packages, &count, maxValues);

    clock_t start, end;
    double time_used;

    start = clock();
    switch(choice) {
        case 1:
            quickSort(packages, 0, count - 1);
            break;
        case 2:
            bubbleSort(packages, count);
            break;
        case 3:
            heapSort(packages, count);
            break;
        case 4:
            insertionSort(packages,  count);
            break;
        default:
            printf("Invalid choice. Using Quick Sort.\n");
            quickSort(packages, 0, count - 1);
    }
    end = clock();

    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorting of %d values using %s algorithm took %f seconds to execute.\n", count, getSortName(choice), time_used);

    strcat(filename, ".out");
    savePackages(filename, packages, count);

    free(packages);

    return 0;
}

// Name of file:
// C:\Users\PC\CLionProjects\AZA_Assignment_Kovaliuk\zoznam.txt



