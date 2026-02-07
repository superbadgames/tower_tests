#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Math/Matrix.hpp>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(MatrixMultiplicationTests)
{
    std::cout << "Running Matrix Multiplication tests...\n";

    Tower::Matrix A {};
    A.SetX2(5.0f);
    A.SetX3(18.0f);

    A.SetY3(35.0f);

    A.SetZ1(45.0f);

    A.SetW1(5.0f);
    A.SetW2(3.0f);
    A.SetW3(4.0f);

    Tower::Matrix B {};
    B.SetX3(2.0f);

    B.SetY3(9.0f);

    B.SetZ1(6.0f);
    B.SetZ2(12.0f);

    B.SetW1(2.0f);
    B.SetW2(4.0f);
    B.SetW3(6.0f);

    Tower::Matrix C = A * B;

    BOOST_TEST(C.GetX1() == 91.0f);
    BOOST_TEST(C.GetX2() == 5.0f);
    BOOST_TEST(C.GetX3() == 20.0f);
    BOOST_TEST(C.GetX4() == 0.0f);


    BOOST_TEST(C.GetY1() == 405.0f);
    BOOST_TEST(C.GetY2() == 1.0f);
    BOOST_TEST(C.GetY3() == 44.0f);
    BOOST_TEST(C.GetY4() == 0.0f);

    BOOST_TEST(C.GetZ1() == 51.0f);
    BOOST_TEST(C.GetZ2() == 42.0f);
    BOOST_TEST(C.GetZ3() == 529.0f);
    BOOST_TEST(C.GetZ4() == 0.0f);

    BOOST_TEST(C.GetW1() == 277.0f);
    BOOST_TEST(C.GetW2() == 17.0f);
    BOOST_TEST(C.GetW3() == 186.0f);
    BOOST_TEST(C.GetW4() == 1.0f);

    std::cout << "Completed Matrix tests\n\n";
}
