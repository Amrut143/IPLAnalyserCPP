#pragma once
#include <list>
#include "IPLAdapter.cpp"
#include "../model/IPLRecordDao.cpp"
#include "../utility/CSVFileReader.cpp"

using namespace std;

class BowlerAdapter : public IPLAdapter {

    public:
    list<IPLRecordDAO> loadIPLData(string filePath) {
        CSVReader reader;
        list<IPLRecordDAO> playersList;
        list<vector<string>> mostWktsCSVList = reader.readCSVFile(filePath);

        for (auto playersRecord = mostWktsCSVList.begin(); playersRecord != mostWktsCSVList.end(); playersRecord++) {
            IPLRecordDAO bowler;
            bowler.player = playersRecord -> at(1);
            bowler.wkts = stoi(playersRecord -> at(6));
            bowler.bowlingAverage = stod(playersRecord -> at(8));
            bowler.economy = stod(playersRecord -> at(9));
            bowler.strikeRate = stod(playersRecord -> at(10));
            bowler.fourWkts = stoi(playersRecord -> at(11));
            bowler.fiveWkts = stoi(playersRecord -> at(12));

            playersList.push_back(bowler);
        }
        return playersList;
    }
};