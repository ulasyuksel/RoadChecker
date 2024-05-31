
/**
 * @file RoadCheckerTest.cc
 *
 * @brief Unit Tests for RoadChecker.
 * 
 * @note (c) 2024.
 * 
 * @author Ulas Yuksel
 */

#include <gtest/gtest.h>
#include "RoadChecker.h"
#include "MockAcceleroMeter.h"
#include "MockGPSModule.h"
#include "MockSpeedUnit.h"
#include "MockStateHandler.h"
#include "GeoCoordinate.h"

constexpr  int32_t valid_speed_to_check_value = (min_speed_to_check + 1);
constexpr  uint32_t valid_broken_road_acc = (broken_road_acc_min + 1);
const GeoCoordinate izmir_clock_tower_coordinate(38.41931921221547, 27.12861099041974);
const GeoCoordinate zero_zero_coordinate;

using namespace testing;
// The fixture for testing class Foo.
class RoadCheckerTest : public testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  RoadCheckerTest() {
     // You can do set-up work for each test here.
  }

  ~RoadCheckerTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  MockAcceleroMeter m_acceleroMeterMock;
  MockSpeedUnit m_speedUnitMock;
  MockGPSModule m_gpsModuleMock;
  MockStateHandler m_stateHandlerMock;

  AcceleroMeter m_acceleroMeterStub; //Just to demo MockAcceleroMeter is not inhereted from AcceleroMeter
  RoadChecker m_roadChecker{m_speedUnitMock, m_acceleroMeterStub, m_gpsModuleMock, m_stateHandlerMock};
};

TEST_F(RoadCheckerTest, ZeroSpeedRoadState)
{
	EXPECT_CALL(m_speedUnitMock,getSpeed()).Times(1).WillOnce(Return(0)) ;
   EXPECT_CALL(m_acceleroMeterMock,getAcceleration(_)).Times(0);

	m_roadChecker.checkState();

   // Expect equality.
   EXPECT_EQ(m_roadChecker.getState(), ROAD_STATE_UNKNOWN);

   //Below lines are just to demo ASSERT_ vs EXPECT_ difference
   //ASSERT_EQ(m_roadChecker.getState(), ROAD_STATE_BROKEN);
   //std::cout << "AFTER FAIL DEMO" << std::endl;
}

TEST_F(RoadCheckerTest, OverLimitSpeedOverVerticalLimitRoadState)
{
	EXPECT_CALL(m_speedUnitMock,getSpeed()).Times(1).WillOnce(Return(valid_speed_to_check_value)) ;
	EXPECT_CALL(m_acceleroMeterMock,getAcceleration(ACC_PROCESSED)).Times(1).WillOnce(Return(valid_broken_road_acc));
	EXPECT_CALL(m_acceleroMeterMock,getAcceleration(Ne(ACC_PROCESSED))).Times(0);
	EXPECT_CALL(m_gpsModuleMock,getLocation(_)).Times(1).WillOnce(DoAll(SetArgReferee<0>(izmir_clock_tower_coordinate), Return(true)));
	EXPECT_CALL(m_stateHandlerMock,setRoadState(ROAD_STATE_BROKEN, izmir_clock_tower_coordinate)).Times(1).WillOnce(Return(true));

	m_roadChecker.checkState();

   // Expect equality.
   EXPECT_EQ(m_roadChecker.getState(), ROAD_STATE_BROKEN);
}

TEST_F(RoadCheckerTest, OverLimitSpeedOverVerticalLimitRoadStateFirstSetStateFail)
{
	EXPECT_CALL(m_speedUnitMock,getSpeed()).Times(1).WillOnce(Return(valid_speed_to_check_value)) ;
	EXPECT_CALL(m_acceleroMeterMock,getAcceleration(ACC_PROCESSED)).Times(1).WillOnce(Return(valid_broken_road_acc));
   EXPECT_CALL(m_acceleroMeterMock,getAcceleration(Ne(ACC_PROCESSED))).Times(0);
	EXPECT_CALL(m_gpsModuleMock,getLocation(_)).Times(1).WillOnce([](GeoCoordinate& out){
      out = izmir_clock_tower_coordinate;
      return true;
   });
	EXPECT_CALL(m_stateHandlerMock,setRoadState(ROAD_STATE_BROKEN, izmir_clock_tower_coordinate)).Times(2)
																									.WillOnce(Return(false))
																									.WillOnce(Return(true));

	m_roadChecker.checkState();

   // Expect equality.
   EXPECT_EQ(m_roadChecker.getState(), ROAD_STATE_BROKEN);
}

/* Test to find bug in code */
TEST_F(RoadCheckerTest, MinimumIntigerSpeedRoadState)
{
	EXPECT_CALL(m_speedUnitMock,getSpeed()).Times(1).WillOnce(Return(INT_MIN)); //INT_MIN
   EXPECT_CALL(m_acceleroMeterMock,getAcceleration(_)).Times(0);

	m_roadChecker.checkState();

   // Expect equality.
   EXPECT_EQ(m_roadChecker.getState(), ROAD_STATE_UNKNOWN);
}

/* Tests for %100 coverage */

TEST_F(RoadCheckerTest, OverLimitSpeedOverVerticalLimitRoadStateAllSetStateFail)
{
	EXPECT_CALL(m_speedUnitMock,getSpeed()).Times(1).WillOnce(Return(valid_speed_to_check_value)) ;
	EXPECT_CALL(m_acceleroMeterMock,getAcceleration(ACC_PROCESSED)).Times(1).WillOnce(Return(valid_broken_road_acc));
	EXPECT_CALL(m_acceleroMeterMock,getAcceleration(Ne(ACC_PROCESSED))).Times(0);
	EXPECT_CALL(m_gpsModuleMock,getLocation(_)).Times(1).WillOnce(DoAll(SetArgReferee<0>(izmir_clock_tower_coordinate),Return(true)));
	EXPECT_CALL(m_stateHandlerMock,setRoadState(ROAD_STATE_BROKEN, izmir_clock_tower_coordinate)).Times(2).WillRepeatedly(Return(false));

	m_roadChecker.checkState();

   // Expect equality.
   EXPECT_EQ(m_roadChecker.getState(), ROAD_STATE_BROKEN);
}

TEST_F(RoadCheckerTest, GetLocationFail)
{
	EXPECT_CALL(m_speedUnitMock,getSpeed()).Times(1).WillOnce(Return(valid_speed_to_check_value)) ;
	EXPECT_CALL(m_acceleroMeterMock,getAcceleration(ACC_PROCESSED)).Times(1).WillOnce(Return(valid_broken_road_acc));
	EXPECT_CALL(m_acceleroMeterMock,getAcceleration(Ne(ACC_PROCESSED))).Times(0);
	EXPECT_CALL(m_gpsModuleMock,getLocation(_)).Times(1).WillOnce(Return(false));
	EXPECT_CALL(m_stateHandlerMock,setRoadState(_, _)).Times(0);

	m_roadChecker.checkState();

   // Expect equality.
   EXPECT_EQ(m_roadChecker.getState(), ROAD_STATE_BROKEN);
}

TEST_F(RoadCheckerTest, OverLimitSpeedOverVerticalLimitZeroAcc)
{
	EXPECT_CALL(m_speedUnitMock,getSpeed()).Times(1).WillOnce(Return(valid_speed_to_check_value)) ;
	EXPECT_CALL(m_acceleroMeterMock,getAcceleration(ACC_PROCESSED)).Times(1).WillOnce(Return(0));
	EXPECT_CALL(m_acceleroMeterMock,getAcceleration(Ne(ACC_PROCESSED))).Times(0);
	EXPECT_CALL(m_gpsModuleMock,getLocation(_)).Times(0);
	EXPECT_CALL(m_stateHandlerMock,setRoadState(_, _)).Times(0);

	m_roadChecker.checkState();

   // Expect equality.
   EXPECT_EQ(m_roadChecker.getState(), ROAD_STATE_UNKNOWN);
}