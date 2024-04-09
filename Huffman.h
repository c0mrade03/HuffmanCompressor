#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <fstream>
#include <sstream> // To use stringstream
#include <bitset>
#include "Node.h"

class Huffman
{
private:
  std::unordered_map<char, std::string> codeMap;
  void encodeCharacters(Node *rootNode, std::string codeString);
  void writeHeader(std::ofstream &outputStream);
  void readHeader(std::ifstream &inputStream);
  Node *buildDecodingTree(std::unordered_map<char, std::string> encodingMap);

public:
  void huff(std::unordered_map<char, int> frequencyMap);
  void dehuff(std::string fileName, std::string decompressedFileName);
  void compressToFile(std::string inputFileName, std::string outputFileName);
  void decompressToFile(Node *rootNode, std::string codeString, std::string decompressFileName);
};

class MyComparator
{
public:
  bool operator()(Node *node1, Node *node2);
};