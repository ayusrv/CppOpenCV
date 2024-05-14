#include "Invoice.h"
std::ostream &operator<<(std::ostream &os, const Invoice &rhs) {
    os << "_invoice_number: " << rhs._invoice_number
       << " _invoice_count: " << rhs._invoice_count;
    return os;
}

Invoice::Invoice(std::string invoice_number, InvoiceType invoice_type, int invoice_count)
        : _invoice_number{invoice_number}, _invoice_type{invoice_type}, _invoice_count{invoice_count} {}