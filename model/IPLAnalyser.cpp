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
    list<IPLRecordDAO> getAllRounderData(list<IPLRecordDAO> batsman, list<IPLRecordDAO> bowler);
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

list<IPLRecordDAO> IPLAnalyser::getAllRounderData(list<IPLRecordDAO> batsman, list<IPLRecordDAO> bowler) {
    list<IPLRecordDAO> playersList;

    for (auto batsmanRecord = batsman.begin(); batsmanRecord != batsman.end(); batsmanRecord++) {

        for(auto bowlerRecord = bowler.begin(); bowlerRecord != bowler.end(); bowlerRecord++) {
            if(batsmanRecord -> player == bowlerRecord -> player) {
                IPLRecordDAO allRounder;
                allRounder.player = bowlerRecord -> player;
                allRounder.batsmanRun = batsmanRecord -> batsmanRun;
                allRounder.battingAverage = batsmanRecord -> battingAverage;
                allRounder.bowlingAverage = bowlerRecord -> bowlingAverage;
                allRounder.bowlerRun = bowlerRecord -> bowlerRun;
                allRounder.wkts = bowlerRecord -> wkts;

                playersList.push_back(allRounder);
            }
        }
    }
    return playersList;
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

        case ECONOMY:
            playerList = bowlerList;
            playerList.sort([](const IPLRecordDAO firstBowler, const IPLRecordDAO secondBowler)
            {return firstBowler.economy < secondBowler.economy;});
            break;

        case FIVEWKT_FOURWKT_STRIKERATE:
            playerList = bowlerList;
            playerList.sort([](const IPLRecordDAO firstBowler, const IPLRecordDAO secondBowler)
            {return ((firstBowler.strikeRate != 0 && secondBowler.strikeRate != 0) ? firstBowler.strikeRate < secondBowler.strikeRate : bool()) && 
            (firstBowler.fiveWkts + firstBowler.fourWkts) > (secondBowler.fiveWkts + secondBowler.fourWkts);});
            break;

        case BOWL_AVG_WITH_STRIKERATE:
            playerList = bowlerList;
            playerList.sort([](const IPLRecordDAO firstBowler, const IPLRecordDAO secondBowler)
            {return ((firstBowler.bowlingAverage != 0 && secondBowler.bowlingAverage != 0) ? firstBowler.bowlingAverage < secondBowler.bowlingAverage : bool()) &&
            ((firstBowler.strikeRate != 0 && secondBowler.strikeRate != 0) ? firstBowler.strikeRate < secondBowler.strikeRate : bool());});
            break;

        case BOWL_WKTS_WITH_AVG:
            playerList = bowlerList;
            playerList.sort([](const IPLRecordDAO firstBowler, const IPLRecordDAO secondBowler)
            {return ((firstBowler.bowlingAverage != 0 && secondBowler.bowlingAverage != 0) ? firstBowler.bowlingAverage < secondBowler.bowlingAverage : bool()) &&
            firstBowler.wkts > secondBowler.wkts; });
            break;

        case BATTING_BOWLING_AVERAGE:
            playerList = getAllRounderData(batsmanList, bowlerList);
            playerList.sort([](const IPLRecordDAO firstPlayer, const IPLRecordDAO secondPlayer)
            {return ((firstPlayer.bowlingAverage != 0 && secondPlayer.bowlingAverage != 0) ? firstPlayer.bowlingAverage < secondPlayer.bowlingAverage : bool()) &&
            firstPlayer.battingAverage > secondPlayer.battingAverage;});

        case MOST_RUNS_AND_WKTS:
            playerList = getAllRounderData(batsmanList, bowlerList);
            playerList.sort([](const IPLRecordDAO firstPlayer, const IPLRecordDAO secondPlayer)
            {return  firstPlayer.wkts > secondPlayer.wkts && firstPlayer.batsmanRun > secondPlayer.batsmanRun;});

        case MAX_100_WITH_BAT_AVG:
            playerList = batsmanList;
            playerList.sort([](const IPLRecordDAO firstPlayer, const IPLRecordDAO secondPlayer)
            {return firstPlayer.century > secondPlayer.century && firstPlayer.battingAverage > secondPlayer.battingAverage; });
    }   

    return playerList;
}