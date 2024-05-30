#include "GPSModule.h"
#include "GeoCoordinate.h"

GPSModule::GPSModule()
{
	// TODO Auto-generated constructor stub
}

GPSModule::~GPSModule()
{
	// TODO Auto-generated destructor stub
}

GeoCoordinate
GPSModule::getLocation() const
{
    return GeoCoordinate(0,0); // TODO stub
}

bool 
getLocation(GeoCoordinate& out) const
{
	return false;
}

