#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <iostream>
#include "AutoMobileType.h"


class Automobile
{
private:
    std::string _model_name; //Model of the data
    AutomobileType _automobile_type; //Tkaing the types in Enum
    float _automobile_price; //AUtomobile prices
    float _automobile_milage; //Automobile ranges
public:
    Automobile() = delete; //Deleting the default constructor
    ~Automobile() = default; //Defult of Destructor
    Automobile(const Automobile&) = delete; //Deleting the Copy COnstructor
    Automobile(Automobile&&) = delete; //Deleteing the move symantic
    Automobile& operator = (Automobile&) = delete; //Deleting the = operator
    Automobile& operator = (Automobile&&) = delete; //Deleting the = operator

    //Parametrized COnstructor
    Automobile(std::string model_name, AutomobileType automobile_type, float automobile_price, float automobile_milage);

    //Getter setter for model name
    std::string modelName() const { return _model_name; }
    void setModelName(const std::string &model_name) { _model_name = model_name; }

    //Getter setter for automobile type
    enum AutomobileType automobileType() const { return _automobile_type; }
    void setAutomobileType(const enum AutomobileType &automobile_type) { _automobile_type = automobile_type; }

    //gETTER SETTER for automobile price
    float automobilePrice() const { return _automobile_price; }
    void setAutomobilePrice(float automobile_price) { _automobile_price = automobile_price; }

    //getter setter for automobile milage
    float automobileMilage() const { return _automobile_milage; }
    void setAutomobileMilage(float automobile_milage) { _automobile_milage = automobile_milage; }

    //Output stream
    friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs);
    
};

#endif // AUTOMOBILE_H
