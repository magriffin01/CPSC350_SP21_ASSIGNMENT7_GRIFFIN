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

    private:


};

#endif