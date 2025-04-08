#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iomanip>

// all of your function definitions should be in this file now

template <typename T>
class Matrix {

private:
    int size;
    std::vector<std::vector<T>> matrix;

public:
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<T>> nums);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, T n);
    T get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    T sum_diagonal_major() const;
    T sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
};

// implementation of functions declared in matrix.hpp goes here


// Initialize an empty NxN matrix
template <typename T>
Matrix<T>::Matrix(size_t N)
{
    size = N;
    matrix.resize(N, std::vector<T>(size, 0));
}

// Load a matrix based on inputted matrix
template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> nums)
{
    size = nums.size();
    matrix = nums;
} 

// Returns sum of two matrices
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &rhs) const
{
    Matrix<T> sum(size);
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
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const
{
    Matrix<T> product(size);
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
template <typename T>
void Matrix<T>::set_value(std::size_t i, std::size_t j, T n)
{
    if (i >= size || j >= size || i < 0 || j < 0)
    {
        throw std::out_of_range("[Index is Out of Bounds]");
    }
    matrix[i][j] = n;
}

// Return a value in matrix
template <typename T>
T Matrix<T>::get_value(std::size_t i, std::size_t j) const
{
    if (i >= size || j >= size || i < 0 || j < 0)
    {
        throw std::out_of_range("[Index is Out of Bounds]");
    }
    return matrix[i][j];
}

// Return size
template <typename T>
int Matrix<T>::get_size() const
{
    return size;
}

// Return sum of top left -> bottom right diagonal
template <typename T>
T Matrix<T>::sum_diagonal_major() const
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][i];
    }
    return sum;
}

// Return sum of top right -> bottom left diagonal
template <typename T>
T Matrix<T>::sum_diagonal_minor() const
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][size - 1 - i];
    }
    return sum;
}

// Swap rows of matrix
template <typename T>
void Matrix<T>::swap_rows(std::size_t r1, std::size_t r2)
{
    if (r1 >= size || r2 >= size || r1 < 0 || r2 < 0)
    {
        throw std::out_of_range("[Index is Out of Bounds]");
    }
    std::swap(matrix[r1], matrix[r2]);
}

// Swap columns of matrix
template <typename T>
void Matrix<T>::swap_cols(std::size_t c1, std::size_t c2)
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
template <typename T>
void Matrix<T>::print_matrix() const 
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

#endif // __MATRIX_HPP__