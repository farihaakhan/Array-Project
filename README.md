# Array-Project

### Array Processing Program
This C++ program reads integer values from a text file and stores them in two-dimensional arrays in row-major and column-major forms using pointers. The program performs the following tasks:

- Reading the Input

- Storing Data.

- Displaying Arrays: The program traverses each array and displays its contents using a standard traversal method.

- Saving Arrays

### Code Documentation:
The program is thoroughly documented to demonstrate an understanding of how pointers are used to access array locations. It includes comments and explanations to clarify the code's functionality and logic. The code reads the input file as integers and stores them in a 2D array using Pointers. Each line from the text file is read as if the first two integers are the number of rows, the number of columns, and the rest are the integer values used for the Matrix.

![image](https://github.com/farihaakhan/Array-Project/assets/30266846/83d9e614-2c90-4b08-804d-fc1ff4f5726c)

The code prints the output in a separate output file with the original input as an Array form then Row Major and Column Major Arrays. 

![image](https://github.com/farihaakhan/Array-Project/assets/30266846/20144190-50eb-4040-9ce5-8738b2a04a34)


**Error Handling:** Because of one of the rules of Matrix, the total number of elements (integers) has to be the same as the product of the row number and column number. I implemented thorough error handling in my code to handle potential exceptions and ensure smooth execution. For instance, I included validation checks to verify the input when processing the input file. If any input doesn't meet the required criteria, appropriate error messages are displayed.

  ``4 4 1 2 3 4 5 6 7 8
  
![image](https://github.com/farihaakhan/Array-Project/assets/30266846/b4746a5c-8de9-43ff-bec2-87ce43c5c550)

