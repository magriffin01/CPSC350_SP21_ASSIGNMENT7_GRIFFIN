#include "Sorter.h"

Sorter::Sorter()
{

}

Sorter::~Sorter()
{
    
}

void Sorter::BubbleSort(double *numbers, int numbersSize)
{
    for (int i = 0; i < numbersSize - 1; ++i)
    {
        for (int j = 0; j < numbersSize - i - 1; ++j)
        {
            if (numbers[j] > numbers[j + 1])
            {
                double temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void Sorter::SelectionSort(double *numbers, int numbersSize)
{
    int i = 0;
    int j = 0;
    int indexSmallest = 0;
    double temp = 0;

    for (i = 0; i < numbersSize - 1; ++i)
    {
        indexSmallest = i;
        
        for (j = i + 1; j < numbersSize; ++j)
        {
            if (numbers[j] < numbers[indexSmallest])
            {
                indexSmallest = j;
            }
        }

        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}