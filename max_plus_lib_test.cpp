#include "max_plus_lib.hpp"
#include <assert.h>
#include <iostream>

using namespace MaxPlus;

int main()
{
    // ----------------------------------------------------
    // Test matrix class
    // ----------------------------------------------------
    int testVals[4] = {4, e, e, eps};
    Matrix testMat(2, 2, testVals);

    assert((testMat == testMat) == true);
    assert(testMat.val(0, 1) == e);

    int testValsChanged[4] = {4, e, 10, eps};
    Matrix testMatChanged(2, 2, testValsChanged);

    testMat.val(1, 0, 10);
    assert(testMat == testMatChanged);

    // ----------------------------------------------------
    // Test max-plus operations with int literals
    // ----------------------------------------------------

    assert(oplus(4, 11) == 11);
    assert(oplus(e, eps) == e);
    assert(oplus(eps, eps) == eps);

    assert(otimes(5, 1) == 6);

    // ----------------------------------------------------
    // Test max-plus matrix operations
    // ----------------------------------------------------

    int valsA[9] = {1, 2, eps, 5, e, 1, eps, 1, 2};
    Matrix A(3, 3, valsA);
    int valsB[9] = {eps, eps, eps, e, e, -1, eps, -9, -2};
    Matrix B(3, 3, valsB);

    int oplusResultVals[9] = {1, 2, eps, 5,e, 1, eps, 1, 2};
    Matrix oplusResult(3, 3, oplusResultVals);
    assert(oplus(A, B) == oplusResult);

    int otimesResultVals[9] = {2, 2, 1, e, e, -1, 1, 1, 0};
    Matrix otimesResult(3, 3, otimesResultVals);
    assert(otimes(A, B) == otimesResult);

    return 0;
}