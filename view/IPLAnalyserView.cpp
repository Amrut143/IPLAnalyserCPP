#pragma once
#include <iostream>
#include <list>
#include "../model/MostRunsCSV.cpp"
using namespace std;

class IPLAnalyserView {

    public:
    IPLAnalyserView() {}

    void displayPlayerDetails(list<IPLBatsmanDataCSV> batsman) {
        int count = 0;
        for(auto playerRecord = batsman.begin(); count < 2; playerRecord++, count++) {
             cout << "\nPLAYERNAME: " << playerRecord -> player << "\nMATCH: " << playerRecord -> match 
                << "\nAVERAGE: " << playerRecord -> avg << "\nSTRIKE RATE: " << playerRecord -> strikeRate 
                << "\n4's: " << playerRecord -> fours << "\n6's: " << playerRecord -> six 
                << "\nRUNS: " << playerRecord -> run << endl;
        }
    }

     int getOptionToSortPlayers() {
        int option;

        cout << "\nSelect your choice accordingly to view batsman data. \n1.Players having top batting averages \n2.Players having top strikerate" 
            <<"\n3.Players having max 6's and 4's \n4.Players having best strikerate with 6's and 4's"
            << "\n5.Players having best average with best strikerate" 
            << "\n6.Players having highest run with best average \n7.Exit" << endl;

        cin >> option;
        return option;
    }
};