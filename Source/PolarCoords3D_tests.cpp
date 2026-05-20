#include "pch.h"
#include <Tower/framework.h>

#include <Tower/Math/PolarCoords3d.hpp>
#include <Tower/Math/Vector.hpp>

#include <boost/test/unit_test.hpp>
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_CASE(test1, * utf::tolerance(float(0.00001)))
{
    std::cout << "Running PolarCoords3D To and from Cartesian tests.... \n";
    Tower::PolarCoords3D arcball {};
    arcball.SetRadius(1.0f);
    arcball.SetHeadingDegree(90.0f);
    arcball.SetPitchDegree(45.0f);

    // std::cout << "radius = " << arcball.GetRadius() << std::endl
    // << "heading = " << arcball.GetHeading() << std::endl
    // << "pitch = " << arcball.GetPitch() << std::endl;

    Tower::PolarCoords3D arcball2 {};
    arcball2.SetRadius(1.0f);
    arcball2.SetHeadingRadian(RADIAN(90.0f));
    arcball2.SetPitchRadian(RADIAN(45.0f));

    BOOST_TEST(arcball.GetRadius() == arcball2.GetRadius());
    BOOST_TEST(arcball.GetHeading() == arcball2.GetHeading());
    BOOST_TEST(arcball.GetPitch() == arcball2.GetPitch());

    Tower::Vector position {1.0f, 1.0f, 50.0f};

    arcball.SetFromCartesianCoords(position);

    Tower::Vector answer = arcball.GetCartesianCoords();

    BOOST_TEST(position.GetX() == answer.GetX());
    BOOST_TEST(position.GetY() == answer.GetY());
    BOOST_TEST(position.GetZ() == answer.GetZ());

    std::cout << "Finished running PolarCoords3D To and from Cartesian tests.... \n";
}