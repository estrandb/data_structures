#include <iostream>
#include "BinaryHeap.h"
#include "AdjListNode.h"

using namespace std;

int main()
{
    auto binheap = new BinaryHeap<AdjListNode>(0);

    for (int i = 0 ; i < 10 ; i++)
    {
        auto node = new AdjListNode();
        auto treeNode = new TreeNode<AdjListNode>();

        node->dest[i] = i+1;
        node->weight[i] = 20;

        treeNode->data = *node;
        treeNode->sortByValue = i;//djikstras greedy criteria for nodes we haven't looked at yet, V

        binheap->InsertNode(*treeNode);
    }

    return 0;
}
