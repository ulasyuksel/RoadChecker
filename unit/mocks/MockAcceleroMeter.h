/*
 * MockAcceleroMeter.cc
 *
 *  Created on: Mar 3, 2024
 *      Author: Ulas Yuksel
 */


#include <gmock/gmock.h>  // Brings in gMock.
#include "AcceleroMeter.h"

class MockAcceleroMeter{
 public:
	MockAcceleroMeter();
    MOCK_METHOD(uint32_t, getAcceleration, (eAcceleroMeter_Direction_t direction), (const));
};

