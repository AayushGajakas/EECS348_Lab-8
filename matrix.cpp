#include "matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>

using std::vector;
using std::cout;
using std::endl;
using std::out_of_range;

Matrix Matrix::load_from_file(std::ifstream &file, std::size_t N) {
    std::vector<std::vector<int>> data(N, std::vector<int>(N, 0));
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            file >> data[i][j];
    return Matrix(data);
}


// Constructor for NxN zero matrix
Matrix::Matrix(std::size_t N) {
    matrix = vector<vector<int>>(N, vector<int>(N, 0));
}

// Constructor from given data
Matrix::Matrix(vector<vector<int>> nums) {
    matrix = nums;
}

// Get size of the matrix
int Matrix::get_size() const {
    return matrix.size();
}

// Get value at position (i, j)
int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i >= get_size() || j >= get_size()) {
        throw out_of_range("Index out of range");
    }
    return matrix[i][j];
}

// Set value at position (i, j)
void Matrix::set_value(std::size_t i, std::size_t j, int value) {
    if (i >= get_size() || j >= get_size()) {
        throw out_of_range("Index out of range");
    }
    matrix[i][j] = value;
}

// Addition operator
Matrix Matrix::operator+(const Matrix& rhs) const {
    int n = get_size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = matrix[i][j] + rhs.matrix[i][j];
    return Matrix(result);
}

// Multiplication operator
Matrix Matrix::operator*(const Matrix& rhs) const {
    int n = get_size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                result[i][j] += matrix[i][k] * rhs.matrix[k][j];
    return Matrix(result);
}

// Sum of major (main) diagonal
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (int i = 0; i < get_size(); ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

// Sum of minor (anti) diagonal
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    int n = get_size();
    for (int i = 0; i < n; ++i) {
        sum += matrix[i][n - 1 - i];
    }
    return sum;
}

// Swap rows
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 >= get_size() || r2 >= get_size()) {
        throw out_of_range("Row index out of bounds");
    }
    std::swap(matrix[r1], matrix[r2]);
}

// Swap columns
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 >= get_size() || c2 >= get_size()) {
        throw out_of_range("Column index out of bounds");
    }
    for (int i = 0; i < get_size(); ++i) {
        std::swap(matrix[i][c1], matrix[i][c2]);
    }
}

// Print matrix
void Matrix::print_matrix() const {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
