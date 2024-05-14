#ifndef DEBITCARD_H
#define DEBITCARD_H

#include <iostream>

class DebitCard
{
private:
    std::string _date;
    long _card_number;
    int _cvv;
public:
    DebitCard()=default;
    DebitCard(const DebitCard &)=delete;
    DebitCard(DebitCard && )=delete;
    DebitCard & operator=(const DebitCard & )=delete;
    DebitCard &operator=(DebitCard &&)=delete;
    ~DebitCard()=default;
    DebitCard(std::string date, long card_number, int cvv);

    int cvv() const { return _cvv; }
    void setCvv(int cvv) { _cvv = cvv; }

    long cardNumber() const { return _card_number; }
    void setCardNumber(long card_number) { _card_number = card_number; }

    std::string date() const { return _date; }
    void setDate(const std::string &date) { _date = date; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif // DEBITCARD_H
