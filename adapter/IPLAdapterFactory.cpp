#pragma once
#include <list>
#include <string>
#include "BatsmanAdapter.cpp"
#include "BowlerAdapter.cpp"
#include "../utility/PlayerType.cpp"
#include "../model/IPLRecordDao.cpp"
using namespace std;

class IPLAdapterFactory {
    
    public:
    list<IPLRecordDAO> getIPLData(string filePath, PlayerType playerType) {
        if (playerType == BATSMAN)
            return (new BatsmanAdapter) -> loadIPLData(filePath);
        return (new BowlerAdapter) -> loadIPLData(filePath);
    }
};