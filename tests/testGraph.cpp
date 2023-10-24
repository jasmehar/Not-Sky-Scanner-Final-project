
#include <catch2/catch_test_macros.hpp> 
#include <iostream>
#include "../code/src/airport.h"
#include "../code/src/graph.h"
#include "../code/src/routes.h"
#include <sstream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

TEST_CASE("data for airport 1 correctly stored in graph"){
  
    int V = 10;
    vector<pair<int, int> > adj[V];

    Routes routes;
    Graph testgraph;
    testgraph.addEdge(routes.GetSourceNumbers()[0],routes.GetDestinationNumbers()[0],routes.GetDistances()[0]);
   // testgraph.printGraph(routes.GetSourceNumbers()[0]);

}

TEST_CASE("index containing \\N skipped when storing airport 7"){
  
    int V = 10;
    vector<pair<int, int> > adj[V];

    Routes routes;
    Graph testgraph;
    testgraph.addEdge(routes.GetSourceNumbers()[7],routes.GetDestinationNumbers()[7],routes.GetDistances()[7]);
   // testgraph.printGraph(routes.GetSourceNumbers()[7]);
  //  cout<<"previous value skipped due to \\N"<<endl;

}

TEST_CASE("graph with size>1 constructed"){
  
    int V = 10;
    vector<pair<int, int> > adj[V];

    Routes routes;
    Graph testgraph;
    testgraph.addEdge(routes.GetSourceNumbers()[12],routes.GetDestinationNumbers()[12],routes.GetDistances()[12]);
     testgraph.addEdge(routes.GetSourceNumbers()[13],routes.GetDestinationNumbers()[13],routes.GetDistances()[13]);
      testgraph.addEdge(routes.GetSourceNumbers()[14],routes.GetDestinationNumbers()[14],routes.GetDistances()[17]);
   // testgraph.printGraph(routes.GetSourceNumbers()[12]);

}




