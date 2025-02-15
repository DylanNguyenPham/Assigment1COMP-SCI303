#pragma once
#include <string>
#include <fstream>

const int MAX_SIZE = 100; 

void readDataFromFile(std::ifstream& inputFile, int arr[], int& size);
void writeDataToFile(std::ofstream& outputFile, const int arr[], int size);
int findNumber(const int arr[], int size, int num);
void modifyValue(int arr[], int size, int index, int newValue, int& oldValue);
void addNumber(int arr[], int& size, int num);
void removeNumber(int arr[], int& size, int index);
void displayArray(const int arr[], int size);
