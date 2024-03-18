# Package Sorting System

The Package Sorting System is a comprehensive C program designed to manage and sort package information efficiently. Utilizing various sorting algorithms, this system offers flexibility in handling package priorities and ensures organized data management. This README provides an overview of the system, including its features, system requirements, installation guide, usage instructions, and contributions.

## Features

- **Multiple Sorting Algorithms**: Supports Quick Sort, Bubble Sort, and Heap Sort, allowing users to choose the most suitable algorithm based on their needs.
- **File-based Package Management**: Loads package data from files and saves sorted results, facilitating easy data manipulation and persistence.
- **Dynamic Memory Management**: Dynamically allocates memory for package data, ensuring efficient use of resources.
- **Performance Measurement**: Calculates and displays the time taken to sort packages, helping users gauge algorithm performance.

## System Requirements

- A C compiler (e.g., GCC, Clang) compatible with C89 or later.
- Standard C library.
- Access to terminal or command prompt.

## Installation Guide

1. **Clone the Repository**: Obtain the source code by cloning this repository or downloading the source code as a ZIP file and extracting it.

   ```bash
   git clone https://github.com/Koval1uk/PackageSortingSystem_Kovaliuk.git
   ```

2. **Compilation**: Navigate to the project directory and compile the source code using a C compiler. For GCC, the command would be:

   ```bash
   gcc -o PackageSortingSystem_Kovaliuk main.c
   ```

   This will generate an executable named `PackageSortingSystem_Kovaliuk`.

## Usage Instructions

1. **Prepare Input File**: Create a text file containing package information. Each line should contain a package's priority (an integer) and code (a string), separated by a space.

2. **Run the Program**: Execute the compiled program from the terminal or command prompt.

   ```bash
   ./PackageSortingSystem_Kovaliuk
   ```

3. **Follow On-screen Prompts**: The program will ask for the input file name, the number of packages to sort, and the choice of sorting algorithm. Enter the requested information accordingly.

4. **View Results**: After sorting, the program saves the sorted package data to a new file and displays the sorting duration. The output file name is the input file name appended with `.out`.

## Contributing

Contributions to the Package Sorting System are welcome! Here's how you can contribute:

- **Report Bugs**: Open an issue describing the bug and steps to reproduce it.
- **Suggest Enhancements**: Have ideas on how to improve the system? Submit an issue with your suggestions.
- **Submit Pull Requests**: Fork the repository, make your changes, and submit a pull request. Please provide a clear description of your changes and any relevant issue numbers.

## License

This project is licensed under [MIT License](LICENSE). Feel free to use, modify, and distribute the code as per the license conditions.

## Acknowledgments

- This project was created as an educational tool to demonstrate various sorting algorithms and file handling in C.
---

