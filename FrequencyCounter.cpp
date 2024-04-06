#include "FrequencyCounter.h"

void FrequencyCounter::readFile(const std::string &fileName)
{
  char character;
  std::ifstream inputFile;
  inputFile.open(fileName, std::ios::in);

  if (!inputFile.is_open())
  {
    std::cerr << "Error while opening file" << std::endl;
    return;
  }

  while (inputFile.get(character))
  {
    frequencyMap[character]++;
  }

  inputFile.close();
}

const std::unordered_map<char, int> &FrequencyCounter::getFrequencyMap() const
{
  return frequencyMap;
}