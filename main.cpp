#include "Huffman.h"
#include "FrequencyCounter.h"

// Function to get the size of a file
std::ifstream::pos_type getFileSize(const std::string &fileName)
{
  std::ifstream in(fileName, std::ifstream::ate | std::ifstream::binary);
  return in.tellg();
}

// Main function
int main()
{
  // Create objects for frequency counter and Huffman coding
  FrequencyCounter frequency;
  Huffman huffman;

  // Display menu
  std::cout << "-------------------------Menu------------------------------\n1.Compress\n2.Decompress" << std::endl;
  std::cout << "Select Your Working Mode: ";
  char choice;
  std::cin >> choice;

  // Perform selected operation
  if (choice == '1')
  {
    // Compressing
    clock_t start = clock();                           // Start timer
    frequency.readFile("input.txt");                   // Read input file to count frequencies
    huffman.huff(frequency.getFrequencyMap());         // Generate Huffman codes
    huffman.compressToFile("input.txt", "output.txt"); // Compress input file
    // Output compression statistics
    std::cout << "Time taken: " << (1.0 * (clock() - start) / CLOCKS_PER_SEC) << "sec" << std::endl;
    std::cout << "Input File Size : " << getFileSize("input.txt") << " bytes." << std::endl;
    std::cout << "Compressed File Size : " << getFileSize("output.txt") << " bytes." << std::endl;
    std::cout << "Compression Ratio : " << (1.0 * getFileSize("output.txt") / getFileSize("input.txt")) << std::endl;
  }
  else if (choice == '2')
  {
    // Decompressing
    clock_t start = clock();                         // Start timer
    huffman.dehuff("output.txt", "finalOutput.txt"); // Decompress compressed file
    // Output decompression statistics
    std::cout << "Time taken: " << (1.0 * (clock() - start) / CLOCKS_PER_SEC) << "sec" << std::endl;
    std::cout << "Input file size (Compressed) : " << getFileSize("output.txt") << " bytes." << std::endl;
    std::cout << "Decompressed file size : " << getFileSize("finalOutput.txt") << std::endl;
  }
  else
  {
    // Invalid choice
    std::cout << "Invalid choice" << std::endl;
  }

  return 0;
}
