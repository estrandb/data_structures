#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>
#include "TreeNode.h"

template <typename T>
class BinaryHeap
{
    public:
        //0 == min, 1 == max
        BinaryHeap(int type);
        virtual ~BinaryHeap();

        void InsertNode(TreeNode<T> node);
        void DeleteTop();
        TreeNode<T> GetTop();

    protected:

    private:
        std::vector<TreeNode<T> > Tree;
        const int heapType;
        typedef sortType;

        void BubbleDown(uint32_t index);
        void BubbleUp(uint32_t index);
        void Heapify();
};

template<typename T>
BinaryHeap<T>::BinaryHeap(int type) : Tree(std::vector<TreeNode<T>()), heapType(type)
{
    //ctor
}

template<typename T>
BinaryHeap<T>::~BinaryHeap()
{
    //dtor
}

template<typename T>
BinaryHeap<T>::Heapify()
{
    int length = Tree.size();
    for(int i=length/2-1; i>=0; --i)
        BubbleDown(i);
}

template<typename T>
BinaryHeap<T>::GetTop()
{
    return Tree[0];
}

template<typename T>
void MinHeap::DeleteMin()
{
    int length = Tree.size();

    if(length == 0)
    {
        return;
    }

    Tree[0] = Tree[length-1];
    Tree.pop_back();

    BubbleDown(0);
}

template<typename T>
BinaryHeap<T>::InsertNode(TreeNode<T> node)
{
    uint32_t length = Tree.size();
    Tree.push_back(node);

    uint32_t postPushLength = Tree.size();
    Tree[postPushLength].sortByValue = postPushLength;

    BubbleUp(length);
}

template<typename T>
BinaryHeap<T>::BubbleUp(uint32_t index)
{
    if (index == 0)
    {
        return;
    }

    uint32_t parentIndex = (index-1)/2;

    if (heapType)
    {//max heap
        if (Tree[parentIndex].sortByValue < Tree[index].sortByValue)
        {
            auto temp = Tree[parentIndex];
            Tree[parentIndex] = Tree[index];
            Tree[index] = temp;
            Tree[index].sortByValue = index;
            Tree[parentIndex].sortByValue = parentIndex;
            BubbleUp(parentIndex);
        }
    }
    else
    {//min heap
        if (Tree[parentIndex].sortByValue > Tree[index].sortByValue)
        {
            auto temp = Tree[parentIndex];
            Tree[parentIndex] = Tree[index];
            Tree[index] = temp;
            Tree[index].sortByValue = index;
            Tree[parentIndex].sortByValue = parentIndex;
            BubbleUp(parentIndex);
        }
    }
}

template<typename T>
BinaryHeap<T>::BubbleDown(uint32_t index)
{
    uint32_t length = Tree.size();
    uint32_t rightChildIndex = 2*index + 2;
    uint32_t leftChildIndex = 2*index + 1;

    if (leftChildIndex >= length)
        return;//index is a leaf. already at bottom

    uint32_t minIndex = index;

    if (Tree[index].sortByValue > Tree[leftChildIndex].sortByValue)
    {
        minIndex = leftChildIndex;
    }

    if (rightChildIndex < length) && Tree[index].sortByValue > Tree[minIndex].sortByValue)
    {
        minIndex = rightChildIndex;
    }

    if(minIndex != index)
    {
        //need to swap
        auto temp = Tree[index];
        Tree[index] = Tree[minIndex];
        Tree[minIndex] = temp;
        BubbleDown(minIndex);
    }
}

#endif // BINARYHEAP_H
