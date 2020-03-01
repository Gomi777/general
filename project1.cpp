#include <iostream>
#include <string>
#include "project1.h"
using namespace std;

int output(int *matf, int rows1, int cols1)
{
    //function to output the properly displayed matrix

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
            cout << *(matf + i * cols1 + j) << " ";

        cout << endl;
    }
}

void addition(int *mat1, int *mat2, int *matf, int &rows1, int &cols1)
{
    //function for addition

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            *(matf + i * cols1 + j) = *(mat1 + i * cols1 + j) + *(mat2 + i * cols1 + j);
        }
    }
    cout << "Output:" << endl;
    output(matf, rows1, cols1);
}

void subtraction(int *mat1, int *mat2, int *matf, int &rows1, int &cols1)
{

    //function for subtraction
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            *(matf + i * cols1 + j) = *(mat1 + i * cols1 + j) - *(mat2 + i * cols1 + j);
        }
    }
    cout << "Output:" << endl;
    output(matf, rows1, cols1);
}

void multiplication(int *mat1, int *mat2, int *matf, int &rows1, int &cols1, int &rows2, int &cols2)
{
    //function for multiplication
    int v1, v2;

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            for (int k = 0; k < cols1; k++)
            {
                v1 = *(mat1 + i * cols1 + k);
                v2 = *(mat2 + k * cols2 + j);
                *(matf + i * cols2 + j) = (v1 * v2);
            }
        }
    }
    cout << "Output:" << endl;
    output(matf, rows1, cols2);
}

void input(int &choice, int &rows1, int &cols1, int &rows2, int &cols2, int &k, int *mat1, int *mat2, int *matf)
{

    //input function

    cout << "Menu"
         << "\n 1. Addition"
         << "\n 2. Subtraction"
         << "\n 3. Multiplication"
         << "\n 0. Exit"
         << "\n Enter the number of your choice" << endl;
    cin >> choice;

    if (choice == 0)
    { // this will kill the main fuction if "Exit" is chosen, or reapeat if an invalid nuber is chosen
        return;
    }
    else if (choice > 3)
    {
        cout << "invalid input" << endl;
        input(choice, rows1, cols1, rows2, cols2, k, mat1, mat2, matf);
    }
    else
    {
    }
    //this part of the code will prompt the user for the rows and columns for each matrix
    cout << "Number of rows for the first Matrix? (max 10)" << endl;
    cin >> rows1;

    cout << "Number of columns for the first Matrix? (max 10)" << endl;
    cin >> cols1;

    cout << "Number of rows for the second Matrix? (max 10)" << endl;
    cin >> rows2;

    cout << "Number of columns for the second Matrix? (max 10)" << endl;
    cin >> cols2;

    //this if/else statement checks that the matrices are the right size to be operated
    if ((choice == 1 || choice == 2) && ((cols1 != cols2) || (rows1 != rows2)))
    {
        cout << " error: for addition and subraction the two matrices must have the same amount of elements";
        choice = 0;
        return;
    }
    else if ((choice == 3) && (rows2 != cols1))
    {
        cout << " error: for mulipication the columns of the first must equal the rows of the second";
        choice = 0;
        return;
    }
    else
    {
    }

    // this for loop allows the user to imput each element for the first matrix
    cout << "input the elements of the first matrix: " << endl;

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cout << "Enter element "
                 << "(" << i << "," << j << "): ";
            cin >> k;
            *(mat1 + i * cols1 + j) = k;
        }
    }

    output(mat1, rows1, cols1); //this call to output will allow the user to see what they have inputed

    // this for loop allows the user to imput each element for the second matrix
    cout << "input the elements of the second matrix: " << endl;
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cout << "Enter element "
                 << "(" << i << "," << j << "): ";
            cin >> k;
            *(mat2 + i * cols2 + j) = k;
        }
    }

    output(mat2, rows2, cols2); //this call to output will allow the user to see what they have inputed
}