/*
 * MockSpeedUnit.cc
 *
 *  Created on: Mar 3, 2024
 *      Author: Ulas Yuksel
 */


#include "MockSpeedUnit.h"

MockSpeedUnit * mockSpeedUnit = nullptr;

MockSpeedUnit::MockSpeedUnit()
{
	mockSpeedUnit = this;
}

SpeedUnit::SpeedUnit()
{

}

SpeedUnit::~SpeedUnit()
{

}

int32_t SpeedUnit::getSpeed() const
{
	if (mockSpeedUnit)
	{
	    return mockSpeedUnit->getSpeed();
	}
	else
	{
        std::cout << "mock::mockSpeedUnit uninitialized. Unable to call " << __func__  << "." << std::endl;
		return 0;
	}
}
