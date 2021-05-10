#include <iostream>
#include "FileProcessor.h"

using namespace std;

int main(int argc, char** argv)
{
    FileProcessor *fileProcessor = new FileProcessor();
    fileProcessor->processFile(345000, "test.txt");

    delete fileProcessor;
    return 0;
}