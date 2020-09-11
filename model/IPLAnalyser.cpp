#include <vector>
#include <list>
#include "MostRunsCSV.cpp"
#include "SortByField.cpp"
#include "../utility/CSVFileReader.cpp"
using namespace std;

class IPLAnalyser {
    list<IPLBatsmanDataCSV> batsmanList;

    public:
    list<IPLBatsmanDataCSV> loadIPLData(string filePath);
    list<IPLBatsmanDataCSV> getFieldWiseSortedPlayersRecord(list<IPLBatsmanDataCSV> batsmanList, SortType sortType);
};

list<IPLBatsmanDataCSV> IPLAnalyser::loadIPLData(string filePath) {
    CSVReader reader;
    list<vector<string>> mostRunCSVList = reader.readCSVFile(filePath);

    for(auto playerRecord = mostRunCSVList.begin(); playerRecord != mostRunCSVList.end(); playerRecord++){

        IPLBatsmanDataCSV batsman;
        batsman.player = playerRecord -> at(1);
        batsman.match = stoi(playerRecord -> at(2));
        batsman.run = stoi(playerRecord -> at(5));
        batsman.avg = stod(playerRecord -> at(7));
        batsman.strikeRate = stod(playerRecord -> at(9));
        batsman.fours = stoi(playerRecord -> at(12));
        batsman.six = stoi(playerRecord -> at(13));

        batsmanList.push_back(batsman);
    }
    return batsmanList;
}

list<IPLBatsmanDataCSV> IPLAnalyser::getFieldWiseSortedPlayersRecord(list<IPLBatsmanDataCSV> batsmanList, SortType sortType) {
    list<IPLBatsmanDataCSV> playerList(batsmanList.begin(), batsmanList.end());

    switch(sortType) {

        case BATTING_AVERAGE:
            playerList.sort([](const IPLBatsmanDataCSV firstBatsman, const IPLBatsmanDataCSV secondBatsman)
            {return firstBatsman.avg > secondBatsman.avg;});
            break;

        case STRIKE_RATE:
            playerList.sort([](const IPLBatsmanDataCSV firstBatsman, const IPLBatsmanDataCSV secondBatsman)
            {return firstBatsman.strikeRate > secondBatsman.strikeRate;});
            break;
    }        
    return playerList;
}