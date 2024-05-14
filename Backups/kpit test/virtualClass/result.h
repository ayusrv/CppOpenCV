#ifndef RESULT
#define RESULT

#include "sports.h"
#include "test.h"

class result: public test, public sports{
    public:
        void totalGrad();
};

#endif