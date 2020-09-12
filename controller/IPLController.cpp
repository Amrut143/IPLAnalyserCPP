#include <iostream>
#include "../view/IPLAnalyserView.cpp"
#include "../model/IPLAnalyser.cpp"
using namespace std;

string MOST_RUNS_FILE_PATH = "../resources/IPL2019FactsheetMostRuns.csv";
string MOST_WKTS_FILE_PATH = "../resources/IPL2019FactsheetMostWkts.csv";


class IPLController {
    IPLAnalyserView iplView;
    IPLAnalyser iplAnalyser;

    public:
    void displayWelcomeMessage() {
        cout << "WelCome To IPLAnalyser 2019" << endl;
    }

    void displayOptionToSortPlayer() {
        bool flag = true;
        list<IPLRecordDAO> playerList;
        iplAnalyser.loadIPLData(MOST_RUNS_FILE_PATH, BATSMAN);
        iplAnalyser.loadIPLData(MOST_WKTS_FILE_PATH, BOWLER);

        while(flag) {
            int option = iplView.getOptionToSortPlayers();

            switch(option) {

                case BATTING_AVERAGE:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(BATTING_AVERAGE);
                    cout << "Batsman having highest to lowest average" << endl;
                    iplView.displayBatsmanDetails(playerList);
                    break;

                case STRIKE_RATE:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(STRIKE_RATE);
                    cout << "Batsman having highest to lowest strikerate" << endl;
                    iplView.displayBatsmanDetails(playerList);
                    break;

                case SIX_AND_FOURS:
                    system("clear");
                    playerList =  iplAnalyser.getFieldWiseSortedPlayersRecord(SIX_AND_FOURS);
                    cout << "Batsman hits maximum 6's and 4's" << endl;
                    iplView.displayBatsmanDetails(playerList);
                    break;

                case SIX_AND_FOURS_WITH_STRIKERATE:
                    system("clear");
                    playerList =  iplAnalyser.getFieldWiseSortedPlayersRecord(SIX_AND_FOURS_WITH_STRIKERATE);
                    cout << "Batsman having best strikerate with max 6's and 4's" << endl;
                    iplView.displayBatsmanDetails(playerList);
                    break;

                case BAT_AVG_WITH_STRIKERATE:
                    system("clear");
                    playerList =  iplAnalyser.getFieldWiseSortedPlayersRecord(BAT_AVG_WITH_STRIKERATE);
                    cout << "Batsman having best average with best strikerate" << endl;
                    iplView.displayBatsmanDetails(playerList);
                    break;

                case BAT_RUN_WITH_AVG:
                    system("clear");
                    playerList =  iplAnalyser.getFieldWiseSortedPlayersRecord(BAT_RUN_WITH_AVG);
                    cout << "Batsman having highest run with best average" << endl;
                    iplView.displayBatsmanDetails(playerList);
                    break;

                case BOWLING_AVG:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(BOWLING_AVG);
                    cout << "Bowler having top average" << endl;
                    iplView.displayBowlerDetails(playerList);
                    break;

                case BOWL_STRIKERATE:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(BOWL_STRIKERATE);
                    cout << "Bowler having top strikerate" << endl;
                    iplView.displayBowlerDetails(playerList);
                    break;

                case ECONOMY:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(ECONOMY);
                    cout << "Bowler having best economy rate" << endl;
                    iplView.displayBowlerDetails(playerList);
                    break;

                case FIVEWKT_FOURWKT_STRIKERATE:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(FIVEWKT_FOURWKT_STRIKERATE);
                    cout << "Bowler having best strikerate with 5'w and 4'w" << endl;
                    iplView.displayBowlerDetails(playerList);
                    break;

                case BOWL_AVG_WITH_STRIKERATE:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(BOWL_AVG_WITH_STRIKERATE);
                    cout << "Bowler having best average with best strikerate" << endl;
                    iplView.displayBowlerDetails(playerList);
                    break;

                case BOWL_WKTS_WITH_AVG:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(BOWL_WKTS_WITH_AVG);
                    cout << "Bowler having most wickets with best average" << endl;
                    iplView.displayBowlerDetails(playerList);
                    break;

                case BATTING_BOWLING_AVERAGE:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(BATTING_BOWLING_AVERAGE);
                    cout << "Player having best batting and bowling average" << endl;
                    iplView.displayAllRounderDetails(playerList);
                    break;

                case MOST_RUNS_AND_WKTS:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(MOST_RUNS_AND_WKTS);
                    cout << "Player having most runs and wickets" << endl;
                    iplView.displayAllRounderDetails(playerList);
                    break;

                case MAX_100_WITH_BAT_AVG:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(MAX_100_WITH_BAT_AVG);
                    cout << "Player having most 100 with best batting average" << endl;
                    iplView.displayBatsmanDetails(playerList);
                    break;

                case ZERO_100_50_WITH_AVG:
                    system("clear");
                    playerList = iplAnalyser.getFieldWiseSortedPlayersRecord(ZERO_100_50_WITH_AVG);
                    cout << "Player having zero 100 and 50 with best average" << endl;
                    iplView.displayBatsmanDetails(playerList);
                    break;

                case 17:
                    flag = false;
                    break;

                default:
                    cout << "Invalid Input!!!!!!!!!" << endl;
            }
        }
    }
};

int main() {
    IPLController controller;

    controller.displayWelcomeMessage();
    controller.displayOptionToSortPlayer();

    return 0;
}