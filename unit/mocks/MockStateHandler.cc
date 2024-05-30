/*
 * MockStateHandler.cc
 *
 *  Created on: Mar 3, 2024
 *      Author: Ulas Yuksel
 */


#include "MockStateHandler.h"

MockStateHandler * mockStateHandler = nullptr;

MockStateHandler::MockStateHandler()
{
	mockStateHandler = this;
}

StateHandler::StateHandler()
{

}

StateHandler::~StateHandler()
{

}

bool
StateHandler::setRoadState(eRoadChecker_State_t state, GeoCoordinate location) const
{
	if (mockStateHandler)
	{
	    return mockStateHandler->setRoadState(state, location);
	}
	else
	{
        std::cout << "mock::mockStateHandler uninitialized. Unable to call " << __func__  << "." << std::endl;
		return false;
	}
}
