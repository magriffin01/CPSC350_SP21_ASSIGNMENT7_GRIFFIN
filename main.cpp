#include <iostream>
#include "FileProcessor.h"
#include "Sorter.h"

using namespace std;

int main(int argc, char** argv)
{
    FileProcessor *fileProcessor = new FileProcessor();
    fileProcessor->processFile(50, "test.txt");

    double *newArray = fileProcessor->getArrayToBeSorted();

    // For ShellSort
    int i = 1;
    int result = 0;
    while (result < 50)
    {
        result = pow(2.0, i);
        if (result > 50)
        {
            cout << i << endl;
            break;
        }
        ++i;
        cout << result-1 << endl;
    }

    int *gapValues = new int[i-1];
    

    // Sorter *sorter = new Sorter();
    // sorter->MergeSort(newArray, 0, 49);

    // for (int i = 0; i < 50; ++i)
    // {
    //     cout << i << ": " << newArray[i] << endl;
    // }

    delete gapValues;
    // delete sorter;
    delete fileProcessor;
    return 0;
}