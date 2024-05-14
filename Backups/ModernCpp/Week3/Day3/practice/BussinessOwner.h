#ifndef BUSSINESSOWNER_H
#define BUSSINESSOWNER_H

#include <iostream>
#include "BussinessType.h"

class BussinessOwner
{
private:
    float _expenses;
    float _revenue;
    std::string _registered_bussiness_name;
    BussinessType _bussiness_type;
public:
    BussinessOwner()=default;
    BussinessOwner(const BussinessOwner &)=delete;
    BussinessOwner(BussinessOwner && )=delete;
    BussinessOwner & operator=(const BussinessOwner & )=delete;
    BussinessOwner &operator=(BussinessOwner &&)=delete;
    ~BussinessOwner()=default;

    float expenses() const { return _expenses; }
    void setExpenses(float expenses) { _expenses = expenses; }

    float revenue() const { return _revenue; }
    void setRevenue(float revenue) { _revenue = revenue; }

    std::string registeredBussinessName() const { return _registered_bussiness_name; }
    void setRegisteredBussinessName(const std::string &registered_bussiness_name) { _registered_bussiness_name = registered_bussiness_name; }

    BussinessType bussinessType() const { return _bussiness_type; }
    void setBussinessType(const BussinessType &bussiness_type) { _bussiness_type = bussiness_type; }

    BussinessOwner(float expenses, float revenue, std::string registered_bussiness_type, BussinessType bussiness_type);

    friend std::ostream &operator<<(std::ostream &os, const BussinessOwner &rhs);
};

#endif // BUSSINESSOWNER_H
