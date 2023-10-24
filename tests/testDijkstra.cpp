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

TEST_CASE("Dijkstra can find the airport shortest distance", "[Dijkstra]") {
    Graph test_graph;
    test_graph.addAllEdges();
    vector< pair<int, int> > dp = test_graph.Dijkstra(2965,2990);
    int ans = 1410;
    int out = dp[2990].first;

    REQUIRE(ans == out);
}

TEST_CASE("Dijkstra can find the airport shortest distance (path does not exist)", "[Dijkstra]") {
    Graph test_graph;
    test_graph.addAllEdges();
    vector< pair<int, int> > dp = test_graph.Dijkstra(0,3300);
    int ans = 1000000007;
    int out = dp[2990].first;

    REQUIRE(ans == out);
}

TEST_CASE("Dijkstra can find the airport shortest distance (direct path)", "[Dijkstra]") {
    Graph test_graph;
    test_graph.addAllEdges();
    vector< pair<int, int> > dp = test_graph.Dijkstra(2965,2990);
    vector<int> ans = {2965};
    vector<int> out;
    int currnode = 2990;
    while(currnode != 2965)
    {
    currnode = dp[currnode].second;
    out.push_back(currnode);
    }

    REQUIRE(ans == out);
}

TEST_CASE("Dijkstra can find the airport shortest distance (not direct path but one exists)", "[Dijkstra]") {
    Graph test_graph;
    test_graph.addAllEdges();
    vector< pair<int, int> > dp = test_graph.Dijkstra(3000,3300);
    vector<int> ans = {3408, 3273,3304,3131,3000};
    vector<int> out;
    int currnode = 3300;
    while(currnode != 3000)
    {
    currnode = dp[currnode].second;
    out.push_back(currnode);
    }

    REQUIRE(ans == out);
}

TEST_CASE("Dijkstra can find the airport shortest distance (no path exists)", "[Dijkstra]") {
    Graph test_graph;
    test_graph.addAllEdges();
    vector< pair<int, int> > dp = test_graph.Dijkstra(0,3300);
    vector<int> ans = {3300,3300,3300,3300};
    vector<int> out;
    int currnode = 3300;
    for(int i =0; i<4; i++)//this is limited since this is a recurring loop
    {
    currnode = dp[currnode].second;
    out.push_back(currnode);
    }

    REQUIRE(ans == out);
}