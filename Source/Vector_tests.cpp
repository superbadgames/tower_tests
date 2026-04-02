#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <boost/test/unit_test.hpp>
namespace utf = boost::unit_test;

#include <Tower/Math/Vector.hpp>


BOOST_AUTO_TEST_CASE(VectorConstructors)
{
    std::cout << "Running Vector Constructor Tests...\n";

    Tower::Vector A {};

    BOOST_TEST(A.GetX() == 0.0f);
    BOOST_TEST(A.GetY() == 0.0f);
    BOOST_TEST(A.GetZ() == 0.0f);

    Tower::Vector B {42.0f, 100.0f};

    BOOST_TEST(B.GetX() == 42.0f);
    BOOST_TEST(B.GetY() == 100.0f);
    BOOST_TEST(B.GetZ() == 0.0f);

    Tower::Vector C {54.0f, 64.0f, 72.0f};

    BOOST_TEST(C.GetX() == 54.0f);
    BOOST_TEST(C.GetY() == 64.0f);
    BOOST_TEST(C.GetZ() == 72.0f);

    Tower::Vector D = C;

    BOOST_TEST(D.GetX() == 54.0f);
    BOOST_TEST(D.GetY() == 64.0f);
    BOOST_TEST(D.GetZ() == 72.0f);

    std::cout << "Finished running Vector Constructor Tests...\n";
}


BOOST_AUTO_TEST_CASE(VectorAssignmentOperators)
{
    std::cout << "Running Vector assignment operators including =, +=, -=, and *=...\n";

    Tower::Vector A { 12.0f, 14.0f, 16.0f};

    Tower::Vector B {};

    B = A;

    BOOST_TEST(B.GetX() == 12.0f);
    BOOST_TEST(B.GetY() == 14.0f);
    BOOST_TEST(B.GetZ() == 16.0f);

    Tower::Vector C {132.0f, 154.0f, 320.0f};

    B += C;

    BOOST_TEST(B.GetX() == 144.0f);
    BOOST_TEST(B.GetY() == 168.0f);
    BOOST_TEST(B.GetZ() == 336.0f);

    BOOST_TEST(C.GetX() == 132.0f);
    BOOST_TEST(C.GetY() == 154.0f);
    BOOST_TEST(C.GetZ() == 320.0f);

    C += 10.0f;

    BOOST_TEST(C.GetX() == 142.0f);
    BOOST_TEST(C.GetY() == 164.0f);
    BOOST_TEST(C.GetZ() == 330.0f);

    Tower::Vector D {50.0f, 100.0f, 25.0f};

    B -= D;

    BOOST_TEST(B.GetX() == 94.0f);
    BOOST_TEST(B.GetY() == 68.0f);
    BOOST_TEST(B.GetZ() == 311.0f);

    D -= 20.0f;

    BOOST_TEST(D.GetX() == 30.0f);
    BOOST_TEST(D.GetY() == 80.0f);
    BOOST_TEST(D.GetZ() == 5.0f);

    D *= 10.0f;

    BOOST_TEST(D.GetX() == 300.0f);
    BOOST_TEST(D.GetY() == 800.0f);
    BOOST_TEST(D.GetZ() == 50.0f);

    std::cout << "Finished running Vector assignment operator tests...\n";
}


BOOST_AUTO_TEST_CASE(VectorOperators)
{
    std::cout << "Running Vector operator tests include +, -, and *...\n";

    Tower::Vector A {10.0f, 15.0f, 25.0f};

    Tower::Vector B {5.0f, 8.0f};

    Tower::Vector C {};

    C = A + B;

    BOOST_TEST(C.GetX() == 15.0f);
    BOOST_TEST(C.GetY() == 23.0f);
    BOOST_TEST(C.GetZ() == 25.0f);

    Tower::Vector D {30.0f, 45.0f, 115.0f};

    D = A + 50.0f;

    BOOST_TEST(D.GetX() == 60.0f);
    BOOST_TEST(D.GetY() == 65.0f);
    BOOST_TEST(D.GetZ() == 75.0f);

    A = B - C;

    BOOST_TEST(A.GetX() == -10.0f);
    BOOST_TEST(A.GetY() == -15.0f);
    BOOST_TEST(A.GetZ() == -25.0f);

    C = D - 30.0f;

    BOOST_TEST(C.GetX() == 30.0f);
    BOOST_TEST(C.GetY() == 35.0f);
    BOOST_TEST(C.GetZ() == 45.0f);

    std::cout << "Finished running Vector operator Tests...\n";
}


// Answers were derived from emathhelp.net/calculators
BOOST_AUTO_TEST_CASE(VectorSpecialFunctions)
{
    std::cout << "Running Vector special functions tests, including Dot, Cross, Length, Squared Length, and Normalize...\n";

    Tower::Vector A {12.0f, 15.0f, 35.0f};

    Tower::Vector B {86.0f, 0.0f, 23.0f};

    F32 answer = A.Dot(B);

    BOOST_TEST(answer == 1837.0f);

    Tower::Vector C = A.Cross(B);

    BOOST_TEST(C.GetX() == 345.0f);
    BOOST_TEST(C.GetY() == 2734.0f);
    BOOST_TEST(C.GetZ() == -1290.0f);

    Tower::Vector D {3.0f, 4.0f, 12.0f};

    answer = D.Length();

    BOOST_TEST(answer == 13.0f);

    answer = D.SquaredLength();

    BOOST_TEST(answer == 169.0f);

    Tower::Vector E {54.0f, 86.0f, 12.0f};

    E.Normalize();

    BOOST_TEST(E.GetX() == 0.528093683001429f);
    BOOST_TEST(E.GetY() == 0.841038087743017f);
    BOOST_TEST(E.GetZ() == 0.117354151778095f);

    std::cout << "Finished running Vector special functions tests...\n";
}