#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

class FrequencyCounter
{
private:
  std::unordered_map<char, int> frequencyMap;

public:
  const std::unordered_map<char, int> &getFrequencyMap() const;
  void readFile(const std::string &fileName);
};
