/**
 * @file  RoadChecker.h
 *
 * @brief This module implements various functions for RoadChecker TOY EXAMPLE Module.
 * 
 * @note (c) 2024.
 * 
 * @author Ulas Yuksel
 */

#ifndef ROADCHECKER_H_
#define ROADCHECKER_H_

#include "RoadStateTypes.h"

class AcceleroMeter;
class GPSModule;
class SpeedUnit;
class StateHandler;

class RoadChecker {
public:
	RoadChecker(SpeedUnit& speedUnit, AcceleroMeter& acceleroMeter, GPSModule gpsModule, StateHandler& stateHandler);
	virtual ~RoadChecker();
	void checkState();
	eRoadChecker_State_t getState();

private:
	eRoadChecker_State_t m_roadState;
	const SpeedUnit& m_speedUnit;
	const AcceleroMeter& m_acceleroMeter;
	const GPSModule& m_gpsModule;
	const StateHandler& m_stateHandler;
};

#endif /* ROADCHECKER_H_ */
