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
    bool operator==(Matrix_t& mat1);

  private:
    int* m;
};

const int eps = std::numeric_limits<int>::min();
const int e = 0;

/**
 * @brief Equivalent to the max operation.
 * @param a First operand.
 * @param b Second operand.
 * @return Max( @p a , @p b )
 */
int oplus(const int a, const int b);

/**
 * @brief Equivalent to regular addition.
 * @param a First operand.
 * @param b Second operand.
 * @return Add( @p a , @p b )
 */
int otimes(const int a, const int b);

/**
 * @brief Applied element wise (symmetrically) so result(i,j) = mat0(i,j) + mat1(i,j) .
 * @param result Where the result will be written.
 * @param mat0 First operand.
 * @param mat1 Second operand.
 * @return Element-wise max operation.
 */
Matrix_t* oplus(Matrix_t* result, Matrix_t* mat0, Matrix_t* mat1);

/**
 * @brief Equivalent to regular matrix multiplication but with addition and multiplication
 *        replaced with oplus and otimes respectively.
 * @param result Where the result will be written.
 * @param mat0 First operand.
 * @param mat1 Second operand.
 * @return Element-wise add operation
 */
Matrix_t* otimes(Matrix_t* result, Matrix_t* mat0, Matrix_t* mat1);
}; // namespace MaxPlus
