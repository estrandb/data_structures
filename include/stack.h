#ifndef STACK_H
#define STACK_H

#include <stdint.h>

class stack
{
    public:
        stack(){base = nullptr;}
        void push();
        void pop();

        uint32_t maxnodes;

        virtual ~stack();

    protected:

    private:
        uint32_t* base;
        void destroy();
};

#endif // STACK_H
