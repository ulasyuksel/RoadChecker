#include "GeoCoordinate.h"

GeoCoordinate::GeoCoordinate()
	:GeoCoordinate(0,0)
{

}

GeoCoordinate::GeoCoordinate(double latitude, double longitude)
	:m_latitude(latitude)
    ,m_longitude(longitude)
{

}

GeoCoordinate::~GeoCoordinate()
{

}

bool
GeoCoordinate::operator==(const GeoCoordinate& rhs) const
{
    return ((this->m_latitude == rhs.m_latitude) && (this->m_longitude == rhs.m_longitude));
}

double
GeoCoordinate::getLatitude()
{
	return m_latitude;
}

double
GeoCoordinate::getLongitude()
{
	return m_longitude;
}

void
GeoCoordinate::setLatitude(double latitude)
{
	m_latitude = latitude;
}

void
GeoCoordinate::setLongitude(double longitude)
{
	m_longitude = longitude;
}

//Non-member operator
std::ostream& operator<<(std::ostream& os, const GeoCoordinate& location)
{
    os  << location.m_latitude << ((location.m_latitude < 0)? "S" : "N") << ", " << location.m_longitude <<  ((location.m_longitude < 0)? "W" :"E");
    return os;
}

