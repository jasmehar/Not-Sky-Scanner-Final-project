## Leading Question 

The data set that we have decided to use is the Open Flights database, which is an open-source data set of flight routes and airports. We plan to use this data to create a directed graph and use the distance between two airports as the weight for the edges. Finally, we will use this data to determine the shortest distance between any two airports using Dijkstra's algorithm. Note that only those paths will be considered where an actual airline route operates. 

## Dataset Acquisition

What does the dataset contain and what will it mean for our graph?

We will be using the openFlights database which contains more than 10,000 airports spanning the globe, last updated in 2017. We will be using the airports.dat which has the latitude and longitude data points using which we will calculate the distances between 2 different airports. These airports will be the nodes in our graph and the distances will act as the weight of the edges of the graph.

We will also be using routes.dat which was last updated in 2014, whose Database contains 67663 routes between 3321 airports on 548 airlines spanning the globe. Here the routes are directional which will be stored twice. We will be using this dataset to map out which current routes are currently viable and these routes will be the edges of the graph.


## Data Format

The dataset is all comma separated values for each of the entries. Each entry in the airports.dat dataset consists of 14 parts however we will only be using :

* a specific OpenFlights identifier
* the airport name
* the city name
* the country the airport is located in
* the airport's latitude, longitude, and Altitude (this will affect the path distance)
* the type of station (for our dataset the type will always be airport).

As for each of the entries in the routes.dat dataset consists of 9 parts, however, we will only be using:
* an airline code
* an OpenFlights airline identifier
* an OpenFlights airport identifier for the source airport (this is what connects both of the databases)
* an OpenFlights airport identifier for the destination airport
* the number of stops on the flight


## Data Correction

As a part of our correction process, we will remove all the unnecessary data that we do not need from the final vectors we store our data in the respective vectors. We will remove the unnecessary data by making a loop and skipping specific indexes with data we don’t need. 


## Data Storage

We will process the airports.dat data and store it as a -
* Vector<Airport ID, Name, City, Country, Latitude, Longitude, Altitude, Type>


For the routes.dat we will store it as - 
* Vector<Airline, Airline ID, Source Airport, Source Airport ID, Destination Airport, Destination Airport ID, Codeshare, Stops, Equipment>


Time taken for the method to run?
* This storage method will take $O(n)$ time to run, with n being the number of entries from the dataset.


## Algorithm 

We will be implementing 3 algorithms: to perform a traversal, to calculate the shortest path between nodes and finally, a complex algorithm. 

* Traversal Algorithm: To traverse our graph, we plan to use the Breadth First Search (BFS) algorithm to go through the nodes. Every node is equivalent to an airport whose data (its respective latitude and longitude) has been obtained from the airports.dat dataset, and each edge is represented by the routes between the airports. The time complexity of this algorithm is expected to be $O(E+N)$, where $E$= number of edges and $N$= number of nodes. 
* Shortest Path Algorithm: To find the shortest path between any two nodes in the graph, we will use Dijkstra's Algorithm. This will enable us to find the shortest path between weighted edges. To calculate the weight of the edges, we will use the airport data to compute the distance and use that as the weight. The algorithm works by building a set of nodes that have a minimum distance from the source. However, to ensure our approach succeeds, we need to have only positive weights in the graph. The timing complexity of the algorithm is expected to be $O(|E| + |V|\log{|V|})$

* Betweenness Centrality: Betweenness centrality is a method used to measure the centrality of a node is a graph. Centrality is essentially a measure of how important a node is in a graph. Betweenness centrality in particular uses the shortest distance between nodes to assign this value to the nodes. Any two nodes in a graph will have the shortest distance which is the minimum sum of the weighted edges.  The input to our function will be a weighted graph. The function will calculate the number of shortest paths that use a particular node for every node in the graph. This is then scaled to get a value between a range (Ex. 0 - 1) using the nodes with the minimum and maximum score. We will use this information to return the vector of centrality score for every airport to help answer questions like which is the most trafficked airport in the world. The function will involve finding the shortest paths between all possible pairs of nodes. We will use the Floyd-Warshall Algorithm to find this and so the time complexity should be $O(n^3)$ whereas the space complexity depends on accessing our graph representation and will be $O(n^2)$.



## Timeline
* Week 1: Nov 2 to Nov 8: complete data parsing and set up files in the GitHub repository, start work on BFS

* Week 2: Nov 9 to Nov 15: complete BFS, start work on Dijkstra's algorithm

* Mid-Project Checkin: demonstrate a working BFS algorithm and finished data parsing to mentor

* Week 3: Nov 16 to Nov 22: work on Dijkstra's algorithm

* Week 4: Nov 23 to Nov 29: complete Dijkstra's algorithm

* Week 5: Nov 30 to Dec 7: complete betweenness centrality algorithm, finish report and video presentation.
Submit deliverables before December 8
