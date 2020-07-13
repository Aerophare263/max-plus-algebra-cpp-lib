#pragma once
#include <limits> // numeric_limits<int>


namespace MaxPlus
{
    class Matrix_t
    {
        public:
            unsigned int rows;
            unsigned int cols;

            Matrix_t(const unsigned int num_rows, const unsigned int num_cols, int* vals);
            int& operator()(const unsigned int r, const unsigned int c);
            bool operator==(Matrix_t &mat1);
        private:
            int* m;
    };


    const int eps = std::numeric_limits<int>::min();
    const int e = 0;


    // Equivalent to the max operation
    int oplus(const int a, const int b);


    // Equivalent to regular addition
    int otimes(const int a, const int b);


    // Matrix_t oplus
    Matrix_t* oplus(Matrix_t* result, Matrix_t* mat0, Matrix_t* mat1);


    // Matrix_t otimes
    Matrix_t* otimes(Matrix_t* result, Matrix_t* mat0, Matrix_t* mat1);
};
