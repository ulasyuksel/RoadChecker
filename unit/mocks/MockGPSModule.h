/*
 * MockGPSModule.h
 *
 *  Created on: Mar 3, 2024
 *      Author: Ulas Yuksel
 */

#ifndef MOCKGPSMODULE_H_
#define MOCKGPSMODULE_H_

#include <gmock/gmock.h>  // Brings in gMock.
#include "GPSModule.h"
#include "GeoCoordinate.h"

class MockGPSModule : public GPSModule {
 public:
	MockGPSModule();
    MOCK_METHOD(GeoCoordinate, getLocation, (), (const));
    MOCK_METHOD(bool, getLocation, (GeoCoordinate& out), (const));
};

#endif /* MOCKGPSMODULE_H_ */

