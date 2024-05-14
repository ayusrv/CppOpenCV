#ifndef CHEQUE_H
#define CHEQUE_H
#include <ostream>

class Cheque
{
private:
    int _amount;
    int _cheque_id;
public:
    static int _chequeId;
    Cheque(int amount);

    int amount() const { return _amount; }
    void setAmount(int amount) { _amount = amount; }

    int chequeId() const { return _cheque_id; }

    friend std::ostream &operator<<(std::ostream &os, const Cheque &rhs);
};

#endif // CHEQUE_H
