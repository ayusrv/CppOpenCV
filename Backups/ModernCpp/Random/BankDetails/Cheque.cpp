#include "Cheque.h"
int Cheque::_chequeId = 1000;

std::ostream &operator<<(std::ostream &os, const Cheque &rhs) {
    os << "_amount: " << rhs._amount;
    return os;
}


Cheque::Cheque(int amount)
        : _amount{amount}, _cheque_id{_chequeId} {
            _chequeId+=50;
        }