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

void Sorter::InsertionSort(double *numbers, int numbersSize)
{
    int i = 0;
    int j = 0;
    double temp = 0;

    for (i = 1; i < numbersSize; ++i)
    {
        j = i;
        while ((j > 0) && (numbers[j] < numbers[j - 1]))
        {
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}

void Sorter::Quicksort(double *numbers, int lowIndex, int highIndex)
{
    if (lowIndex >= highIndex)
    {
        return;
    }

    int lowEndIndex = Partition(numbers, lowIndex, highIndex);

    Quicksort(numbers, lowIndex, lowEndIndex);
    Quicksort(numbers, lowEndIndex + 1, highIndex);
}

void Sorter::Merge(double *numbers, int i, int j, int k) {
   int mergedSize = k - i + 1;                // Size of merged partition
   int mergePos = 0;                          // Position to insert merged number
   int leftPos = 0;                           // Position of elements in left partition
   int rightPos = 0;                          // Position of elements in right partition
   double *mergedNumbers = new double[mergedSize];   // Dynamically allocates temporary array
                                         // for merged numbers
   
   leftPos = i;                           // Initialize left partition position
   rightPos = j + 1;                      // Initialize right partition position
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }

   delete mergedNumbers;
}

void Sorter::MergeSort(double *numbers, int lowIndex, int highIndex)
{
    int j = 0;

    if (lowIndex < highIndex)
    {
        j = (lowIndex + highIndex) / 2; // Find the midpoint in the partition

        // Recursively sort left and right partitions
        MergeSort(numbers, lowIndex, j);
        MergeSort(numbers, j + 1, highIndex);

        // Merge left and right partition in sorted order
        Merge(numbers, lowIndex, j, highIndex);
    }
}

int Sorter::Partition(double *numbers, int lowIndex, int highIndex)
{
    int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    double pivot = numbers[midpoint];

    bool done = false;

    while (!done)
    {
        while (numbers[lowIndex] < pivot)
        {
            lowIndex += 1;
        }

        while (pivot < numbers[highIndex])
        {
            highIndex -= 1;
        }

        if (lowIndex >= highIndex)
        {
            done = true;
        }
        else
        {
            double temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;

            lowIndex += 1;
            highIndex -= 1;
        }
    }

    return highIndex;
}