#include <iostream>
#include "../view/IPLAnalyserView.cpp"
#include "../model/IPLAnalyser.cpp"
using namespace std;

const string MOST_RUNS_FILE_PATH = "../resources/IPL2019FactsheetMostRuns.csv";

class IPLController {
    IPLAnalyserView iplView;
    IPLAnalyser iplAnalyser;
    list<IPLBatsmanDataCSV> playerList;

    public:
    IPLController() {
        playerList = iplAnalyser.loadIPLData(MOST_RUNS_FILE_PATH);
    }

    void displayWelcomeMessage() {
        cout << "WelCome To IPLAnalyser 2019" << endl;
    }

    void displayOptionToSortPlayer() {
        bool flag = true;
        list<IPLBatsmanDataCSV> batsmanList;

        while(flag) {
            int option = iplView.getOptionToSortPlayers();

            switch(option) {

                case BATTING_AVERAGE:
                    system("clear");
                    batsmanList = iplAnalyser.getFieldWiseSortedPlayersRecord(playerList, BATTING_AVERAGE);
                    cout << "Batsman having highest to lowest average" << endl;
                    iplView.displayPlayerDetails(batsmanList);
                    break;

                case STRIKE_RATE:
                    system("clear");
                    batsmanList = iplAnalyser.getFieldWiseSortedPlayersRecord(playerList, STRIKE_RATE);
                    cout << "Batsman having highest to lowest strikerate" << endl;
                    iplView.displayPlayerDetails(batsmanList);
                    break;

                case SIX_AND_FOURS:
                    system("clear");
                    batsmanList =  iplAnalyser.getFieldWiseSortedPlayersRecord(playerList, SIX_AND_FOURS);
                    cout << "Batsman hits maximum 6's and 4's" << endl;
                    iplView.displayPlayerDetails(batsmanList);
                    break;

                case SIX_AND_FOURS_WITH_STRIKERATE:
                    system("clear");
                    batsmanList =  iplAnalyser.getFieldWiseSortedPlayersRecord(playerList, SIX_AND_FOURS_WITH_STRIKERATE);
                    cout << "Batsman having best strikerate with max 6's and 4's" << endl;
                    iplView.displayPlayerDetails(batsmanList);
                    break;

                case BAT_AVG_WITH_STRIKERATE:
                    system("clear");
                    batsmanList =  iplAnalyser.getFieldWiseSortedPlayersRecord(playerList, BAT_AVG_WITH_STRIKERATE);
                    cout << "Batsman having best average with best strikerate" << endl;
                    iplView.displayPlayerDetails(batsmanList);
                    break;

                case 6:
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