#include "airport.h"
#include "vector"
#include <iostream>

using namespace std;

Airport::Airport() {
    name = "UNKNOWN";
    city = "UNKNOWN";
    IATA = "UNKNOWN";
    lon = 0;
    lat = 0;

}

string Airport:: getName() {
    return name;
}
string Airport::getCity() {
    return city;
}
double Airport::getLat() {
    return lat;
}
double Airport:: getLon() {
    return lon;
}
string Airport::getIATA() {
    return IATA;
}

void Airport::setName(string input) {
    name = input;
}
void Airport::setCity(string input) {
    city = input;
}
void Airport::setIATA(string input) {
    IATA = input;
}
void Airport::setLon(double input) {
    lon = input;
}
void Airport::setLat(double input) {
    lat = input;
}

void Airport::printAirport() {
    cout << "The Current Airport is " << name << " located in " << city << " which is latitude = " << lat << " and longitude = " << lon << " The IATA Code is " << IATA << endl;
}
