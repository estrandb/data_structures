#ifndef STACK_H
#define STACK_H

#include "node.h"

class stack
{
    public:
        stack(){base = nullptr;}
        void push(node* node);
        node* pop();

        uint32_t maxnodes;

        virtual ~stack();

    protected:

    private:
        node* base;
        void destroy(node* base);
};

#endif // STACK_H
