#ifndef CARDDETAILS_H
#define CARDDETAILS_H

#include <iostream>

class CardDetails
{
private:
    std::string _expiry;
    long _card_number;
    int _cvv;
public:
    static long _cardNumber;
    static int _CVV;
    CardDetails(std::string expiry);

    std::string expiry() const { return _expiry; }
    void setExpiry(const std::string &expiry) { _expiry = expiry; }

    long cardNumber() const { return _card_number; }

    int cvv() const { return _cvv; }

    friend std::ostream &operator<<(std::ostream &os, const CardDetails &rhs);
};

#endif // CARDDETAILS_H
