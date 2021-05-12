/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 7
*/

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

        void createFile(int numberOfDoubles, string fileName);
        void readFile(string fileName);
        double* getArrayToBeSorted();
        int getArraySize();

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
        string numberOfDoubles;
};

#endif