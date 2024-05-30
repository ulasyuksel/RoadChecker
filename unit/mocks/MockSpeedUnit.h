/*
 * MockSpeedUnit.h
 *
 *  Created on: Mar 3, 2024
 *      Author: Ulas Yuksel
 */

#ifndef MOCKSPEEDUNIT_H_
#define MOCKSPEEDUNIT_H_


#include <gmock/gmock.h>  // Brings in gMock.
#include "SpeedUnit.h"

class MockSpeedUnit : public SpeedUnit {
 public:
	MockSpeedUnit();
    MOCK_METHOD(int32_t, getSpeed, (), (const));
};

#endif /* MOCKSPEEDUNIT_H_ */
