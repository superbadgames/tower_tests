#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <boost/test/unit_test.hpp>

#include <Tower/Math/Matrix.hpp>
#include <glm/mat4x4.hpp>


BOOST_AUTO_TEST_CASE(MatrixOperators)
{
    std::cout << "Running Matrix operator tests including ...\n";

    std::cout << "Matrix A * Matrix B...\n";

    Tower::Matrix A {5.0f, 0.0f, 18.0f, 0.0f,
                     0.0f, 15.0f, 25.0f, 0.0f,
                     45.0f, 0.0f, 0.0f, 0.0f,
                     123.0f, 321.0f, 567.0f, 1.0f};

    Tower::Matrix B {12.0f, 32.0f, 14.0f, 0.0f,
                     2.0f, 56.0f, 5.0f, 0.0f,
                     15.0f, 6.0f, 7.0f, 0.0f,
                     543.0f, 987.0f, 463.0f, 0.0f};

    Tower::Matrix C {};
    C = A * B;
    glm::mat4 c_accessor = C.GetRaw();

    glm::mat4x4 controlA = {5.0f, 0.0f, 18.0f, 0.0f,
                            0.0f, 15.0f, 25.0f, 0.0f,
                            45.0f, 0.0f, 0.0f, 0.0f,
                            123.0f, 321.0f, 567.0f, 1.0f};

    glm::mat4x4 controlB = {12.0f, 32.0f, 14.0f, 0.0f,
                            2.0f, 56.0f, 5.0f, 0.0f,
                            15.0f, 6.0f, 7.0f, 0.0f,
                            543.0f, 987.0f, 463.0f, 0.0f};

    glm::mat4x4 controlC = controlA * controlB;

    BOOST_TEST(c_accessor[0][0] == controlC[0][0]);
    BOOST_TEST(c_accessor[0][1] == controlC[0][1]);
    BOOST_TEST(c_accessor[0][2] == controlC[0][2]);
    BOOST_TEST(c_accessor[0][3] == controlC[0][3]);


    BOOST_TEST(c_accessor[1][0] == controlC[1][0]);
    BOOST_TEST(c_accessor[1][1] == controlC[1][1]);
    BOOST_TEST(c_accessor[1][2] == controlC[1][2]);
    BOOST_TEST(c_accessor[1][3] == controlC[1][3]);

    BOOST_TEST(c_accessor[2][0] == controlC[2][0]);
    BOOST_TEST(c_accessor[2][1] == controlC[2][1]);
    BOOST_TEST(c_accessor[2][2] == controlC[2][2]);
    BOOST_TEST(c_accessor[2][3] == controlC[2][3]);

    BOOST_TEST(c_accessor[3][0] == controlC[3][0]);
    BOOST_TEST(c_accessor[3][1] == controlC[3][1]);
    BOOST_TEST(c_accessor[3][2] == controlC[3][2]);
    BOOST_TEST(c_accessor[3][3] == controlC[3][3]);


    std::cout << "Vector v2 = Matrix A * Vector v...\n";

    glm::mat4 reset = {1.0f, 0.0f, 0.0f, 0.0f,
                       0.0f, 1.0f, 0.0f, 0.0f,
                       0.0f, 0.0f, 1.0f, 0.0f,
                       5.0f, 10.0f, 15.0f, 1.0f};

    A.Set(reset);

    Tower::Vector v {10.0f, 13.0f, 65.0f};

    Tower::Vector v2 = A * v;

    controlA = glm::mat4x4(1.0f);
    controlA[3][0] = 5.0f;
    controlA[3][1] = 10.0f;
    controlA[3][2] = 15.0f;

    glm::vec4 controlV = {10.0f, 13.0f, 65.0f, 1.0f};

    glm::vec4 controlAnswer = controlA * controlV;

    BOOST_TEST(v2.GetX() == controlAnswer.x);
    BOOST_TEST(v2.GetY() == controlAnswer.y);
    BOOST_TEST(v2.GetZ() == controlAnswer.z);

    std::cout << "Completed Matrix tests\n\n";
}


BOOST_AUTO_TEST_CASE(MatrixDeterminant)
{
    std::cout << "Running Matrix determinant test...\n";

    Tower::Matrix A {1.0f, 1.0f, 4.0f, 0.0f,
                     3.0f, 3.0f, 3.0f, 0.0f,
                     5.0f, 1.0f, 9.0f, 0.0f,
                     9.0f, 7.0f, 8.0f, 1.0f};

    F32 det = A.Determinant();

    glm::mat4x4 control = {1.0f, 1.0f, 4.0f, 0.0f,
                           3.0f, 3.0f, 3.0f, 0.0f,
                           5.0f, 1.0f, 9.0f, 0.0f,
                           9.0f, 7.0f, 8.0f, 1.0f};

    F32 controlDet = glm::determinant(control);

    BOOST_TEST(det == controlDet);
}
