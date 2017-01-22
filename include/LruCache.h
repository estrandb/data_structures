#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <stdint.h>
#include <unordered_map>
#include <queue>

#include "LruNode.h"

template <typename T>
class LruCache
{
    public:
        LruCache(uint16_t _cacheSize) : CacheSize(_cacheSize) {}
        virtual ~LruCache();

        T Reference(uint32_t key);


    protected:

    private:
        uint16_t CacheSize;

        std::unordered_map<uint32_t, LruNode<T>* > CacheMap;
        std::queue<LruNode<T> > CacheQ;

        T Get(uint32_t Key);
        void Set(T data);
};

template <typename T>
T LruCache<T>::Reference(uint32_t key)
{

}
#endif // LRUCACHE_H
