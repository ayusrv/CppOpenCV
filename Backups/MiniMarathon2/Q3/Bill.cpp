#include "Bill.h"
std::ostream &operator<<(std::ostream &os, const Bill &rhs) {
    os << "_bill_amount: " << rhs.billAmount()
       << " _bill_amount_tax: " << rhs.billAmountTax()
       << " _associated_invoice: " << rhs.associatedInvoice();
    return os;
}

Bill::Bill(float bill_amount, float bill_amount_tax, std::reference_wrapper<Invoice> associated_invoice)
      : _bill_amount{bill_amount}, _bill_amount_tax{bill_amount_tax}, _associated_invoice{associated_invoice} {}