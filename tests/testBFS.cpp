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

TEST_CASE("BFS Test Case 1", "[BFS]") {
    Graph test_graph = Graph("../data/testRoutes.dat","../data/testAirports.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(100);
    std::vector<std::string> expected = {"Arya Airport", "Athish Airport", "Mount Hagen Kagamuga Airport", "Nadzab Airport"};

    REQUIRE(temp == expected);
}

TEST_CASE("BFS Test Case 2", "[BFS]") {
    Graph test_graph = Graph("../data/testRoutes.dat","../data/testAirports.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(3500);
    std::vector<std::string> expected = {"Nadzab Airport"};

    REQUIRE(temp == expected);
}

TEST_CASE("BFS Test Case 3", "[BFS]") {
    Graph test_graph = Graph("../data/testRoutes.dat","../data/testAirports.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(45);
    std::vector<std::string> expected = {};

    REQUIRE(temp == expected);
}

TEST_CASE("BFS Test Case 4", "[BFS]") {
    Graph test_graph = Graph("../data/testRoutes.dat","../data/testAirports.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(42);
    std::vector<std::string> expected = {"Lonely Airport"};

    REQUIRE(temp == expected);
}

TEST_CASE("BFS Test Case 5", "[BFS]") {
    Graph test_graph = Graph("../data/testRoutes.dat","../data/testAirports.dat");
    test_graph.addAllEdges();
    vector<string> temp = test_graph.BFS(250);
    std::vector<std::string> expected = {"Athish Airport", "Mount Hagen Kagamuga Airport", "Nadzab Airport"};

    REQUIRE(temp == expected);
}
