/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 7
*/

#include <iostream>
#include <chrono>
#include <ctime>
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
            // auto bubbleStartTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "BubbleSort start time: " << ctime(&bubbleStartTime);
            // sorter->BubbleSort(bubbleArray, arraySize);
            // auto bubbleEndTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "BubbleSort end time: " << ctime(&bubbleEndTime);
            // auto stopBubble = chrono::high_resolution_clock::now();
            // auto durationBubble = chrono::duration_cast<microseconds>(stopBubble-startBubble);
            // cout << "BubbleSort execution time: " << durationBubble.count() * 1e-6 << " seconds" << endl;
            // delete bubbleArray;
            // cout << endl;

            // // SelectionSort

            // double *selectionArray = new double[arraySize];
            // for (int i = 0; i < arraySize; ++i)
            // {
            //     selectionArray[i] = arrayToBeSorted[i];
            // }

            // auto startSelection = high_resolution_clock::now();
            // auto selectionStartTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "SelectionSort start time: " << ctime(&selectionStartTime);
            // sorter->SelectionSort(selectionArray, arraySize);
            // auto selectionEndTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "SelectionSort end time: " << ctime(&selectionEndTime);
            // auto stopSelection = chrono::high_resolution_clock::now();
            // auto durationSelection = chrono::duration_cast<microseconds>(stopSelection-startSelection);
            // cout << "SelectionSort execution time: " << durationSelection.count() * 1e-6 << " seconds" << endl;
            // delete selectionArray;
            // cout << endl;

            // // InsertionSort

            // double *insertionArray = new double[arraySize];
            // for (int i = 0; i < arraySize; ++i)
            // {
            //     insertionArray[i] = arrayToBeSorted[i];
            // }

            // auto startInsertion = high_resolution_clock::now();
            // auto insertionStartTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "InsertionSort start time: " << ctime(&insertionStartTime);
            // sorter->InsertionSort(insertionArray, arraySize);
            // auto insertionEndTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "InsertionSort end time: " << ctime(&insertionEndTime);
            // auto stopInsertion = chrono::high_resolution_clock::now();
            // auto durationInsertion = chrono::duration_cast<microseconds>(stopInsertion-startInsertion);
            // cout << "InsertionSort execution time: " << durationInsertion.count() * 1e-6 << " seconds" << endl;
            // delete insertionArray;
            // cout << endl;

            // // QuickSort

            // double *quickArray = new double[arraySize];
            // for (int i = 0; i < arraySize; ++i)
            // {
            //     quickArray[i] = arrayToBeSorted[i];
            // }
            
            // auto startQuick = high_resolution_clock::now();
            // auto quickStartTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "QuickSort start time: " << ctime(&quickStartTime);
            // sorter->Quicksort(quickArray, 0, arraySize - 1);
            // auto quickEndTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "QuickSort end time: " << ctime(&quickStartTime);
            // auto stopQuick = chrono::high_resolution_clock::now();
            // auto durationQuick = chrono::duration_cast<microseconds>(stopQuick-startQuick);
            // cout << "QuickSort execution time: " << durationQuick.count() * 1e-6 << " seconds" << endl;
            // delete quickArray;
            // cout << endl;

            // // MergeSort

            // double *mergeArray = new double[arraySize];
            // for (int i = 0; i < arraySize; ++i)
            // {
            //     mergeArray[i] = arrayToBeSorted[i];
            // }

            // auto startMerge = high_resolution_clock::now();
            // auto mergeStartTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "MergeSort start time: " << ctime(&mergeStartTime);
            // sorter->MergeSort(mergeArray, 0, arraySize - 1);
            // auto mergeEndTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "MergeSort end time: " << ctime(&mergeEndTime);
            // auto stopMerge = chrono::high_resolution_clock::now();
            // auto durationMerge = chrono::duration_cast<microseconds>(stopMerge-startMerge);
            // cout << "MergeSort execution time: " << durationMerge.count() * 1e-6 << " seconds" << endl;
            // delete mergeArray;
            // cout << endl;

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
            // auto shellStartTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "ShellSort start time: " << ctime(&shellStartTime);
            // sorter->ShellSort(shellArray, arraySize, gapValues, size);
            // auto shellEndTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            // cout << "ShellSort end time: " << ctime(&shellEndTime);
            // auto stopShell = chrono::high_resolution_clock::now();
            // auto durationShell = chrono::duration_cast<microseconds>(stopShell-startShell);
            // cout << "ShellSort execution time: " << durationShell.count() * 1e-6 << " seconds" << endl;
            // delete gapValues;
            // delete shellArray;
            // cout << endl;

            delete sorter;
            delete fileProcessor;
        }
        else
        {
            cout << "Invalid command-line argument sequence, please specify the mode, followed by the filename and number of doubles if necessary..." << endl;
            return -1;
        }
    }

    return 0;
}