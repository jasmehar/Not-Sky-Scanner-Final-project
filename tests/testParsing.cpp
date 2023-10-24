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


TEST_CASE("Parsing First Element", "[Edge Case 1]") {
    Routes test_routes;
    vector<Airport> test = test_routes.GetAirports();

    REQUIRE(test[1].getName() == "Goroka Airport");
    REQUIRE(test[1].getCity() == "Goroka");
    REQUIRE(test[1].getLat() == 145.391998291);
    REQUIRE(test[1].getLon() == -6.081689834590001);
    REQUIRE(test[1].getIATA() == "GKA");
}

TEST_CASE("Parsing Last Element", "[Edge Case 2]") {
    Routes test_routes;
    vector<Airport> test = test_routes.GetAirports();

    REQUIRE(test[14110].getName() == "Melitopol Air Base");
    REQUIRE(test[14110].getCity() == "Melitopol");
    REQUIRE(test[14110].getLat() == 35.305);
    REQUIRE(test[14110].getLon() == 46.880001);
    // string st = "\" + "N";
    REQUIRE(test[14110].getIATA() == "\\N");
}

TEST_CASE("Parsing Random", "[Middle Case 1]") {
    Routes test_routes;
    vector<Airport> test = test_routes.GetAirports();

    REQUIRE(test[641].getName() == "Harstad/Narvik Airport, Evenes");
    REQUIRE(test[641].getCity() == "Harstad/Narvik");
    REQUIRE(test[641].getLat() == 16.678100585938);
    REQUIRE(test[641].getLon() == 68.491302490234);
    // string st = "\" + "N";
    REQUIRE(test[641].getIATA() == "EVE");
}

TEST_CASE("Parsing Random", "[Middle Case 2]") {
    // Graph test_graph;
    // vector<Airport> test = test_graph.setVector();
    Routes test_routes;
    vector<Airport> test = test_routes.GetAirports();

    REQUIRE(test[2997].getName() == "Chhatrapati Shivaji International Airport");
    REQUIRE(test[2997].getCity() == "Mumbai");
    REQUIRE(test[2997].getLat() == 72.8678970337);
    REQUIRE(test[2997].getLon() == 19.0886993408);
    // string st = "\" + "N";
    REQUIRE(test[2997].getIATA() == "BOM");
}


TEST_CASE("Skips /N values", "[Routes = 1]") {
//test from 1 to 10 - this test must skip a /N value and all distances must be calculated 
    vector<int> ans_source_id;
    vector<int> ans_destination_id;
    vector<double> ans_distance;
    vector<double> test_distance; 

    Routes routes;

    vector<int> test_source_id = {2965,2966,2966,2968,2968,4029,4029,4029,6156,6156};
    vector<int> test_destination_id = {2990,2990,2962,2990,4078,2990,6969,6160,2952,2990};
    for(int i = 0; i< 10;i++ ){
        test_distance.push_back(routes.distance(test_source_id[i],test_destination_id[i]));
    }
    //{ 1410.3985310865, 698.9271709004, 570.2167546593, 1358.753027497, 2350.3060694337, 1264.0110818466, 1576.6803538014, 1656.5176917083, 1825.0159036461, 1466.0666625335 };

    for(int i; i<10; i++){
        ans_source_id.push_back(routes.GetSourceNumbers()[i]);
        ans_destination_id.push_back(routes.GetDestinationNumbers()[i]);
        ans_distance.push_back(routes.GetDistances()[i]);
    }

    // for(int i; i<10; i++){
    //     std::cout << routes.GetDistances()[i] <<endl;
    // }
   // std::cout << routes.GetDistances()[i] <<endl;

    REQUIRE(test_source_id == ans_source_id);
    REQUIRE(test_destination_id == ans_destination_id);
    REQUIRE(test_distance == ans_distance);
}

TEST_CASE("No extra values in any vector/ all the data has been parsed", "[Routes = 2]") {

    Routes routes;
    //std::cout << routes.GetSourceNumbers().size() <<endl;

    REQUIRE(routes.GetSourceNumbers().size() == routes.GetDestinationNumbers().size());
    REQUIRE(routes.GetDestinationNumbers().size() == routes.GetDistances().size());
    REQUIRE(routes.GetSourceNumbers().size() == routes.GetDistances().size());
}




