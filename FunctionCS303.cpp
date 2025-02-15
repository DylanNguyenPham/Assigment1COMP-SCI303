#include "Function.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Function to read data from file into array
void readDataFromFile(ifstream& inputFile, int arr[], int& size) {
    if (!inputFile) {
        throw runtime_error("Error: Could not open input file.");
    }

    size = 0;
    while (inputFile >> arr[size] && size < MAX_SIZE) {
        size++;
    }
}

// Function to write data to a file
void writeDataToFile(ofstream& outputFile, const int arr[], int size) {
    if (!outputFile) {
        throw runtime_error("Error: Could not open output file.");
    }

    for (int i = 0; i < size; i++) {
        outputFile << arr[i] << " ";
    }
    outputFile << endl;
    cout << "Data successfully saved.\n";
}

// Function to check if a number exists in the array
int findNumber(const int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

// Function to modify a value at a given index
void modifyValue(int arr[], int size, int index, int newValue, int& oldValue) {
    if (index < 0 || index >= size) {
        throw out_of_range("Error: Index out of range.");
    }
    oldValue = arr[index];
    arr[index] = newValue;
    cout << "Value at index " << index << " modified from " << oldValue << " to " << newValue << endl;
}

// Function to add a new integer to the end of the array
void addNumber(int arr[], int& size, int num) {
    if (size >= MAX_SIZE) {
        throw overflow_error("Error: Array is full, cannot add more elements.");
    }
    arr[size++] = num;
    cout << "Number " << num << " added to the array.\n";
}

// Function to remove an integer at a given index
void removeNumber(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Error: Invalid index.");
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Number at index " << index << " removed successfully.\n";
}

// Function to display the array
void displayArray(const int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

