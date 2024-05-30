/*
 * MockStateHandler.h
 *
 *  Created on: Mar 3, 2024
 *      Author: Ulas Yuksel
 */

#ifndef MOCKSTATEHANDLER_H_
#define MOCKSTATEHANDLER_H_


#include <gmock/gmock.h>  // Brings in gMock.
#include "StateHandler.h"
#include "GeoCoordinate.h"


class MockStateHandler : public StateHandler {
 public:
	MockStateHandler();
    MOCK_METHOD(bool, setRoadState, (eRoadChecker_State_t, GeoCoordinate location), (const));
};
#endif /* MOCKSTATEHANDLER_H_ */
