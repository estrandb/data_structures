#include <iostream>
#include "BinaryHeap.h"
#include "AdjListNode.h"
#include "Utilities.h"

int main()
{
    auto binheap = new BinaryHeap<AdjListNode>(0);

    std::string const filePath = "/home/sig/projects/algorithms/graph.txt";
    int const numVertices = 200;
    int const source_vert = 0;

    std::vector<std::vector<uint32_t> > vertices;

    std::unique_ptr<Utilities> util(new Utilities());
    util->AdjLengthListToVec(vertices, filePath);
    //util->PrintAdjList(vertices, numVertices);

    std::vector<uint32_t> processedVertices;
    uint32_t computedShortestPaths[200] = {0};

    uint32_t current_vert = source_vert;

    while (processedVertices.size() != vertices.size())
    {
        processedVertices.push_back(current_vert);
        for (int i = 0; i < processedVertices.size(); i++)
        {
            if ((i%2) == 0)
            {
                /*
                take each vertex in processedVertices and find edge going to vertices
                calculate dijkstra criterion and store that into heap
                */


            }
        }

    }


    return 0;
}
