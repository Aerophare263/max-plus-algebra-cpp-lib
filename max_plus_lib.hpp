#include <limits>

namespace MaxPlus
{
    class Matrix
    {
        public:
            int numCols;
            int numRows;

            Matrix(int rows, int cols, int* A);
            int val(int row, int col);
            void val(int row, int col, int newVal);
            bool operator==(Matrix &B);
        private:
            int* vals;
    };

    const int eps = std::numeric_limits<int>::min();
    const int e = 0;

    // Equivalent to the max operation
    int oplus(int a, int b);

    // Equivalent to regular addition
    int otimes(int a, int b);

    // Matrix oplus
    Matrix oplus(Matrix &A, Matrix &B);

    // Matrix otimes
    Matrix otimes(Matrix &A, Matrix &B);
};