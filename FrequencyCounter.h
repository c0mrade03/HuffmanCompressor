#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

class FrequencyCounter
{
private:
  std::unordered_map<char, int> frequencyMap; //  Unordered map to store the frequencies of the characters in the file

public:
  const std::unordered_map<char, int> &getFrequencyMap() const; /* Will return the frequency map we will create
                                                                since we don't want to change the contents of the map
                                                                the return type is set to const*/

  void readFile(const std::string &fileName); // Will read contents of the file with the help of file handling
};
