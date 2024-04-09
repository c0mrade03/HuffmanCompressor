#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <fstream>
#include <sstream>
#include <bitset>
#include "Node.h" // Include the Node class header file

class Huffman
{
private:
  std::unordered_map<char, std::string> codeMap; // Map to store character codes
  // Private member functions
  void encodeCharacters(Node *rootNode, std::string codeString);              // Function to encode characters with their codes
  void writeHeader(std::ofstream &outputStream);                              // Function to write header information to compressed file
  void readHeader(std::ifstream &inputStream);                                // Function to read header information from compressed file
  Node *buildDecodingTree(std::unordered_map<char, std::string> encodingMap); // Function to build decoding tree from character codes

public:
  // Public member functions
  void huff(std::unordered_map<char, int> frequencyMap);                                         // Function to perform Huffman encoding
  void dehuff(std::string fileName, std::string decompressedFileName);                           // Function to perform Huffman decoding
  void compressToFile(std::string inputFileName, std::string outputFileName);                    // Function to compress a file
  void decompressToFile(Node *rootNode, std::string codeString, std::string decompressFileName); // Function to decompress a file
};

// Comparator class used for priority queue
class MyComparator
{
public:
  bool operator()(Node *node1, Node *node2); // Comparison operator for nodes
};
