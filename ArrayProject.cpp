/* Fariha Khan
CS 316 Section 12
Project 2: Array Project
Collaborator: Andrew Hu
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Max number of Rows and Columns
const int MAX_ROWS = 100;
const int MAX_COLS = 100;

/*Read values from the input file and store them in 2D array
RowMaj = pointer to the row major
ColMaj = pointer to the column major
numberOfColumns, numberOfRows = number of rows and columns
*/
void readArrays(ifstream &inputFile, int *RowMaj, int *ColMaj, int numberOfRows,int numberOfColumns) {
  int totalNumbers = numberOfRows * numberOfColumns; // product
  int count = 0;                                     // values read from file

  // iterates over the col and rows of array
  for (int j = 0; j < numberOfColumns; j++) {
    for (int i = 0; i < numberOfRows; i++) {
      int val; // reads values into
      if (inputFile >> val) {
        // gets the offset from the pointer then dereferences
        *(RowMaj + i * numberOfColumns + j) = val; // acesses memory location of the element in the row major array.
        *(ColMaj + j * numberOfRows + i) = val; // accesses the memory location of the element in the column major array
        count++;
      }
    }
  }
  if (count < totalNumbers) {
    throw runtime_error("Insufficient values in the input file.");
  }
}
/* write the array in the output file
arr = pointer to the array
arrayname = string that represent the name of the array
*/
void saveArray(ofstream &outputFile, int *arr, int numberOfRows, int numberOfColumns, string arrayName) {
    outputFile << arrayName << ":" << endl;   //writes the name of array
  // iterates over the rows and columns of the array
  for (int i = 0; i < numberOfRows; i++) {
    for (int j = 0; j < numberOfColumns; j++) {
      outputFile << setw(4) << *(arr + i * numberOfColumns + j) << " "; // dereferncing gets the value of the element at position i,j in the array arr
    }
    outputFile << endl;
  }
  outputFile << endl;
}

int main() {
  ifstream inputFile("input.txt");
  ofstream outputFile("ArrayOutput.txt");
  int RowMaj[MAX_ROWS][MAX_COLS];   //2D arrray with max dimensions
  int ColMaj[MAX_ROWS][MAX_COLS];

  while (inputFile.good()) {    // read the input file untill the end
    int numberOfRows, numberOfColumns;
    inputFile >> numberOfRows >> numberOfColumns;

    try {   //exception thrown if insufficient number of values in the input file
      readArrays(inputFile, (int *)RowMaj, (int *)ColMaj, numberOfRows, numberOfColumns);    //calls the readArray function to read the arrays using pointer casting (int*)
      saveArray(outputFile, (int *)ColMaj, numberOfRows, numberOfColumns, "Original Array");  //saves the array in the output file
      saveArray(outputFile, (int *)ColMaj, numberOfRows, numberOfColumns, "Row Major Order");
      saveArray(outputFile, (int *)RowMaj, numberOfRows, numberOfColumns,"Column Major Order");
    } 
    catch (const exception &e) {
      outputFile << "Error: " << e.what() << endl;  //shows error message if exception occurs
      continue; // Skip to the next iteration
    }
  }

  //close files
  inputFile.close();
  outputFile.close();
    cout << "Arrays saved to ArrayOutput.txt" << endl;
    
    return 0;
}
