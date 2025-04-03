#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::size_t N;
    infile >> N;

    // Load two N x N matrices from the file
    Matrix mat1 = Matrix::load_from_file(infile, N);
    Matrix mat2 = Matrix::load_from_file(infile, N);
    infile.close();

    std::cout << "\nMatrix 1:\n";
    mat1.print_matrix();

    std::cout << "\nMatrix 2:\n";
    mat2.print_matrix();

    Matrix sum = mat1 + mat2;
    std::cout << "\nMatrix Addition Result:\n";
    sum.print_matrix();

    Matrix product = mat1 * mat2;
    std::cout << "\nMatrix Multiplication Result:\n";
    product.print_matrix();

    std::cout << "\nMatrix 1 Major Diagonal Sum: " << mat1.sum_diagonal_major() << "\n";
    std::cout << "Matrix 1 Minor Diagonal Sum: " << mat1.sum_diagonal_minor() << "\n";

    // Swap rows
    std::size_t r1, r2;
    std::cout << "\nEnter two row indices to swap in Matrix 1 (e.g. 1 2): ";
    std::cin >> r1 >> r2;
    try {
        mat1.swap_rows(r1, r2);
        std::cout << "Matrix 1 after swapping rows:\n";
        mat1.print_matrix();
    } catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Swap columns
    std::size_t c1, c2;
    std::cout << "\nEnter two column indices to swap in Matrix 1 (e.g. 1 2): ";
    std::cin >> c1 >> c2;
    try {
        mat1.swap_cols(c1, c2);
        std::cout << "Matrix 1 after swapping columns:\n";
        mat1.print_matrix();
    } catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Update value
    std::size_t row, col;
    int new_val;
    std::cout << "\nEnter row, column, and new value (e.g. 2 2 99): ";
    std::cin >> row >> col >> new_val;
    try {
        mat1.set_value(row, col, new_val);
        std::cout << "Matrix 1 after update:\n";
        mat1.print_matrix();
    } catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
