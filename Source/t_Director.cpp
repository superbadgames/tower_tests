#include "pch.h"
#include <boost/test/unit_test.hpp>
#include <Tower/Director.h>
#include <Tower/Components/Transform.h>



BOOST_AUTO_TEST_CASE(EntityManagerChecklist)
{
    Tower::p_Director handle = Tower::Director::Instance();
    handle->Init();

    handle->RegisterComponent<Tower::Transform>();

    Tower::Entity first = handle->CreateEntity();

}
