/*
 * MockGPSModule.cc
 *
 *  Created on: Mar 3, 2024
 *      Author: Ulas Yuksel
 */

#include "MockGPSModule.h"

MockGPSModule * mockGPSModule;

MockGPSModule::MockGPSModule() {
	mockGPSModule = this;
}

GPSModule::GPSModule() {
}

GPSModule::~GPSModule() {
}

GeoCoordinate
GPSModule::getLocation() const
{
    return mockGPSModule->getLocation();
}

bool
GPSModule::getLocation(GeoCoordinate& out) const
{
	return mockGPSModule->getLocation(out);
}

