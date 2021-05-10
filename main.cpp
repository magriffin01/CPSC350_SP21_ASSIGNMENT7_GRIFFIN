#include <iostream>
#include "FileProcessor.h"
#include "Sorter.h"

using namespace std;

int main(int argc, char** argv)
{
    FileProcessor *fileProcessor = new FileProcessor();
    fileProcessor->processFile(50, "test.txt");

    double* newArray = fileProcessor->getArrayToBeSorted();

    Sorter *sorter = new Sorter();
    sorter->BubbleSort(newArray, 50);

    for (int i = 0; i < 50; ++i)
    {
        cout << newArray[i] << endl;
    }

    delete sorter;
    delete fileProcessor;
    return 0;
}