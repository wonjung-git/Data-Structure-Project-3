#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(bool type, int size) : Graph(type, size), m_List(size)
{

}

void ListGraph::getAdjacentEdges(int vertex, Adjacent* result) const
{

}

void ListGraph::getAdjacentEdgesDirect(int vertex, Adjacent* result) const
{

}

Weight ListGraph::getEdgeWeight(int from, int to) const
{

}

bool ListGraph::insertEdge(int from, int to, Weight weight)
{
	m_List[from][to] = weight;
}

bool ListGraph::printGraph(ostream* output) const
{
    for (int i = 0; i < m_Size; i++) {
        *output << "[" << i << "]";

        // adjacent node empty
        if (m_List[i].empty()) {
            *output << " ->";
        }
        else {
            Adjacent::const_iterator it;
            for (it = m_List[i].begin(); it != m_List[i].end(); it++) {
                int to = it->first;    // to node
                int w = it->second;   // weight

                //print
                *output << " -> (" << to << "," << w << ")";
            }
            *output << endl;
        }
    }
    return 1;
}

