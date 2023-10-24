//Graphs Class

#include "Routes.h"
#include "Graph.h"
#include <math.h> 
#include <float.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>


using namespace std;


//construct the vertices 
//such that each airport object is connected with its ID
Graph::Graph() {
    Routes routes = Routes();
    routes_ = routes;
    std::vector<std::pair<int, long double>> row = {};
    std::vector<std::vector<std::pair<int, long double>>> adjList(routes.GetAirports().size(), row);
    adjList_ = adjList;
}

Graph::Graph(string routesFile, string airportsFile) {
    Routes routes = Routes(routesFile, airportsFile);
    routes_ = routes;
    std::vector<std::pair<int, long double>> row = {};
    std::vector<std::vector<std::pair<int, long double>>> adjList(routes.GetAirports().size(), row);
    adjList_ = adjList;
}

/*
Adds a single edge to the Adjacency List representation of the Graph
source_number is the OpenFlights ID for the Source Airport
destination_number is the OpenFlights ID for the Destination Airport
distance is the calculated distance between them
Note that the function only add an edge from source number to destination number since the graph is directed
*/
void Graph::addEdge(int source_number, int destination_number, long double distance) {
    bool exist = false;
    for (int i = 0; i < adjList_[source_number].size(); i++) {
        if ((adjList_[source_number][i].first == destination_number) && (adjList_[source_number][i].second == distance)) {
            exist = true;
        }
    }
    if (!exist) adjList_[source_number].push_back(make_pair(destination_number, distance));
}

/*
Adds all edges from the Route class that has been initialized to the Adjacency List
*/
void Graph::addAllEdges(){
    for(int i = 0; i< routes_.GetDestinationNumbers().size(); i++){
        int source_number = routes_.GetSourceNumbers()[i]; //gives the index of the source airport as in the airport vector (i is the index per line)
        int dest_number = routes_.GetDestinationNumbers()[i]; //gives the index of the destination as in the airport vector (i is the index per line)
        long double distance = routes_.GetDistances()[i]; //distance between the airports (i is index per line)
        addEdge(source_number, dest_number, distance);
    }
}

/*
The function prints a visual representation of the graph for a given node
source_number is the OpenFlights ID for the Source Airport
The function prints to standard out all the Airports connected to the input airport along with their distance
*/
void Graph::printGraph(int source_number) {
    if (adjList_[source_number].size() == 0) { // Checks if the provided source number is a given airport
        std::cout << "Airport does not exist" << std::endl;
        return;
    }
    cout << "Source Airport " << routes_.GetAirports()[source_number].getName() << " is connected to \n";
    for (auto it = adjList_[source_number].begin(); it!=adjList_[source_number].end(); it++)
    {
        int v = it->first;
        long double w = it->second;
        cout << "\tDestination " << routes_.GetAirports()[v].getName() << " with distance: " << w << "\n";
    }
    cout << "\n";
    std::cout << "NUMBER OF EDGES: " << adjList_[source_number].size() << std::endl;
}

/* 
The function implements a BFS traversal through the graph with the airport at the given source number Airport
source_number is the OpenFlights ID for the Source Airport
Returns a vector of Airports Names which highlighted the path traversed in a breath first manner
*/
std::vector<std::string> Graph::BFS(int source_number) {
    if (adjList_[source_number].size() == 0) { // Checks if the provided source number is a given airport
        std::cout << "Airport does not exist" << std::endl;
        return {};
    }
    std::queue<int> queue;
    std::vector<bool> visited(adjList_.size(), false);
    queue.push(source_number);
    visited[source_number] = true;
    std::vector<std::string> path;

    while (!queue.empty()) {
        int source_airport = queue.front();
        path.push_back(routes_.GetAirports()[source_airport].getName());
        queue.pop();
        std::vector<std::pair<int, long double>> neighbours = adjList_[source_airport];
        for (std::pair<int, long double>& neighbour: neighbours) {
            if (!visited[neighbour.first]) {
                queue.push(neighbour.first);
                visited[neighbour.first] = true;
            }
        }
    }
    return path;
}



//error it is deleting something that is already there
vector< pair<int, int> > Graph::Dijkstra(int start,int destination)
    {
    //cout << "\nGetting the shortest path from " << start << " to all other nodes.\n";
    vector<pair<int, int> > dist; // First int is dist, second is the previous node. 
    
    int n = adjList_.size();// Initialize all source->vertex as infinite.
    for(int i = 0; i < n; i++)
        {
        dist.push_back(make_pair(1000000007, i)); // Define "infinity" as necessary by constraints.
        }
        
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > priorityQ;// Create a Priority Q.
    
    priorityQ.push(make_pair(start, 0));
    dist[start] = make_pair(0, start);;
    
    while(priorityQ.empty() == false)// While priorityQ isn't empty
        {
        int u = priorityQ.top().first;// Get min distance vertex from priorityQ which is u
        priorityQ.pop();
        
        
        for(int i = 0; i < adjList_[u].size(); i++)// Visit all of u's neighbours
            {
            int v = adjList_[u][i].first;
            int weight = adjList_[u][i].second;
            
            // If the distance to v is shorter by going through u...
            if(dist[v].first > dist[u].first + weight)
                {
                // Update the distance of v.
                dist[v].first = dist[u].first + weight;
                // Update the previous node of v.
                dist[v].second = u;
                priorityQ.push(make_pair(v, dist[v].first));// Insert v into the priorityQ. 
                }
            }
        }
    //PrintShortestPath(dist,start,destination);
    return dist;
    }
    
void Graph::PrintShortestPath(vector< pair<int, int> > dist, int start,int destination)
    {
    //cout << "\nPrinting the shortest paths for node " << start << ".\n";
        if(dist[destination].first == 1000000007){
            cout<<"Oops it looks like there is no path"<< endl;
        }
        else{
        cout << "The distance from node " << start << " to node " << destination << " is: " << dist[destination].first << endl;
        
        int currnode = destination;
        cout << "The path is: " << currnode;
        int count;
        while(currnode != start)
            {
            currnode = dist[currnode].second;
            cout << " <- " << currnode;
            }
        cout << endl << endl;
        }
    }
    