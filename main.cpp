/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 7
*/

#include <iostream>
#include <chrono>
#include "FileProcessor.h"
#include "Sorter.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
    if ((argc != 4) && (argc != 3))
    {
        cout << "Invalid command-line arugments, please check README.txt for correct formatting..." << endl;
        return -1;
    }
    else
    {
        string mode = argv[1];
        if (mode == "create")
        {
            string fileName = argv[2];
            string temp = argv[3];
            int numberOfDoubles = stoi(temp);
            
            FileProcessor *fileProcessor = new FileProcessor();
            fileProcessor->createFile(numberOfDoubles, fileName);
            return 0;
        }
        else if (mode == "sort")
        {
            string fileName = argv[2];
            FileProcessor *fileProcessor = new FileProcessor();
            fileProcessor->readFile(fileName);

            int arraySize = fileProcessor->getArraySize();
            double *arrayToBeSorted = fileProcessor->getArrayToBeSorted();

            Sorter *sorter = new Sorter();

            // // BubbleSort

            // double *bubbleArray = new double[arraySize];
            // for (int i = 0; i < arraySize; ++i)
            // {
            //     bubbleArray[i] = arrayToBeSorted[i];
            // }

            // auto startBubble = high_resolution_clock::now();
            // sorter->BubbleSort(bubbleArray, arraySize);
            // auto stopBubble = chrono::high_resolution_clock::now();
            // auto durationBubble = chrono::duration_cast<microseconds>(stopBubble-startBubble);
            // cout << "BubbleSort: " << durationBubble.count() * 1e-6 << " seconds" << endl;
            // delete bubbleArray;

            // // SelectionSort

            // double *selectionArray = new double[arraySize];
            // for (int i = 0; i < arraySize; ++i)
            // {
            //     selectionArray[i] = arrayToBeSorted[i];
            // }

            // auto startSelection = high_resolution_clock::now();
            // sorter->SelectionSort(selectionArray, arraySize);
            // auto stopSelection = chrono::high_resolution_clock::now();
            // auto durationSelection = chrono::duration_cast<microseconds>(stopSelection-startSelection);
            // cout << "SelectionSort: " << durationSelection.count() * 1e-6 << " seconds" << endl;
            // delete selectionArray;

            // // InsertionSort

            // double *insertionArray = new double[arraySize];
            // for (int i = 0; i < arraySize; ++i)
            // {
            //     insertionArray[i] = arrayToBeSorted[i];
            // }

            // auto startInsertion = high_resolution_clock::now();
            // sorter->InsertionSort(insertionArray, arraySize);
            // auto stopInsertion = chrono::high_resolution_clock::now();
            // auto durationInsertion = chrono::duration_cast<microseconds>(stopInsertion-startInsertion);
            // cout << "InsertionSort: " << durationInsertion.count() * 1e-6 << " seconds" << endl;
            // delete insertionArray;

            // QuickSort

            // double *quickArray = new double[arraySize];
            // for (int i = 0; i < arraySize; ++i)
            // {
            //     quickArray[i] = arrayToBeSorted[i];
            // }
            
            // auto startQuick = high_resolution_clock::now();
            // sorter->Quicksort(quickArray, 0, arraySize - 1);
            // auto stopQuick = chrono::high_resolution_clock::now();
            // auto durationQuick = chrono::duration_cast<microseconds>(stopQuick-startQuick);
            // cout << "QuickSort: " << durationQuick.count() * 1e-6 << " seconds" << endl;
            // delete quickArray;

            // // MergeSort

            // double *mergeArray = new double[arraySize];
            // for (int i = 0; i < arraySize; ++i)
            // {
            //     mergeArray[i] = arrayToBeSorted[i];
            // }

            // auto startMerge = high_resolution_clock::now();
            // sorter->MergeSort(mergeArray, 0, arraySize - 1);
            // auto stopMerge = chrono::high_resolution_clock::now();
            // auto durationMerge = chrono::duration_cast<microseconds>(stopMerge-startMerge);
            // cout << "MergeSort: " << durationMerge.count() * 1e-6 << " seconds" << endl;
            // delete mergeArray;

            // // ShellSort

            // double *shellArray = new double[arraySize];
            // for (int i = 0; i < arraySize; ++i)
            // {
            //     shellArray[i] = arrayToBeSorted[i];
            // }

            // // ShellSort GapValues Algorithm
            // int count = 1;
            // int result = 0;
            // while (result < arraySize)
            // {
            //     result = pow(2.0, count);
            //     if (result > arraySize)
            //     {
            //         break;
            //     }
            //     ++count;
            // }
            // int size = count - 1;
            // int *gapValues = new int[size];
            
            // for (int i = 0; i < size; ++i)
            // {
            //     gapValues[i] = pow(2.0, count - 1) - 1;
            //     --count;
            // }

            // auto startShell = high_resolution_clock::now();
            // sorter->ShellSort(shellArray, arraySize, gapValues, size);
            // auto stopShell = chrono::high_resolution_clock::now();
            // auto durationShell = chrono::duration_cast<microseconds>(stopShell-startShell);
            // cout << "ShellSort: " << durationShell.count() * 1e-6 << " seconds" << endl;
            // delete gapValues;
            // delete shellArray;

            // delete sorter;
            // delete fileProcessor;
        }
        else
        {
            cout << "Invalid command-line argument sequence, please specify the mode, followed by the filename and number of doubles if necessary..." << endl;
            return -1;
        }
    }

    return 0;
}