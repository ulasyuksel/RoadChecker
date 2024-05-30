/**
 * @file GPSModule.h
 *
 * @brief This module implements various functions for GPS Module handling
 *        and provides API for handling necessary GPS parameters.
 * 
 * @note (c) 2024.
 * 
 * @author Ulas Yuksel
 */

#ifndef GPSMODULE_H_
#define GPSMODULE_H_
class GeoCoordinate;

class GPSModule {
public:
	GPSModule();
	virtual ~GPSModule();
	GeoCoordinate getLocation() const;
	bool getLocation(GeoCoordinate& out) const;
};

#endif /* GPSMODULE_H_ */
