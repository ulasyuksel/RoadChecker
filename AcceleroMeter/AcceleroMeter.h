/**
 * @file  AcceleroMeter.h
 *
 * @brief This module implements various functions for AcceleroMeter handling
 *        and provides API for handling necessary AcceleroMeter parameters.
 * 
 * @note (c) 2024.
 * 
 * @author Ulas Yuksel
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_
#include "AcceleroMeterTypes.h"
#include <cstdint>

class AcceleroMeter {
public:
	AcceleroMeter();
        virtual ~AcceleroMeter();
        uint32_t getAcceleration(eAcceleroMeter_Direction_t direction) const;
};

#endif /* ACCELEROMETER_H_ */
