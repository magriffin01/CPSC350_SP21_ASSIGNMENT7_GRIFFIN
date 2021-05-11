#include "FileProcessor.h"

FileProcessor::FileProcessor()
{
    
}

FileProcessor::~FileProcessor()
{
    delete arrayToBeSorted;
}

double* FileProcessor::getArrayToBeSorted()
{
    return arrayToBeSorted;
}

void FileProcessor::processFile(int numberOfDoubles, string fileName)
{
    openOutputFile(fileName);
    writeOutputFile(numberOfDoubles);
    closeOutputFile(fileName);

    openInputFile(fileName);
    readInputFile();
    closeInputFile(fileName);
}

void FileProcessor::openInputFile(string inputFile)
{
    cout << "Attempting to open for input: " << inputFile << endl;

    inputStream.open(inputFile);
    
    if (!inputStream.is_open())
    {
        cout << "Could not open for input: " << inputFile << endl;
    }
    else
    {
        cout << "Successfully opened input: " << inputFile << endl;
    }
}

void FileProcessor::readInputFile()
{
    string numberOfDoubles;
    getline(inputStream, numberOfDoubles);
    arrayToBeSorted = new double[stoi(numberOfDoubles)];

    string doubleToBeInserted;

    for (int i = 0; i < stoi(numberOfDoubles); ++i)
    {
        getline(inputStream, doubleToBeInserted);
        arrayToBeSorted[i] = stod(doubleToBeInserted);

        // testing
        cout << arrayToBeSorted[i] << endl;
    }
}

void FileProcessor::closeInputFile(string inputFile)
{
    cout << "Closing for input: " << inputFile << endl;

    inputStream.close();
}

void FileProcessor::openOutputFile(string outputFile)
{
    cout << "Attempting to open for output: " << outputFile << endl;

    outputStream.open(outputFile);

    if (!outputStream.is_open())
    {
        cout << "Could not open for output: " << outputFile << endl;
    }
    else
    {
        cout << "Successfully opened for output: " << outputFile << endl;
    }
}

void FileProcessor::writeOutputFile(int numberOfDoubles)
{
    outputStream << numberOfDoubles << "\n";

    double randomDouble;

    for (int i = 0; i < numberOfDoubles; ++i)
    {
        randomDouble = generateRandomDouble();
        outputStream << randomDouble << "\n";
    }
}

void FileProcessor::closeOutputFile(string outputFile)
{
    cout << "Closing for output: " << outputFile << endl;

    outputStream.close();
}

double FileProcessor::generateRandomDouble()
{
    random_device rand;
    default_random_engine eng(rand());
    uniform_real_distribution<double> distr(0, 500000);
    return distr(eng);
}