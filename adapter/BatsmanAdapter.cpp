#pragma once
#include <list>
#include "IPLAdapter.cpp"
#include "../model/IPLRecordDao.cpp"
#include "../utility/CSVFileReader.cpp"

using namespace std;

class BatsmanAdapter : public IPLAdapter {

    public:
    list<IPLRecordDAO> loadIPLData(string filePath) {
        CSVReader reader;
        list<IPLRecordDAO> playersList;
        list<vector<string>> mostRunsCSVList = reader.readCSVFile(filePath);

        for (auto playersRecord = mostRunsCSVList.begin(); playersRecord != mostRunsCSVList.end(); playersRecord++) {
            IPLRecordDAO batsman;
            batsman.player = playersRecord -> at(1);
            batsman.batsmanRun = stoi(playersRecord -> at(5));
            batsman.battingAverage = stod(playersRecord -> at(7));
            batsman.strikeRate = stod(playersRecord -> at(9));
            batsman.fours = stoi(playersRecord -> at(12));
            batsman.sixes = stoi(playersRecord -> at(13));
            batsman.century = stoi(playersRecord -> at(10));
            batsman.fifties = stoi(playersRecord -> at(11));

            playersList.push_back(batsman);
        }
        return playersList;
    }
};