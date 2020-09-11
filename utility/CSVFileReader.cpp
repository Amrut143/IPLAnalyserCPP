#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

class CSVReader {
    private:
    vector<string> split(const string& line, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(line);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    public:
    list<vector<string>> readCSVFile(string file) {
        fstream fileStream;
        fileStream.open(file, ios::in);

        list<vector<string>> csvList;

        if (fileStream.is_open()) {
            vector<string> details;
            string line, word;
            getline(fileStream, line);

            while (!fileStream.eof()) {
                details.clear();
                getline(fileStream, line);
                stringstream ss(line);
                while (getline(ss, word)) {
                    csvList.push_back(split(word, ','));
                }
            }
        }
        fileStream.close();
        return csvList;
    }
}; 