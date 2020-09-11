#include <vector>
#include <list>
#include "MostRunsCSV.cpp"
#include "../utility/CSVFileReader.cpp"
using namespace std;

class IPLAnalyser {
    list<IPLBatsmanDataCSV> batsmanList;

    public:
    void loadIPLData(string filePath);
    list<IPLBatsmanDataCSV> getSortedPlayerAsPerBattingAvg();
};

void IPLAnalyser::loadIPLData(string filePath) {
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
}

list<IPLBatsmanDataCSV> IPLAnalyser::getSortedPlayerAsPerBattingAvg() {
    batsmanList.sort([](const IPLBatsmanDataCSV firstBatsman, const IPLBatsmanDataCSV secondBatsman)
    {return firstBatsman.avg > secondBatsman.avg;});
    
    return batsmanList;
}