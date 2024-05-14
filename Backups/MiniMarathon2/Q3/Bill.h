#ifndef BILL_H
#define BILL_H

#include "Invoice.h"
#include <memory>
#include <functional>

class Bill
{
private:
    float _bill_amount;
    float _bill_amount_tax;
    std::reference_wrapper<Invoice> _associated_invoice;
public:
    Bill() = delete;
    ~Bill() = default;
    Bill(const Bill&) = delete;
    Bill(Bill&&) = delete;
    Bill& operator = (const Bill&) = delete;
    Bill& operator = (const Bill&&) = delete;

    Bill(float bill_amount, float bill_amount_tax, std::reference_wrapper<Invoice> associated_invoice);

    float billAmount() const { return _bill_amount; }
    void setBillAmount(float bill_amount) { _bill_amount = bill_amount; }

    float billAmountTax() const { return _bill_amount_tax; }
    void setBillAmountTax(float bill_amount_tax) { _bill_amount_tax = bill_amount_tax; }

    std::reference_wrapper<Invoice> associatedInvoice() const { return _associated_invoice; }
    void setAssociatedInvoice(const std::reference_wrapper<Invoice> &associated_invoice) { _associated_invoice = associated_invoice; }
};

#endif // BILL_H
