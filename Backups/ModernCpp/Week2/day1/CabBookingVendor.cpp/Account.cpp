#include "Account.h"

unsigned long Account::_counter = 90000;

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "_id: " << rhs._userId
       << " _username: " << rhs._username;
    return os;
}

Account::Account(std::string username)
        : _username(username), _userId{++_counter} {}