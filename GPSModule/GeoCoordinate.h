/**
 * @file GeoCoordinate.h
 *
 * @brief This module implements various functions for GPS coordinate.
 * 
 * @note (c) 2024.
 * 
 * @author Ulas Yuksel
 */

#ifndef GEOCOORDINATE_H_
#define GEOCOORDINATE_H_
#include <iostream>

class GeoCoordinate{
public:
	GeoCoordinate(double latitude, double longitude);
	GeoCoordinate();
	virtual ~GeoCoordinate();
	bool operator==(const GeoCoordinate& rhs) const;
	friend std::ostream& operator<<(std::ostream& os, const GeoCoordinate& location);
	double getLatitude();
	double getLongitude();
	void setLatitude(double latitude);
	void setLongitude(double longitude);

private:
	double m_latitude;
	double m_longitude;
};

#endif /* GEOCOORDINATE_H_ */
