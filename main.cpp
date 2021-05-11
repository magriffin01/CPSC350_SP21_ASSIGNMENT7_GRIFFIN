#include <iostream>
#include <chrono>
#include "FileProcessor.h"
#include "Sorter.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
    FileProcessor *fileProcessor = new FileProcessor();
    fileProcessor->processFile(200, "test.txt");
    double *arrayToBeSorted = fileProcessor->getArrayToBeSorted();
    Sorter *sorter = new Sorter();

    // BubbleSort

    double *bubbleArray = new double[200];
    for (int i = 0; i < 200; ++i)
    {
        bubbleArray[i] = arrayToBeSorted[i];
    }

    auto startBubble = high_resolution_clock::now();
    sorter->BubbleSort(bubbleArray, 200);
    auto stopBubble = chrono::high_resolution_clock::now();
    auto durationBubble = chrono::duration_cast<microseconds>(stopBubble-startBubble);
    cout << "BubbleSort: " << durationBubble.count() * 1e-6 << " seconds" << endl;
    delete bubbleArray;

    // SelectionSort

    double *selectionArray = new double[200];
    for (int i = 0; i < 200; ++i)
    {
        selectionArray[i] = arrayToBeSorted[i];
    }

    auto startSelection = high_resolution_clock::now();
    sorter->SelectionSort(selectionArray, 200);
    auto stopSelection = chrono::high_resolution_clock::now();
    auto durationSelection = chrono::duration_cast<microseconds>(stopSelection-startSelection);
    cout << "SelectionSort: " << durationSelection.count() * 1e-6 << " seconds" << endl;
    delete selectionArray;

    // InsertionSort

    double *insertionArray = new double[200];
    for (int i = 0; i < 200; ++i)
    {
        insertionArray[i] = arrayToBeSorted[i];
    }

    auto startInsertion = high_resolution_clock::now();
    sorter->InsertionSort(insertionArray, 200);
    auto stopInsertion = chrono::high_resolution_clock::now();
    auto durationInsertion = chrono::duration_cast<microseconds>(stopInsertion-startInsertion);
    cout << "InsertionSort: " << durationInsertion.count() * 1e-6 << " seconds" << endl;
    delete insertionArray;

    // QuickSort

    double *quickArray = new double[200];
    for (int i = 0; i < 200; ++i)
    {
        quickArray[i] = arrayToBeSorted[i];
    }
    
    auto startQuick = high_resolution_clock::now();
    sorter->Quicksort(quickArray, 0, 199);
    auto stopQuick = chrono::high_resolution_clock::now();
    auto durationQuick = chrono::duration_cast<microseconds>(stopQuick-startQuick);
    cout << "QuickSort: " << durationQuick.count() * 1e-6 << " seconds" << endl;
    delete quickArray;

    // MergeSort

    double *mergeArray = new double[200];
    for (int i = 0; i < 200; ++i)
    {
        mergeArray[i] = arrayToBeSorted[i];
    }

    auto startMerge = high_resolution_clock::now();
    sorter->MergeSort(mergeArray, 0, 199);
    auto stopMerge = chrono::high_resolution_clock::now();
    auto durationMerge = chrono::duration_cast<microseconds>(stopMerge-startMerge);
    cout << "MergeSort: " << durationMerge.count() * 1e-6 << " seconds" << endl;
    delete mergeArray;

    // ShellSort

    double *shellArray = new double[200];
    for (int i = 0; i < 200; ++i)
    {
        shellArray[i] = arrayToBeSorted[i];
    }

    // ShellSort GapValues Algorithm
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

    auto startShell = high_resolution_clock::now();
    sorter->ShellSort(shellArray, 200, gapValues, size);
    auto stopShell = chrono::high_resolution_clock::now();
    auto durationShell = chrono::duration_cast<microseconds>(stopShell-startShell);
    cout << "ShellSort: " << durationShell.count() * 1e-6 << " seconds" << endl;
    delete gapValues;
    delete shellArray;

    delete sorter;
    delete fileProcessor;
    return 0;
}