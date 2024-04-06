#include "FrequencyCounter.h"

void FrequencyCounter::readFile(const std::string &fileName)
{
  char character;
  std::ifstream inputFile; // creates object of ifstream class
  inputFile.open(fileName, std::ios::in); // Opens a file if the file doesn't exist the creates and opens it

  if (!inputFile.is_open()) // Check if there was any error while opening the file
  {
    std::cerr << "Error while opening file" << std::endl;
    return;
  }

  while (inputFile.get(character)) // Runs the loop till there is character present in the file
  {
    frequencyMap[character]++; // Increments the frequency
  }

  inputFile.close(); // Closes the file
}

const std::unordered_map<char, int> &FrequencyCounter::getFrequencyMap() const
{
  return frequencyMap;
}