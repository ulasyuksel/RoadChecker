#include "RoadChecker.h"
#include "AcceleroMeter.h"
#include "GeoCoordinate.h"
#include "GPSModule.h"
#include "SpeedUnit.h"
#include "StateHandler.h"

RoadChecker::RoadChecker(SpeedUnit& speedUnit, AcceleroMeter& acceleroMeter, 
                               GPSModule gpsModule, StateHandler& stateHandler )
    :m_speedUnit(speedUnit)
	,m_acceleroMeter(acceleroMeter)
    ,m_gpsModule(gpsModule)
    ,m_stateHandler(stateHandler)
	,m_roadState(ROAD_STATE_UNKNOWN)
{
}

RoadChecker::~RoadChecker()
{
}

void
RoadChecker::checkState()
{
	m_roadState = ROAD_STATE_UNKNOWN;
	uint32_t speed = m_speedUnit.getSpeed();
	std::cout << "speed: " << speed << std::endl;
	if (speed > min_speed_to_check)
	{
		if (m_acceleroMeter.getAcceleration(ACC_PROCESSED) > broken_road_acc_min)
		{
			m_roadState = ROAD_STATE_BROKEN; //m_acceleroMeter.getAcceleration(ACC_DIRECTION_VERTICAL) ; //just for demo
			GeoCoordinate local_coordinate;
			bool location_success = m_gpsModule.getLocation(local_coordinate);
			if (location_success)
			{
				if (m_stateHandler.setRoadState(m_roadState, local_coordinate))
				{
					std::cout << "SUCCESS!" << std::endl;
				}
				else
				{
					if (m_stateHandler.setRoadState(m_roadState, local_coordinate))
					{
						std::cout << "SUCCESS! at 2nd set" << std::endl;
					}
					else
					{
						std::cout << "FAIL!" << std::endl;
					}
				}
			}
			else
			{
				std::cout << "get location FAIL!" << std::endl;
			}
		}
		else
		{
			std::cout << "ACC is low!" << std::endl;
		}
	}
	else
	{
		std::cout << "Speed is low!" << std::endl;
	}
}

eRoadChecker_State_t
RoadChecker::getState()
{
   return m_roadState;
}

