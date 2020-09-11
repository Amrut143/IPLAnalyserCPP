#include <vector>
#include <list>
#include "../adapter/IPLAdapterFactory.cpp"
#include "../utility/SortByField.cpp"
#include "../utility/PlayerType.cpp"
#include "../utility/CSVFileReader.cpp"
using namespace std;

class IPLAnalyser {
    list<IPLRecordDAO> batsmanList;
    list<IPLRecordDAO> bowlerList;

    public:
    void loadIPLData(string filePath, PlayerType playerType);
    list<IPLRecordDAO> getFieldWiseSortedPlayersRecord(SortType sortType);
};

void IPLAnalyser::loadIPLData(string filePath, PlayerType playerType) {
    IPLAdapterFactory factory;

    switch(playerType) {

        case BATSMAN:
            batsmanList = factory.getIPLData(filePath, playerType);
            break;

        case BOWLER:
            bowlerList = factory.getIPLData(filePath, playerType);
            break;
    }
}

list<IPLRecordDAO> IPLAnalyser::getFieldWiseSortedPlayersRecord(SortType sortType) {
    list<IPLRecordDAO> playerList;

    switch(sortType) {

        case BATTING_AVERAGE:
            playerList = batsmanList;
            playerList.sort([](const IPLRecordDAO firstBatsman, const IPLRecordDAO secondBatsman)
            {return firstBatsman.battingAverage > secondBatsman.battingAverage;});
            break;

        case STRIKE_RATE:
            playerList = batsmanList;
            playerList.sort([](const IPLRecordDAO firstBatsman, const IPLRecordDAO secondBatsman)
            {return firstBatsman.strikeRate > secondBatsman.strikeRate;});
            break;

        case SIX_AND_FOURS:
            playerList = batsmanList;
            playerList.sort([](const IPLRecordDAO firstBatsman, const IPLRecordDAO secondBatsman)
            {return ((firstBatsman.fours * 4) + (firstBatsman.sixes * 6)) > ((secondBatsman.fours * 4) + (secondBatsman.sixes * 6)); });
            break;

        case SIX_AND_FOURS_WITH_STRIKERATE:
            playerList = batsmanList;
            playerList.sort([](const IPLRecordDAO firstBatsman, const IPLRecordDAO secondBatsman)
            {return firstBatsman.strikeRate > secondBatsman.strikeRate && 
            ((firstBatsman.fours * 4) + (firstBatsman.sixes * 6 )) > ((secondBatsman.fours * 4) + (secondBatsman.sixes * 6)); });
            break;

        case BAT_AVG_WITH_STRIKERATE:
            playerList = batsmanList;
            playerList.sort([](const IPLRecordDAO firstBatsman, const IPLRecordDAO secondBatsman)
            {return firstBatsman.battingAverage > secondBatsman.battingAverage && firstBatsman.strikeRate > secondBatsman.strikeRate;});
            break;

        case BAT_RUN_WITH_AVG:
            playerList = batsmanList;
            playerList.sort([](const IPLRecordDAO firstBatsman, const IPLRecordDAO secondBatsman)
            {return firstBatsman.batsmanRun > secondBatsman.batsmanRun && firstBatsman.battingAverage > secondBatsman.battingAverage;});
            break;

        case BOWLING_AVG:
            playerList = bowlerList;
            playerList.sort([](const IPLRecordDAO firstBowler, const IPLRecordDAO secondBowler)
            {return (firstBowler.bowlingAverage != 0 && secondBowler.bowlingAverage != 0) ? firstBowler.bowlingAverage < secondBowler.bowlingAverage : bool(); });
            break;

        case BOWL_STRIKERATE:
            playerList = bowlerList;
            playerList.sort([](const IPLRecordDAO firstBowler, const IPLRecordDAO secondBowler)
            {return (firstBowler.strikeRate != 0 && secondBowler.strikeRate != 0) ? firstBowler.strikeRate < secondBowler.strikeRate : bool(); });
            break;    
    }   

    return playerList;
}