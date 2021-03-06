#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <stdint.h>
#include <unordered_map>
#include <list>

#include "LruNode.h"

template <typename T>
class LruCache
{
    public:
        LruCache(uint16_t _cacheSize) : CacheSize(_cacheSize), CacheQ(std::list<LruNode<T>(_cacheSize)) {CacheMap->reserve(_cacheSize);}
        virtual ~LruCache();

        T Reference(uint32_t key);

    protected:

    private:
        uint16_t CacheSize;

        std::unordered_map<uint32_t, LruNode<T>* > CacheMap;
        std::list<LruNode<T> > CacheQ;

        T Get(uint32_t Key);
        void Set(T data);
};

template <typename T>
T LruCache<T>::Reference(LruNode<T> node)
{
    if (node.Key == null)
        return;

    T data = nullptr;

    //at this point data integrity within a node is the responsibility of the user, we're just keeping track of node usage
    if (CacheMap->count(node.Key) > 0)
    {//cache hit
        CacheQ->erase(CacheMap->at(node.Key));
        CacheQ->push_front(node);
        CacheMap->at(node.Key) = CacheQ->begin();
    }
    else if (CacheMap->count(node.Key) == 0)
    {//cache miss
        if (CacheQ->size() == CacheSize)
        {
            LruNode leastNode = CacheQ->back();
            CacheQ->pop_back();
            CacheQ->push_front(node);
            CacheMap->erase(leastNode.Key);
            CacheMap->insert(std::make_pair(node.Key, CacheQ->begin()));
        }
        else
        {
            CacheQ->push_front(node);
            CacheMap->insert(std::make_pair(node.Key, CacheQ->begin()));
        }
    }

}
#endif // LRUCACHE_H
