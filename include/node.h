
#ifndef NODE_H
#define NODE_H

#include <stdint.h>

struct node
{
    uint32_t data;
    node* next;
    node* prev;
};

#endif // NODE_H
