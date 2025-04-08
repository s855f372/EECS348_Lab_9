#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iomanip>

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// Initialize an empty NxN matrix
Matrix::Matrix(size_t N)
{
    size = N;
    matrix.resize(N, std::vector<int>(size, 0));
}

// Load a matrix based on inputted matrix
Matrix::Matrix(std::vector<std::vector<int>> nums)
{
    size = nums.size();
    matrix = nums;
} 

// Returns sum of two matrices
Matrix Matrix::operator+(const Matrix &rhs) const
{
    Matrix sum = Matrix(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }
    return sum;
}

// Returns product of two matrices
Matrix Matrix::operator*(const Matrix &rhs) const
{
    Matrix product = Matrix(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           for (int k = 0; k < size; k++)
           {
                product.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
           }
        }
    }
    return product;
}

// Set a value in matrix
void Matrix::set_value(std::size_t i, std::size_t j, int n)
{
    if (i >= size || j >= size || i < 0 || j < 0)
    {
        throw std::out_of_range("[Index is Out of Bounds]");
    }
    matrix[i][j] = n;
}

// Return a value in matrix
int Matrix::get_value(std::size_t i, std::size_t j) const
{
    if (i >= size || j >= size  || i < 0 || j < 0)
    {
        throw std::out_of_range("[Index is Out of Bounds]");
    }
    return matrix[i][j];
}

// Return size
int Matrix::get_size() const
{
    return size;
}

// Return sum of top left -> bottom right diagonal
int Matrix::sum_diagonal_major() const
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][i];
    }
    return sum;
}

// Return sum of top right -> bottom left diagonal
int Matrix::sum_diagonal_minor() const
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][size - 1 - i];
    }
    return sum;
}

// Swap rows of matrix
void Matrix::swap_rows(std::size_t r1, std::size_t r2)
{
    if (r1 >= size || r2 >= size || r1 < 0 || r2 < 0)
    {
        throw std::out_of_range("[Index is Out of Bounds]");
    }
    std::swap(matrix[r1], matrix[r2]);
}

// Swap columns of matrix
void Matrix::swap_cols(std::size_t c1, std::size_t c2)
{
    if (c1 >= size || c2 >= size || c1 < 0 || c2 < 0)
    {
        throw std::out_of_range("[Index is Out of Bounds]");
    }
    for (int i = 0; i < size; i++)
    {
        std::swap(matrix[i][c1], matrix[i][c2]);
    }
}

// Print out matrix
void Matrix::print_matrix() const 
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}