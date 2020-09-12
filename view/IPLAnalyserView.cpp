#pragma once
#include <iostream>
#include <list>
#include "../model/IPLRecordDao.cpp"
using namespace std;

class IPLAnalyserView {

    public:
    IPLAnalyserView() {}

    void displayBatsmanDetails(list<IPLRecordDAO> batsman) {
        int count = 0;
        for(auto playerRecord = batsman.begin(); count < 2; playerRecord++, count++) {
             cout << "\nPLAYERNAME: " << playerRecord -> player << "\nMATCH: " << playerRecord -> match 
                << "\nAVERAGE: " << playerRecord -> battingAverage << "\nSTRIKE RATE: " << playerRecord -> strikeRate 
                << "\n4's: " << playerRecord -> fours << "\n6's: " << playerRecord -> sixes 
                << "\nRUNS: " << playerRecord -> batsmanRun << "\n100'S: " << playerRecord -> century 
                << "\n50'S: " << playerRecord -> fifties << endl;
        }
    }

    void displayBowlerDetails(list<IPLRecordDAO> bowler) {
        int count = 0;
        for (auto playerRecord = bowler.begin(); count < 2 ; playerRecord++, count++) {
            cout << "\nPLAYERNAME: " << playerRecord -> player << "\nMATCH: " << playerRecord -> match
                << "\nAVERAGE: " << playerRecord -> bowlingAverage << "\nSTRIKE RATE: " << playerRecord -> strikeRate
                << "\nWICKETS: " << playerRecord -> wkts << "\n4'w: " << playerRecord -> fourWkts 
                << "\n5'w: " << playerRecord -> fiveWkts << "\nECONOMY RATE: " << playerRecord -> economy << endl;
        }   
    }

    void displayAllRounderDetails(list<IPLRecordDAO> allrounder) {
    int count = 0;
    for (auto playerRecord = allrounder.begin(); count < 2 ; playerRecord++ , count++) {
        cout << "\nPLAYERNAME: " << playerRecord -> player << "\nBATTING AVERAGE: " << playerRecord -> battingAverage 
            << "\nBOWLING AVERAGE: " << playerRecord -> bowlingAverage << "\nWICKETS: " << playerRecord -> wkts 
            << "\nRUNS: " << playerRecord -> batsmanRun << endl;
    }   
}


     int getOptionToSortPlayers() {
        int option;

        cout << "\nSelect your choice accordingly to view batsman data. \n1.Players having top batting averages \n2.Players having top strikerate" 
            <<"\n3.Players having max 6's and 4's \n4.Players having best strikerate with 6's and 4's"
            << "\n5.Players having best average with best strikerate" 
            << "\n6.Players having highest run with best average" 
            << "\n7.Players having top bowling average \n8.Players having top bowling strikerate"
            << "\n9.Players having best economy \n10.Players having best strikerate with 5'w and 4'w"
            << "\n11.Player having best bowling average with best strikerate"
            << "\n12.Player having most wickets with best average \n13.Player having best batting and bowling average"
            << "\n14.Player having most runs and wickets \n15.Player having most 100 with best batting average"
            << "\n16.Exit" << endl;

        cin >> option;
        return option;
    }
};