#include "Functionalities.h"

void CreateObject(Container &data, PermitContainer &data2)
{
    data2.push_back( std::make_shared<Permit>("UK09HH888", PermitType::LEASE, 12));
    data.push_back(std::make_shared<TouristVehicle>("UK09HH888", VehicleType::CAB, 2, 900.8f,*data2[0]));

    data2.push_back(std::make_shared<Permit>("JH08U777", PermitType::OWNED, 19));
    data.push_back(std::make_shared<TouristVehicle>("JH08U777", VehicleType::BIKE, 2, 300.8f, *data2[1]));

    data.push_back(std::make_shared<TouristVehicle>("MH01U777", VehicleType::BUS, 8, 1200.8f, *data2[1]));

    data2.push_back(std::make_shared<Permit>("PB01HU7765", PermitType::LEASE, 12));
    data.push_back(std::make_shared<TouristVehicle>("PB01HU7765", VehicleType::CAB, 4, 700.8f,*data2[2]));
}

float AverageCharge(Container &data, PermitContainer &data2, std::string type)
{
    if (data.empty())
    {
        throw EmptyContainerException("NO DATA IS AVAILABLE");
    }
    float ans = 0.0f;
    size_t size = 0;
    VehicleType _type;
    if (type == "CAB" || type=="cab")
        _type = VehicleType::CAB;
    else if (type == "BUS" || type=="bus")
        _type = VehicleType::BUS;
    else if(type == "BIKE" || type=="bike")
        _type = VehicleType::BIKE;
    for (Pointer p : data)
    {
            if (p->vehicleType() == _type)
            {
                ans += p->perHourBookingCharge();
                size++;
            }
    }
    return ans / size;
}

std::string MaximumCharge(Container &data, PermitContainer &data2)
{
    if (data.empty())
    {
        throw EmptyContainerException("NO DATA IS AVAILABLE");
    }
    int i = 0;
    int _max_booking_charge = data[0]->perHourBookingCharge();
    for (int p = 0; p < data.size(); p++)
    {
        
            if (data[p]->perHourBookingCharge() > _max_booking_charge)
            {
                _max_booking_charge = data[p]->perHourBookingCharge();
                i = p;
            }
    }

    return data[i]->permit().get().serialNumer();
}

Container FirstNInstances(Container &data, PermitContainer &data2, int n)
{
    if (data.empty())
    {
        throw EmptyContainerException("NO DATA IS AVAILABLE");
    }
    if (n < 0 || n > data.size())
    {
        throw SizeNotMatched("Size input is less than 0 or more than the size of data");
    }
    Container result;
    for (int i = 0; i < n; i++)
    {
        result.push_back(data[i]);
    }
    return result;
}

Container NInstances(Container &data, PermitContainer &data2, int n)
{
    if (data.empty())
    {
        throw EmptyContainerException("NO DATA IS AVAILABLE");
    }
    if (n < 0 || n > data.size())
    {
        throw SizeNotMatched("Size input is less than 0 or more than the size of data");
    }
    Container result;
    for (Pointer p : data)
    {
            if (p->sertCount() >= 4 && p->permit().get().permitType()== PermitType::LEASE)
            {
                result.push_back(p);
            }
    }
    return result;
}

void Adapter(std::function<Container(Container &data, PermitContainer &data2, int n)> fun, Container &data, PermitContainer &data2, int n){
    Container val = fun(data, data2, n);
    for (Pointer p : val)
        {
            std::cout << *p << std::endl;
        }
}