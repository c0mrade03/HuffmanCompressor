#include "Huffman.h"

#define INTERNAL_NODE_CHARACTER char(128)
#define PSEUDO_EOF char(129)
#define CHARACTER_CODE_SEPERATOR char(130)
#define HEADER_ENTRY_SEPERATOR char(131)
#define HEADER_TEXT_SEPERATOR char(132)

void Huffman::encodeCharacters(Node *rootNode, std::string codeString)
{
  if (!rootNode)
  {
    return;
  }

  if (rootNode->getCharacter() != INTERNAL_NODE_CHARACTER)
  {
    codeMap[rootNode->getCharacter()] = codeString;
  }

  encodeCharacters(rootNode->getLeft(), codeString + "0");
  encodeCharacters(rootNode->getRight(), codeString + "1");
}

bool MyComparator::operator()(Node *node1, Node *node2)
{
  return node1->getFrequency() > node2->getFrequency();
}

void Huffman::huff(std::unordered_map<char, int> frequencyMap)
{

  std::priority_queue<Node *, std::vector<Node *>, MyComparator> HuffmanQueue;
  std::string tempString;
  Node *leftNode, *rightNode, *newNode;

  for (const auto &item : frequencyMap)
  {
    HuffmanQueue.push(new Node(item.first, item.second));
  }
  HuffmanQueue.push(new Node(PSEUDO_EOF, 1));

  while (HuffmanQueue.size() != 1)
  {
    leftNode = HuffmanQueue.top();
    HuffmanQueue.pop();
    rightNode = HuffmanQueue.top();
    HuffmanQueue.pop();
    newNode = new Node(INTERNAL_NODE_CHARACTER, leftNode->getFrequency() + rightNode->getFrequency());
    HuffmanQueue.push(newNode);
    newNode->setLeft(leftNode);
    newNode->setRight(rightNode);
  }

  encodeCharacters(HuffmanQueue.top(), tempString);
}

void Huffman::writeHeader(std::ofstream &outputStream)
{
  for (const auto &item : codeMap)
  {
    outputStream << item.first << CHARACTER_CODE_SEPERATOR << item.second << HEADER_ENTRY_SEPERATOR;
  }
  outputStream << HEADER_TEXT_SEPERATOR;
}

void Huffman::compressToFile(std::string inputFile, std::string outputFile)
{
  char character;
  std::string file;
  std::ifstream inputStream;
  std::ofstream outputStream;
  inputStream.open(inputFile, std::ios::in);
  outputStream.open(outputFile, std::ios::out);
  writeHeader(outputStream);

  while (inputStream.get(character))
  {
    file += codeMap[character];
  }
  file += codeMap[PSEUDO_EOF];
  inputStream.close();

  unsigned long remainder = (file.size() - 1) % 8;
  for (int i = 0; i < 8 - remainder; i++)
  {
    file += '0';
  }

  std::stringstream stringStream(file);
  while (stringStream.good())
  {
    std::bitset<8> bits;
    stringStream >> bits;
    char c = char(bits.to_ulong());
    outputStream << c;
  }

  outputStream.flush();
  outputStream.close();
}

Node *Huffman::buildDecodingTree(std::unordered_map<char, std::string> encodingMap)
{
  Node *rootNode = new Node(INTERNAL_NODE_CHARACTER);
  Node *previousNode;

  for (const auto &item : encodingMap)
  {
    previousNode = rootNode;
    Node *newNode = new Node(item.first);
    std::string characterCode = item.second;

    for (int i = 0; i < characterCode.size(); i++)
    {
      if (characterCode[i] == '0')
      {
        if (i == characterCode.size() - 1)
        {
          previousNode->setLeft(newNode);
        }
        else
        {
          if (!previousNode->getLeft())
          {
            previousNode->setLeft(new Node(INTERNAL_NODE_CHARACTER));
            previousNode = previousNode->getLeft();
          }
          else
          {
            previousNode = previousNode->getLeft();
          }
        }
      }
      else
      {
        if (i == characterCode.size() - 1)
        {
          previousNode->setRight(newNode);
        }
        else
        {
          if (!previousNode->getRight())
          {
            previousNode->setRight(new Node(INTERNAL_NODE_CHARACTER));
            previousNode = previousNode->getRight();
          }
          else
          {
            previousNode = previousNode->getRight();
          }
        }
      }
    }
  }
  return rootNode;
}

void Huffman::readHeader(std::ifstream &inputStream)
{
  codeMap.clear();
  char character;
  inputStream.get(character);
  char key = character;

  while (character != HEADER_TEXT_SEPERATOR)
  {
    if (character == CHARACTER_CODE_SEPERATOR)
    {
      inputStream.get(character);
      while (character != HEADER_ENTRY_SEPERATOR)
      {
        codeMap[key] += character;
        inputStream.get(character);
      }
    }
    else
    {
      key = character;
    }
    inputStream.get(character);
  }
}

void Huffman::decompressToFile(Node *rootNode, std::string codeString, std::string decompressedFile)
{
  std::ofstream outputStream;
  outputStream.open(decompressedFile, std::ios::out);
  Node *traverse = rootNode;

  for (int i = 0; i < codeString.size() + 1; i++)
  {
    if (codeString[i] == '0')
    {
      traverse = traverse->getLeft();
    }
    else
    {
      traverse = traverse->getRight();
    }

    if (traverse->getCharacter() != INTERNAL_NODE_CHARACTER)
    {
      if (traverse->getCharacter() == PSEUDO_EOF)
      {
        break;
      }
      outputStream << traverse->getCharacter();
      traverse = rootNode;
    }
  }
  outputStream.flush();
  outputStream.close();
}

void Huffman::dehuff(std::string compressedFile, std::string decompressedFile)
{
  char character;
  std::string codeString;
  std::ifstream inputStream;
  inputStream.open(compressedFile, std::ios::in);
  readHeader(inputStream);
  while (inputStream.get(character))
  {
    std::bitset<8> bits(character);
    codeString += bits.to_string();
  }

  Node *rootNode = buildDecodingTree(codeMap);
  decompressToFile(rootNode, codeString, decompressedFile);
}