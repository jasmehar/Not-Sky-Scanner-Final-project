#pragma once
#include <string>
#include <vector>

using namespace std; 

class Airport {
    private:

    string name;
    string city;
    double lat;
    double lon;
    string IATA;

    public:

    Airport();     

    string getName();
    string getCity();
    double getLat();
    double getLon();
    string getIATA();

    void setName(string input);
    void setCity(string input);
    void setIATA(string input);
    void setLon(double input);
    void setLat(double input);

    void printAirport();



};

