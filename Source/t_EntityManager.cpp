#include "pch.h"
#include <boost/test/unit_test.hpp>
#include <Tower/Managers/EntityManager.h>
#include <Tower/Entity.h>



BOOST_AUTO_TEST_CASE(EntityManagerChecklist)
{
    Tower::p_EntityManager manager = Tower::EntityManager::Instance();
    Tower::Entity entity1 = manager->CreateEntity();
    Tower::Entity entity2 = manager->CreateEntity();

    BOOST_CHECK_EQUAL(entity1, 0);
    BOOST_CHECK_EQUAL(entity2, 1);

    
}
