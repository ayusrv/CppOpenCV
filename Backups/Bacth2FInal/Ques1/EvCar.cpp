#include "EvCar.h"

EvCar::EvCar(std::string m_car_id, int m_battery_charging_time, Platform m_platform, float m_chassis_length, int m_seat_count, int m_top_speed)
    : _m_car_id{m_car_id}, _m_battery_charging_time{m_battery_charging_time}, _m_platform{m_platform}, _m_chassis_length{m_chassis_length}, _m_seat_count{m_seat_count}, _m_top_speed{m_top_speed} {}
std::string EvCar::EnumStringConverter (const Platform& platform) const
{
    if(platform == Platform::IC_BASED) return "Ic based";
    return "Pure EV";
}
std::ostream &operator<<(std::ostream &os, const EvCar &rhs)
{
    os << "_m_car_id: " << rhs._m_car_id
       << " _m_battery_charging_time: " << rhs._m_battery_charging_time
       << " _m_platform: " << rhs.EnumStringConverter(rhs._m_platform)
       << " _m_chassis_length: " << rhs._m_chassis_length
       << " _m_seat_count: " << rhs._m_seat_count
       << " _m_top_speed: " << rhs._m_top_speed;
    return os;
}