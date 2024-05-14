#include "DebitCard.h"
std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "_date: " << rhs._date
       << " _card_number: " << rhs._card_number
       << " _cvv: " << rhs._cvv;
    return os;
}

DebitCard::DebitCard(std::string date, long card_number, int cvv)
        : _date{date}, _card_number{card_number}, _cvv{cvv} {}