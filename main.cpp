#include <iostream>
#include <string>
#include "project1.h"
using namespace std;

int main()
{

    int choice, rows1, cols1, rows2, cols2, k;
    char choice2;
    int *mat1 = new int[10 * 10];
    int *mat2 = new int[10 * 10];
    int *matf = new int[10 * 10];

    input(choice, rows1, cols1, rows2, cols2, k, mat1, mat2, matf);
    cout << rows1;
    switch (choice)
    { //this switch block will call the correct fucntion with respect to the user's choice

    case 1:
        addition(mat1, mat2, matf, rows1, cols1);

        break;

    case 2:
        subtraction(mat1, mat2, matf, rows1, cols1);

        break;

    case 3:
        multiplication(mat1, mat2, matf, rows1, cols1, rows2, cols2);

        break;

    case 0:
        return 0;
    default:
        cout << "invalid input";
    }
    //the end of the main fucntion will repeat if the user would like

    cout << "\n Would you like to do another operation y/n?" << endl;
    cin >> choice2;

    if (choice2 == 'y')
    {
        main();
    }
    else
    {
        return 0;
    }
}