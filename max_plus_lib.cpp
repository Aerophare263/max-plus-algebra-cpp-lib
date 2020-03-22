#include "max_plus_lib.hpp"

int MaxPlus::oplus(int a, int b)
{
    return a ^ ((a ^ b) & -(a < b));
}

int MaxPlus::otimes(int a, int b)
{
    if (a == MaxPlus::eps || b == MaxPlus::eps)
        return MaxPlus::eps;
    return a + b;
}

MaxPlus::Matrix MaxPlus::oplus(MaxPlus::Matrix &A, MaxPlus::Matrix &B)
{
    int resultVals[A.numRows * A.numCols];
    Matrix result(A.numRows, A.numCols, resultVals);
    int maxVal;
    for (unsigned int i = 0; i < A.numRows; i++)
    {
        for (unsigned int j = 0; j < A.numCols; j++)
        {
            maxVal = MaxPlus::oplus(A.val(i, j), B.val(i, j));
            result.val(i, j, maxVal);
        }
    }
    return result;
}

MaxPlus::Matrix MaxPlus::otimes(MaxPlus::Matrix &A, MaxPlus::Matrix &B)
{   
    int resultVals[A.numRows * B.numCols];
    Matrix result(A.numRows, B.numCols, resultVals);
    int val;
    int sum;
    for (unsigned int k = 0; k < B.numCols; k++)
    {   
        for (unsigned int j = 0; j < A.numCols; j++)
        {
            val = eps;
            for (unsigned int i = 0; i < A.numRows; i++)
            {
                sum = MaxPlus::otimes(B.val(i, j), A.val(k, i));
                val = MaxPlus::oplus(val, sum);
            }
            result.val(k, j, val);
        }
    }
    return result;
}

MaxPlus::Matrix::Matrix(int rows, int cols, int* A)
{
    numCols = cols;
    numRows = rows;
    vals = A;
}

int MaxPlus::Matrix::val(int row, int col)
{
    return vals[(row * numCols) + col];
}

void MaxPlus::Matrix::val(int row, int col, int newVal)
{
    vals[(row * numCols) + col] = newVal;
}

bool MaxPlus::Matrix::operator==(MaxPlus::Matrix &B)
{
    if (numRows == B.numRows && numCols == B.numRows)
    {
        // Check vals == B.vals
        for (unsigned int i = 0; i < numRows; i++)
        {
            for (unsigned int j = 0; j < numCols; j++)
            {
                if (val(i, j) != B.val(i, j))
                    return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}