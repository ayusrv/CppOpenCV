#ifndef EVCAR_H
#define EVCAR_H

#include <iostream>
#include "Platform.h"
 class EvCar
 {
 private:
    std::string _m_car_id;
    int _m_battery_charging_time;
    Platform _m_platform;
    float _m_chassis_length;
    int _m_seat_count;
    int _m_top_speed;
 public:
    EvCar() = default;
    EvCar(const EvCar&) = delete;
    EvCar(EvCar&&) = delete;
    EvCar& operator= (const EvCar&) = delete;
    EvCar& operator= (EvCar&&) = delete;
    EvCar(std::string m_car_id, int m_battery_charging_time, Platform m_platform, float m_chassis_length, int m_seat_count, int m_top_speed);
    ~EvCar() = default;

    std::string mCarId() const { return _m_car_id; }
    void setMCarId(const std::string &m_car_id) { _m_car_id = m_car_id; }

    int mBatteryChargingTime() const { return _m_battery_charging_time; }
    void setMBatteryChargingTime(int m_battery_charging_time) { _m_battery_charging_time = m_battery_charging_time; }

    Platform mPlatform() const { return _m_platform; }
    void setMPlatform(const Platform &m_platform) { _m_platform = m_platform; }

    float mChassisLength() const { return _m_chassis_length; }
    void setMChassisLength(float m_chassis_length) { _m_chassis_length = m_chassis_length; }

    int mSeatCount() const { return _m_seat_count; }
    void setMSeatCount(int m_seat_count) { _m_seat_count = m_seat_count; }

    int mTopSpeed() const { return _m_top_speed; }
    void setMTopSpeed(int m_top_speed) { _m_top_speed = m_top_speed; }

    std::string EnumStringConverter (const Platform& platform) const;

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
 };

#endif // EVCAR_H
