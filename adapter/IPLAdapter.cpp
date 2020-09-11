#pragma once
#include <list>
#include "../model/IPLRecordDao.cpp"

class IPLAdapter {
    public:
    virtual list<IPLRecordDAO> loadIPLData(string filePath) = 0;
};