#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    
    // Get the file and the matrix type first

    std::string fileName;
    std::cout << "Input File Name: ";
    std::cin >> fileName;
    std::ifstream file(fileName);

    int N;
    file >> N;

    int matrixType;
    file >> matrixType;

    // if matrix type is integer
    if (matrixType == 0)
    {

        // 1. Read values from a file into the matrix:
        Matrix<int> A(N);
        Matrix<int> B(N);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int a;
                file >> a;
                A.set_value(i, j, a);
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int b;
                file >> b;
                B.set_value(i, j, b);
            }
        }

        file.close();

        std::cout << "Matrix A:" << std::endl;
        A.print_matrix();

        std::cout << "Matrix B:" << std::endl;
        B.print_matrix();

        // 2. Add two matrices and display the result:

        std::cout << "Matrix A + Matrix B:" << std::endl;
        Matrix<int>SUM = A + B;
        SUM.print_matrix();

        // 3. Multiply two matrices and display the result:
        std::cout << "Matrix A * Matrix B:" << std::endl;
        Matrix<int>PRODUCT = A * B;
        PRODUCT.print_matrix();

        // 4. Get the sum of matrix diagonal elements:
        std::cout << "Sum of Major Diagonal Elements in Matrix A:" << std::endl;
        std::cout << A.sum_diagonal_major() << std::endl << std::endl;

        std::cout << "Sum of Minor Diagonal Elements in Matrix A:" << std::endl;
        std::cout << A.sum_diagonal_minor() << std::endl << std::endl;

        // 5. Swap matrix rows and display the result:
        Matrix<int>A_swapRow(A);

        int row1, row2;
        std::cout << "Input Two Rows to Swap:\nRow 1: ";
        std::cin >> row1;
        std::cout << "Row 2: ";
        std::cin >> row2;

        A_swapRow.swap_rows(row1, row2);
        std::cout << "\nMatrix A with Rows " << row1 << " and " << row2 << " Swapped:" << std::endl;
        A_swapRow.print_matrix();

        // 6. Swap matrix columns and display the result:
        Matrix<int> A_swapCol(A);

        int col1, col2;
        std::cout << "Input Two Columns to Swap:\nColumn 1: ";
        std::cin >> col1;
        std::cout << "Column 2: ";
        std::cin >> col2;

        A_swapCol.swap_cols(col1, col2);
        std::cout << "\nMatrix A with Columns " << col1 << " and " << col2 << " Swapped:" << std::endl;
        A_swapCol.print_matrix();

        // 7. Update matrix rows and display the result:
        char matrix;
        int row_x, col_x, new_val;
        std::cout << "Input Matrix, Row Index, Column Index, and New Value:\nMatrix: ";
        std::cin >> matrix;
        std::cout << "Row Index: ";
        std::cin >> row_x;
        std::cout << "Column Index: ";
        std::cin >> col_x;
        std::cout << "New Value: ";
        std::cin >> new_val;
        if (matrix == 'A' || matrix == 'a')
        {
            A.set_value(row_x, col_x, new_val);
            std::cout << "\nUpdated Matrix A:" << std::endl;
            A.print_matrix();
        }
        else if (matrix == 'B' || matrix == 'b')
        {
            B.set_value(row_x, col_x, new_val);
            std::cout << "\nUpdated Matrix B:" << std::endl;
            B.print_matrix();
        }
        else
        {
            std::cout << "[ERROR: Invalid Matrix]";
        }
    }

    // if matrix type is double
    if (matrixType == 1)
    {
        // 1. Read values from a file into the matrix:

        Matrix<double> A(N);
        Matrix<double> B(N);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                double a;
                file >> a;
                A.set_value(i, j, a);
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                double b;
                file >> b;
                B.set_value(i, j, b);
            }
        }

        file.close();

        std::cout << "Matrix A:" << std::endl;
        A.print_matrix();

        std::cout << "Matrix B:" << std::endl;
        B.print_matrix();

        // 2. Add two matrices and display the result:

        std::cout << "Matrix A + Matrix B:" << std::endl;
        Matrix<double>SUM = A + B;
        SUM.print_matrix();

        // 3. Multiply two matrices and display the result:
        std::cout << "Matrix A * Matrix B:" << std::endl;
        Matrix<double>PRODUCT = A * B;
        PRODUCT.print_matrix();

        // 4. Get the sum of matrix diagonal elements:
        std::cout << "Sum of Major Diagonal Elements in Matrix A:" << std::endl;
        std::cout << A.sum_diagonal_major() << std::endl << std::endl;

        std::cout << "Sum of Minor Diagonal Elements in Matrix A:" << std::endl;
        std::cout << A.sum_diagonal_minor() << std::endl << std::endl;

        // 5. Swap matrix rows and display the result:
        Matrix<double>A_swapRow(A);

        int row1, row2;
        std::cout << "Input Two Rows to Swap:\nRow 1: ";
        std::cin >> row1;
        std::cout << "Row 2: ";
        std::cin >> row2;

        A_swapRow.swap_rows(row1, row2);
        std::cout << "\nMatrix A with Rows " << row1 << " and " << row2 << " Swapped:" << std::endl;
        A_swapRow.print_matrix();

        // 6. Swap matrix columns and display the result:
        Matrix<double> A_swapCol(A);

        int col1, col2;
        std::cout << "Input Two Columns to Swap:\nColumn 1: ";
        std::cin >> col1;
        std::cout << "Column 2: ";
        std::cin >> col2;

        A_swapCol.swap_cols(col1, col2);
        std::cout << "\nMatrix A with Columns " << col1 << " and " << col2 << " Swapped:" << std::endl;
        A_swapCol.print_matrix();

        // 7. Update matrix rows and display the result:
        char matrix;
        int row_x, col_x, new_val;
        std::cout << "Input Matrix, Row Index, Column Index, and New Value:\nMatrix: ";
        std::cin >> matrix;
        std::cout << "Row Index: ";
        std::cin >> row_x;
        std::cout << "Column Index: ";
        std::cin >> col_x;
        std::cout << "New Value: ";
        std::cin >> new_val;
        if (matrix == 'A' || matrix == 'a')
        {
            A.set_value(row_x, col_x, new_val);
            std::cout << "\nUpdated Matrix A:" << std::endl;
            A.print_matrix();
        }
        else if (matrix == 'B' || matrix == 'b')
        {
            B.set_value(row_x, col_x, new_val);
            std::cout << "\nUpdated Matrix B:" << std::endl;
            B.print_matrix();
        }
        else
        {
            std::cout << "[ERROR: Invalid Matrix]";
        }
    }

    return 0;
}
