This C program is designed to manage and sort packages based on their priorities using different sorting algorithms. Here's how each part of the program works:

### Structure Definition
- `Package`: A structure representing a package, containing an integer `priority` to determine the order in which packages are sorted, and a `code` string that uniquely identifies each package.

### Sorting Algorithms
The program implements three sorting algorithms to organize arrays of `Package` structures by their priority:

1. **Quick Sort** (`quickSort` and `partition` functions):
    - This algorithm selects a 'pivot' element and partitions the array into two sub-arrays: one with elements less than the pivot and the other with elements greater than the pivot. It recursively sorts the sub-arrays.
    - The `partition` function supports this by determining the pivot position and rearranging elements based on their comparison with the pivot.

2. **Bubble Sort** (`bubbleSort` function):
    - A simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process repeats until the list is sorted.

3. **Heap Sort** (`heapSort` and `heapify` functions):
    - This algorithm converts the array into a heap structure, then repeatedly removes the largest element from the heap and places it at the end of the array. It re-heaps the remaining elements to ensure the largest element is moved to its correct position in the sorted portion of the array.

### File Operations
- **Loading Packages** (`loadPackages` function): Reads package data from a file. It expects each line in the file to contain a package's priority and code. The function dynamically allocates memory for an array of `Package` structures and populates it with the file's data.
- **Saving Packages** (`savePackages` function): Writes the sorted package data back to a file. Each line in the output file contains a package's priority and code.

### Utility Functions
- **getSortName**: Returns a string representation of the sorting algorithm based on the user's choice.
- **main**: Orchestrates the program's workflow, including user input, algorithm selection, timing the sorting process, and outputting the results.

### Workflow
1. **Initialization**: The program prompts the user for input, including the filename to load packages from, the number of packages to sort, and the choice of sorting algorithm.
2. **Loading Data**: Reads package data from the specified file and loads it into an array of `Package` structures.
3. **Sorting**: Based on the user's choice, the program selects one of the three sorting algorithms and sorts the array of packages by priority.
4. **Timing**: The program measures the time taken to sort the packages using the chosen algorithm.
5. **Output**: After sorting, the program saves the sorted packages to a new file and displays the sorting time on the console.
6. **Cleanup**: Finally, the program frees any dynamically allocated memory before exiting.

This design allows for flexible package management and sorting, showcasing different sorting techniques' effectiveness and efficiency.