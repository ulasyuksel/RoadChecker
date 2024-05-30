/*
 * MockAcceleroMeter.cc
 *
 *  Created on: Mar 3, 2024
 *      Author: Ulas Yuksel
 */
#include "MockAcceleroMeter.h"

MockAcceleroMeter * mockAcceleroMeter = nullptr;

MockAcceleroMeter::MockAcceleroMeter()
{
	mockAcceleroMeter = this;
}

AcceleroMeter::AcceleroMeter()
{
	// TODO Auto-generated constructor stub
}

AcceleroMeter::~AcceleroMeter()
{
	// TODO Auto-generated destructor stub
}


uint32_t AcceleroMeter::getAcceleration(eAcceleroMeter_Direction_t direction) const
{
	if (mockAcceleroMeter)
	{
	    return mockAcceleroMeter->getAcceleration(direction);
	}
	else
	{
        std::cout << "mock::mockAcceleroMeter uninitialized. Unable to call " << __func__  << "." << std::endl;
		return 0;
	}
}


