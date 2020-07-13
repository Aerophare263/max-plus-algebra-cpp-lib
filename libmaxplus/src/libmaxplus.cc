#include "libmaxplus.hh"


MaxPlus::Matrix_t::Matrix_t(const unsigned int num_rows, const unsigned int num_cols, int* vals)
{
    rows = num_rows;
    cols = num_cols;
    m = vals;
}


int& MaxPlus::Matrix_t::operator()(const unsigned int r, const unsigned int c)
{
    return m[(r * cols) + c];
}


bool MaxPlus::Matrix_t::operator==(Matrix_t &mat1)
{
    if (rows == mat1.rows && cols == mat1.cols)
    {
        for (unsigned int i = 0; i < rows; i++)
        {
            for (unsigned int j = 0; j < cols; j++)
            {
                if ((*this)(i, j) != mat1(i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}


int MaxPlus::oplus(const int a, const int b)
{
    return a ^ ((a ^ b) & -(a < b)); // Equivalent to max(a, b)
}


int MaxPlus::otimes(const int a, const int b)
{
    if (a == MaxPlus::eps || b == MaxPlus::eps)
    {
        return MaxPlus::eps;
    }
    return a + b;
}


MaxPlus::Matrix_t* MaxPlus::oplus(Matrix_t* result, Matrix_t* mat0, Matrix_t* mat1)
{
    int max_val;
    for (unsigned int i = 0; i < mat0->rows; i++)
    {
        for (unsigned int j = 0; j < mat0->cols; j++)
        {
            max_val = oplus((*mat0)(i, j), (*mat1)(i, j));
            (*result)(i, j) = max_val;
        }
    }
    return result;
}


MaxPlus::Matrix_t* MaxPlus::otimes(Matrix_t* result, Matrix_t* mat0, Matrix_t* mat1)
{   
    int val;
    int sum;
    for (unsigned int k = 0; k < mat1->cols; k++)
    {   
        for (unsigned int j = 0; j < mat0->cols; j++)
        {
            val = eps;
            for (unsigned int i = 0; i < mat0->rows; i++)
            {
                sum = otimes((*mat1)(i, j), (*mat0)(k, i));
                val = oplus(val, sum);
            }
            (*result)(k, j) = val;
        }
    }
    return result;
}
