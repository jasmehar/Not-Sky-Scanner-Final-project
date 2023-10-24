#include <iostream>
#include "../src/airport.h"
#include "../src/graph.h"
#include <sstream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<Airport> setVector();

int main() {
    
    std::cout << "Main is working" << std::endl;
    
    Graph test_graph;
    test_graph.addAllEdges();
    test_graph.printGraph(2966);
    //test_graph.Dijkstra(2966,2990);
     int node = 3000;
    vector< pair<int, int> > dp = test_graph.Dijkstra(node,3300);
    test_graph.PrintShortestPath(dp,node,3300);
  

// //test to see value stored correctly in vertex of graph
//     testgraph.addEdge(routes.GetSourceNumbers()[0],routes.GetDestinationNumbers()[0],routes.GetDistances()[0]);

//     testgraph.printGraph(routes.GetSourceNumbers()[0]);

//     //test for skipping value with \N
// testgraph.addEdge(routes.GetSourceNumbers()[7],routes.GetDestinationNumbers()[7],routes.GetDistances()[7]);
//   testgraph.printGraph(routes.GetSourceNumbers()[7]);
//     cout<<"previous value skipped due to \\N"<<endl;


//     //test for multiple edges
//     testgraph.addEdge(routes.GetSourceNumbers()[12],routes.GetDestinationNumbers()[12],routes.GetDistances()[12]);
//      testgraph.addEdge(routes.GetSourceNumbers()[13],routes.GetDestinationNumbers()[13],routes.GetDistances()[13]);
//       testgraph.addEdge(routes.GetSourceNumbers()[14],routes.GetDestinationNumbers()[14],routes.GetDistances()[17]);
//       testgraph.printGraph(routes.GetSourceNumbers()[12]);


    return 0;
} 
