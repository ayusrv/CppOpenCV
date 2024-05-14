#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include "InvoiceType.h"

class Invoice
{
private:
    std::string _invoice_number;
    InvoiceType _invoice_type;
    int _invoice_count;
public:
    Invoice() = delete;
    ~Invoice() = default;
    Invoice(const Invoice&) = delete;
    Invoice(Invoice&&) = delete;
    Invoice& operator = (const Invoice&) = delete;
    Invoice& operator = (const Invoice&&) = delete;
    Invoice(std::string invoice_number, InvoiceType invoice_type, int invoice_count);

    std::string invoiceNumber() const { return _invoice_number; }
    void setInvoiceNumber(const std::string &invoice_number) { _invoice_number = invoice_number; }

    InvoiceType invoiceType() const { return _invoice_type; }
    void setInvoiceType(const InvoiceType &invoice_type) { _invoice_type = invoice_type; }

    int invoiceCount() const { return _invoice_count; }
    void setInvoiceCount(int invoice_count) { _invoice_count = invoice_count; }

    friend std::ostream &operator<<(std::ostream &os, const Invoice &rhs);
};

#endif // INVOICE_H
