#include "Sorter.h"

Sorter::Sorter()
{

}

Sorter::~Sorter()
{
    
}

void Sorter::BubbleSort(double* numbers, int numbersSize)
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