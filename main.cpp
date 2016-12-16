#include <iostream>
#include "BinaryHeap.h"
#include "AdjListNode.h"

using namespace std;

int main()
{
    auto binheap = new BinaryHeap<AdjListNode>(0);
    auto node = new AdjListNode();
    auto treeNode = new TreeNode<AdjListNode>();

    node->dest[0] = 1;
    node->weight[0] = 20;

    treeNode->data = *node;
    treeNode->sortByValue = node->dest[0];

    binheap->InsertNode(*treeNode);

    return 0;
}
