#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <stdint.h>

template <typename T>
class LruCache
{
    public:
        LruCache();// : Cache(/*hashmap<LruNode<T> >()*/);
        virtual ~LruCache();

        T Get(uint32_t Key);
        void Set(T data);

    protected:

    private:
        /*hashmap<LruNode<T> > Cache; */
};

#endif // LRUCACHE_H
