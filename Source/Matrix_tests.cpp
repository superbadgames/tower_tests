#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <boost/test/unit_test.hpp>

#include <Tower/Math/Matrix.hpp>

BOOST_AUTO_TEST_CASE(MatrixConstructors)
{
    std::cout << "Running Matrix constructor tests...\n";

    Tower::Matrix A {};

    BOOST_TEST(A.GetX1() == 1.0f);
    BOOST_TEST(A.GetX2() == 0.0f);
    BOOST_TEST(A.GetX3() == 0.0f);
    BOOST_TEST(A.GetX4() == 0.0f);


    BOOST_TEST(A.GetY1() == 0.0f);
    BOOST_TEST(A.GetY2() == 1.0f);
    BOOST_TEST(A.GetY3() == 0.0f);
    BOOST_TEST(A.GetY4() == 0.0f);

    BOOST_TEST(A.GetZ1() == 0.0f);
    BOOST_TEST(A.GetZ2() == 0.0f);
    BOOST_TEST(A.GetZ3() == 1.0f);
    BOOST_TEST(A.GetZ4() == 0.0f);

    BOOST_TEST(A.GetW1() == 0.0f);
    BOOST_TEST(A.GetW2() == 0.0f);
    BOOST_TEST(A.GetW3() == 0.0f);
    BOOST_TEST(A.GetW4() == 1.0f);

    A.SetX1(12.0f);
    A.SetX2(15.0f);
    A.SetX3(20.0f);

    A.SetY1(2.0f);
    A.SetY3(5.0f);

    A.SetZ2(6.0f);

    Tower::Matrix B {A};

    BOOST_TEST(B.GetX1() == 12.0f);
    BOOST_TEST(B.GetX2() == 15.0f);
    BOOST_TEST(B.GetX3() == 20.0f);
    BOOST_TEST(B.GetX4() == 0.0f);

    BOOST_TEST(B.GetY1() == 2.0f);
    BOOST_TEST(B.GetY2() == 1.0f);
    BOOST_TEST(B.GetY3() == 5.0f);
    BOOST_TEST(B.GetY4() == 0.0f);

    BOOST_TEST(B.GetZ1() == 0.0f);
    BOOST_TEST(B.GetZ2() == 6.0f);
    BOOST_TEST(B.GetZ3() == 1.0f);
    BOOST_TEST(B.GetZ4() == 0.0f);

    BOOST_TEST(B.GetW1() == 0.0f);
    BOOST_TEST(B.GetW2() == 0.0f);
    BOOST_TEST(B.GetW3() == 0.0f);
    BOOST_TEST(B.GetW4() == 1.0f);
}

BOOST_AUTO_TEST_CASE(MatrixAssignmentOperators)
{
    std::cout << "Running Matrix assignment operator tests including = and *=...\n";

    Tower::Matrix A {};

    A.SetX1(36.0f);
    A.SetX2(18.0f);
    A.SetX3(14.0f);

    A.SetY1(2.0f);
    A.SetY2(56.0f);
    A.SetY3(5.0f);

    A.SetZ1(15.0f);
    A.SetZ2(6.0f);
    A.SetZ3(74.0f);

    Tower::Matrix B {};

    B = A;

    BOOST_TEST(B.GetX1() == 36.0f);
    BOOST_TEST(B.GetX2() == 18.0f);
    BOOST_TEST(B.GetX3() == 14.0f);
    BOOST_TEST(B.GetX4() == 0.0f);

    BOOST_TEST(B.GetY1() == 2.0f);
    BOOST_TEST(B.GetY2() == 56.0f);
    BOOST_TEST(B.GetY3() == 5.0f);
    BOOST_TEST(B.GetY4() == 0.0f);

    BOOST_TEST(B.GetZ1() == 15.0f);
    BOOST_TEST(B.GetZ2() == 6.0f);
    BOOST_TEST(B.GetZ3() == 74.0f);
    BOOST_TEST(B.GetZ4() == 0.0f);

    BOOST_TEST(B.GetW1() == 0.0f);
    BOOST_TEST(B.GetW2() == 0.0f);
    BOOST_TEST(B.GetW3() == 0.0f);
    BOOST_TEST(B.GetW4() == 1.0f);


    A.SetX1(64.0f);
    A.SetX2(184.0f);
    A.SetX3(126.0f);

    A.SetY1(163.0f);
    A.SetY2(564.0f);
    A.SetY3(16.0f);

    A.SetZ1(83.0f);
    A.SetZ2(65.0f);
    A.SetZ3(732.0f);

    A.SetW1(123.0f);
    A.SetW2(321.0f);
    A.SetW4(567.0f);

    B.SetW1(543.0f);
    B.SetW2(987.0f);
    B.SetW3(463.0f);

    // A *= B;

    // BOOST_TEST(A.GetX1() == 36.0f);
    // BOOST_TEST(A.GetX2() == 18.0f);
    // BOOST_TEST(A.GetX3() == 14.0f);
    // BOOST_TEST(A.GetX4() == 0.0f);

    // BOOST_TEST(A.GetY1() == 2.0f);
    // BOOST_TEST(A.GetY2() == 56.0f);
    // BOOST_TEST(A.GetY3() == 5.0f);
    // BOOST_TEST(A.GetY4() == 0.0f);

    // BOOST_TEST(A.GetZ1() == 15.0f);
    // BOOST_TEST(A.GetZ2() == 6.0f);
    // BOOST_TEST(A.GetZ3() == 74.0f);
    // BOOST_TEST(A.GetZ4() == 0.0f);

    // BOOST_TEST(A.GetW1() == 0.0f);
    // BOOST_TEST(A.GetW2() == 0.0f);
    // BOOST_TEST(A.GetW3() == 0.0f);
    // BOOST_TEST(A.GetW4() == 1.0f);
}


BOOST_AUTO_TEST_CASE(MatrixOperators)
{
    std::cout << "Running Matrix operator tests including ...\n";

    Tower::Matrix A {};
    A.SetX1(5.0f);
    A.SetX3(18.0f);

    A.SetY2(15.0f);
    A.SetY3(35.0f);

    A.SetZ1(45.0f);

    A.SetW1(123.0f);
    A.SetW2(321.0f);
    A.SetW3(567.0f);

    Tower::Matrix B {};

    B.SetX1(12.0f);
    B.SetX2(32.0f);
    B.SetX3(14.0f);


    B.SetY1(2.0f);
    B.SetY2(56.0f);
    B.SetY3(5.0f);

    B.SetZ1(15.0f);
    B.SetZ2(6.0f);
    B.SetZ3(7.0f);

    B.SetW1(543.0f);
    B.SetW2(987.0f);
    B.SetW3(463.0f);

    Tower::Matrix C {};
    C = A * B;

    BOOST_TEST(C.GetX1() == 690.0f);
    BOOST_TEST(C.GetX2() == 480.0f);
    BOOST_TEST(C.GetX3() == 1350.0f);
    BOOST_TEST(C.GetX4() == 0.0f);


    BOOST_TEST(C.GetY1() == 235.0f);
    BOOST_TEST(C.GetY2() == 840.0f);
    BOOST_TEST(C.GetY3() == 2001.0f);
    BOOST_TEST(C.GetY4() == 0.0f);

    BOOST_TEST(C.GetZ1() == 390.0f);
    BOOST_TEST(C.GetZ2() == 90.0f);
    BOOST_TEST(C.GetZ3() == 487.0f);
    BOOST_TEST(C.GetZ4() == 0.0f);

    BOOST_TEST(C.GetW1() == 23673.0f);
    BOOST_TEST(C.GetW2() == 15126.0f);
    BOOST_TEST(C.GetW3() == 45349.0f);
    BOOST_TEST(C.GetW4() == 1.0f);

    std::cout << "Completed Matrix tests\n\n";
}
