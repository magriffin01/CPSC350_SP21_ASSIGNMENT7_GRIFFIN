#include <iostream>
#include "FileProcessor.h"
#include "Sorter.h"

using namespace std;

int main(int argc, char** argv)
{
    FileProcessor *fileProcessor = new FileProcessor();
    fileProcessor->processFile(200, "test.txt");

    double *newArray = fileProcessor->getArrayToBeSorted();

    // For ShellSort
    int count = 1;
    int result = 0;
    while (result < 200)
    {
        result = pow(2.0, count);
        if (result > 200)
        {
            break;
        }
        ++count;
    }
    int size = count - 1;
    int *gapValues = new int[size];
    
    for (int i = 0; i < size; ++i)
    {
        gapValues[i] = pow(2.0, count - 1) - 1;
        --count;
    }

    Sorter *sorter = new Sorter();
    sorter->ShellSort(newArray, 200, gapValues, size);

    for (int i = 0; i < 100; ++i)
    {
        cout << i << ": " << newArray[i] << endl;
    }

    delete gapValues;
    delete sorter;
    delete fileProcessor;
    return 0;
}