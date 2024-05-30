/*
 * StateHandler.h
 *
 *  Created on: Mar 3, 2024
 *      Author: Ulas Yuksel
 */

/**
 * @file  StateHandler.h
 *
 * @brief This module implements various functions for StateHandler handling
 *        and provides API for handling necessary StateHandler parameters.
 * 
 * @note (c) 2024.
 * 
 * @author Ulas Yuksel
 */

#ifndef STATEHANDLER_H_
#define STATEHANDLER_H_
#include "RoadStateTypes.h"
class GeoCoordinate;

class StateHandler {
public:
	StateHandler();
	virtual ~StateHandler();
	bool setRoadState(eRoadChecker_State_t state, GeoCoordinate location) const;
};

#endif /* STATEHANDLER_H_ */
