#include "CardDetails.h"

int CardDetails::_CVV=500;
long CardDetails::_cardNumber=12345678;

CardDetails::CardDetails(std::string expiry) : _expiry{expiry}, _cvv {_CVV}, _card_number{_cardNumber}
{
    _CVV+=10;
    _cardNumber += 500;
}

std::ostream &operator<<(std::ostream &os, const CardDetails &rhs) {
    os << "_expiry: " << rhs._expiry
       << " _card_number: " << rhs._card_number
       << " _cvv: " << rhs._cvv;
    return os;
}
