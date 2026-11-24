#include "MatrixGraph.h"

using namespace std;

MatrixGraph::MatrixGraph(bool type, int size) : Graph(type, size), m_Mat(size, vector<Weight>(size, 0))
{

}

void MatrixGraph::getAdjacentEdges(int vertex, Adjacent* result) const
{

}

void MatrixGraph::getAdjacentEdgesDirect(int vertex, Adjacent* result) const
{

}

Weight MatrixGraph::getEdgeWeight(int from, int to) const
{

}

bool MatrixGraph::insertEdge(int from, int to, Weight weight)
{
	m_Mat[from][to] = weight;
}

bool MatrixGraph::printGraph(ostream* output) const
{
	*output << "   ";
	for(int i=0; i<m_Size; i++) *output << " [" << i << "]";
	*output << endl;

	for (int i = 0; i < m_Size; i++) {
		*output << "[" << i << "]";
		for (int j = 0; j < m_Size; j++) *output << " " << m_Mat[i][j];
		*output << endl;
	}
}

