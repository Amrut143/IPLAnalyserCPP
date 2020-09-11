#pragma once
#include <iostream>
using namespace std;

class IPLBatsmanDataCSV {

public:
    string player;
    int match;
    int innings;
    int run;
    string highScore;
    double avg;
    double strikeRate;
    int centuary;
    int halfCentuary;
    int fours;
    int six;

    public: 
    IPLBatsmanDataCSV() {}  
};