#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <fstream>
#include <iostream>
#include <random>
#include <iomanip>
#include <string>

using namespace std;

class FileProcessor
{
    public:
        FileProcessor();
        ~FileProcessor();

        void processFile(int numberOfDoubles, string fileName);
        double* getArrayToBeSorted();

    private:
        void openInputFile(string inputFile);
        void readInputFile();
        void closeInputFile(string inputFile);
        void openOutputFile(string outputFile);
        void writeOutputFile(int numberOfDoubles);
        void closeOutputFile(string outputFile);
        double generateRandomDouble();

        ifstream inputStream;
        ofstream outputStream;
        double *arrayToBeSorted;
};

#endif