/**
 * @file  RoadStateTypes.h
 *
 * @brief This module implements various type definitions.
 * 
 * @note (c) 2024.
 * 
 * @author Ulas Yuksel
 */

#ifndef ROADSTATETYPES_H_
#define ROADSTATETYPES_H_
#include <cstdint>

constexpr  int32_t min_speed_to_check = 10;
constexpr  uint32_t broken_road_acc_min = 879;

typedef enum
{
    ROAD_STATE_UNKNOWN = 0,
	ROAD_STATE_BROKEN = 1,
} eRoadChecker_State_t;



#endif /* ROADSTATETYPES_H_ */
