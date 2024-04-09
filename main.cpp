#include "Huffman.h"
#include "FrequencyCounter.h"

std::ifstream::pos_type getFileSize(const std::string &fileName)
{
  std::ifstream in(fileName, std::ifstream::ate | std::ifstream::binary);
  return in.tellg();
}

int main()
{
  FrequencyCounter frequency;
  Huffman huffman;
  std::cout << "-------------------------Menu------------------------------\n1.Compress\n2.Decompress" << std::endl;
  std::cout << "Select Your Working Mode: ";
  char choice;
  std::cin >> choice;
  const std::string rootPath = "/home/pk/HuffmanCompressor";
  if (choice == '1')
  {
    clock_t start = clock();
    frequency.readFile(rootPath + "/input.txt");
    huffman.huffer(frequency.getFrequencyMap());
    huffman.compressToFile(rootPath + "/input.txt", rootPath + "/output.txt");
    std::cout << "Time taken: " << (1.0 * (clock() - start) / CLOCKS_PER_SEC) << "sec" << std::endl;
    std::cout << "Input File Size : " << getFileSize(rootPath + "/input.txt") << " bytes." << std::endl;
    std::cout << "Compressed File Size : " << getFileSize(rootPath + "/output.txt") << " bytes." << std::endl;
    std::cout << "Compression Ratio : " << (1.0 * getFileSize(rootPath + "/output.txt") / getFileSize(rootPath + "/input.txt")) << std::endl;
  }
  else if (choice == '2')
  {
    clock_t start = clock();
    huffman.dehuffer(rootPath + "/output.txt", rootPath + "/finalOutput.txt");
    std::cout << "Time taken: " << (1.0 * (clock() - start) / CLOCKS_PER_SEC) << "sec" << std::endl;
    std::cout << "Input file size (Compressed) : " << getFileSize(rootPath + "/output.txt") << " bytes." << std::endl;
    std::cout << "Decompressed file size : " << getFileSize(rootPath + "/finalOutput.txt") << std::endl;
  }
  else
  {
    std::cout << "Invalid choice" << std::endl;
  }

  return 0;
}