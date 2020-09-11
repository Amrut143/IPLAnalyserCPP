#pragma once
#include <iostream>
#include <list>
#include "../model/MostRunsCSV.cpp"
using namespace std;

class IPLAnalyserView {

    public:
    IPLAnalyserView() {}

    void displayTopAvgBatsmanDetails(list<IPLBatsmanDataCSV> batsman) {
        int count = 0;
        for(auto playerRecord = batsman.begin(); count < 5; playerRecord++, count++) {
             cout << "\nPLAYERNAME: " << playerRecord -> player << "\nMATCH: " << playerRecord -> match 
                << "\nAVERAGE: " << playerRecord -> avg << "\nSTRIKE RATE: " << playerRecord -> strikeRate 
                << "\n4's: " << playerRecord -> fours << "\n6's: " << playerRecord -> six << endl;
        }
    }
};