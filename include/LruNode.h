#ifndef LRUNODE_H
#define LRUNODE_H

#include <stdint.h>

template <typedef T>
struct LruNode
{
    LruNode(T nodeData, uint32_t key) : Data(nodeData), Key(key){}

    T Data;
    uint32_t Key;

};

#endif // LRUNODE_H
