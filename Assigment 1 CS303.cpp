// Assigment 1 CS303.cpp : This file contains the 'main' function. Program execution begins and ends there.
// used old past C++ labs to help reused functions. 
#include "Function.h"
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Find a number in the array\n";
    cout << "2. Modify a value in the array\n";
    cout << "3. Add a new number to the array\n";
    cout << "4. Remove a number from the array\n";
    cout << "5. Display the array\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int arr[MAX_SIZE]; // Array 
    int size = 0;      // Tracks the number of elements

    // Open input file
    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1; // Exit if file cannot be opened
    }

    // Read data from file
    try {
        readDataFromFile(inFile, arr, size);
        cout << "Data loaded successfully.\n";
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    inFile.close(); 

    int choice;
    do {
        displayMenu();
        cin >> choice;

        try {
            switch (choice) {
            case 1: { // Find a number
                int numToFind;
                cout << "Enter a number to find: ";
                cin >> numToFind;
                int index = findNumber(arr, size, numToFind);
                if (index != -1)
                    cout << "Number " << numToFind << " found at index " << index << endl;
                else
                    cout << "Number " << numToFind << " not found in the array.\n";
                break;
            }
            case 2: { // Modify a value
                int modifyIndex, newValue, oldValue;
                cout << "Enter index to modify: ";
                cin >> modifyIndex;
                cout << "Enter new value: ";
                cin >> newValue;
                modifyValue(arr, size, modifyIndex, newValue, oldValue);
                break;
            }
            case 3: { // Add a new number
                int numToAdd;
                cout << "Enter a number to add: ";
                cin >> numToAdd;
                addNumber(arr, size, numToAdd);
                break;
            }
            case 4: { // Remove a number
                int removeIndex;
                cout << "Enter index to remove: ";
                cin >> removeIndex;
                removeNumber(arr, size, removeIndex);
                break;
            }
            case 5: // Display the array
                displayArray(arr, size);
                break;
            case 6: // Exit
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (choice != 6);

    // Save data back to the file before exiting
    ofstream outFile("output.txt");
    if (!outFile) {
        cerr << "Error: Unable to open output file!" << endl;
        return 1;
    }

    writeDataToFile(outFile, arr, size);
    outFile.close();
    cout << "Data saved successfully to output.txt.\n";

    return 0;
}
