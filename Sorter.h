#ifndef SORTER_H
#define SORTER_H

#include <iostream>

using namespace std;

class Sorter
{
    public:
        Sorter();
        ~Sorter();

        void BubbleSort(double *numbers, int numbersSize);
        void SelectionSort(double *numbers, int numbersSize);
        void InsertionSort(double *numbers, int numbersSize);
        void Quicksort(double *numbers, int lowIndex, int highIndex);
        void MergeSort(double *numbers, int lowIndex, int highIndex);
        void ShellSort(double *nubmers, int numbersSize, int *gapValues, int gapValuesSize);

    private:
        int Partition(double *numbers, int lowIndex, int highIndex);
        void Merge(double *numbers, int leftFirstIndex, int leftLastIndex, int rightLastIndex);
        void InsertionSortInterleaved(double *numbers, int numbersSize, int startIndex, int gap);

};

#endif