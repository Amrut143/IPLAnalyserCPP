#include <iostream>
#include "../view/IPLAnalyserView.cpp"
#include "../model/IPLAnalyser.cpp"

#define MOST_RUNS_FILE_PATH "../resources/IPL2019FactsheetMostRuns.csv"

using namespace std;

class IPLController {
    IPLAnalyserView iplView;
    IPLAnalyser iplAnalyser;

    public:
    void displayWelcomeMessage() {
        cout << "WelCome To IPLAnalyser 2019" << endl;
    }

    void displayTopAvgBatsmanDetails() {
        iplAnalyser.loadIPLData(MOST_RUNS_FILE_PATH);
        iplView.displayTopAvgBatsmanDetails(iplAnalyser.getSortedPlayerAsPerBattingAvg());
    }
};

int main() {
    IPLController controller;

    controller.displayWelcomeMessage();
    controller.displayTopAvgBatsmanDetails();

    return 0;
}