#include <assert.h> // assert
#include <chrono> // high_resolution_clock
#include <iostream> // printf


#include "libmaxplus.hh"


using namespace MaxPlus;


int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();

    // ----------------------------------------------------
    // Test matrix class
    // ----------------------------------------------------
    int test_vals[4] = {
        4, e, 
        e, eps
    };
    Matrix_t test_mat(2, 2, test_vals);

    assert(test_mat == test_mat);
    assert(test_mat(0, 0) == 4);
    assert(test_mat(0, 1) == e);
    assert(test_mat(1, 0) == e);
    assert(test_mat(1, 1) == eps);

    int test_vals_changed[4] = {
        4, e, 
        10, eps
    };
    Matrix_t test_mat_changed(2, 2, test_vals_changed);

    test_mat(1, 0) = 10;
    assert(test_mat == test_mat_changed);

    // ----------------------------------------------------
    // Test max-plus operations with int literals
    // ----------------------------------------------------
    assert(oplus(4, 11) == 11);
    assert(oplus(e, eps) == e);
    assert(oplus(eps, e) == e);
    assert(oplus(eps, 1) == 1);
    assert(oplus(eps, eps) == eps);

    assert(otimes(5, 1) == 6);
    assert(otimes(eps, 1) == eps);
    assert(otimes(eps, e) == eps);
    assert(otimes(eps, eps) == eps);
    assert(otimes(1, 1) == 2);
    assert(otimes(e, eps) == eps);

    // ----------------------------------------------------
    // Test max-plus matrix operations
    // ----------------------------------------------------
    int oplus_expected_vals[9] = {
        1, 2, eps, 
        5,e, 1, 
        eps, 1, 2
    };
    int oplus_result_vals[9] = {
        0, 0, 0, 
        0, 0, 0, 
        0, 0, 0
    };

    int otimes_expected_vals[9] = {
        2, 2, 1, 
        e, e, -1,
        1, 1, 0
    };
    int otimes_result_vals[9] = {
        0, 0, 0, 
        0, 0, 0, 
        0, 0, 0
    };
    
    for (long long int i = 0; i < 10e5; i++)
    {
        int a_vals[9] = {
            1, 2, eps, 
            5, e, 1, 
            eps, 1, 2
        };
        int b_vals[9] = {
            eps, eps, eps, 
            e, e, -1, 
            eps, -9, -2
        };
        Matrix_t mat_a(3, 3, a_vals);
        Matrix_t mat_b(3, 3, b_vals);

        Matrix_t oplus_expected(3, 3, oplus_expected_vals);
        Matrix_t oplus_result(3, 3, oplus_result_vals);
        oplus(&oplus_result, &mat_a, &mat_b);
        assert(oplus_result == oplus_expected);
        
        Matrix_t otimes_expected(3, 3, otimes_expected_vals);
        Matrix_t otimes_result(3, 3, otimes_result_vals);
        otimes(&otimes_result, &mat_a, &mat_b);
        assert(otimes_result == otimes_expected);
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    printf("Took %li microseconds\n", duration);
    return 0;
}
