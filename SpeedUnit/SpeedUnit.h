/**
 * @file  SpeedUnit.h
 *
 * @brief This module implements various functions for SpeedUnit handling
 *        and provides API for handling necessary SpeedUnit parameters.
 * 
 * @note (c) 2024.
 * 
 * @author Ulas Yuksel
 */

#ifndef SPEEDUNIT_H_
#define SPEEDUNIT_H_
#include <cstdint>

class SpeedUnit {
public:
	SpeedUnit();
	virtual ~SpeedUnit();
	int32_t getSpeed() const;
};

#endif /* SPEEDUNIT_H_ */
