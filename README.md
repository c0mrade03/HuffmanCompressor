###Huffman Coding Compression and Decompression

This project implements Huffman coding, a popular algorithm for lossless data compression. It provides functionalities for compressing and decompressing text files using Huffman coding.
##Features

    Compression: Compresses input text files using Huffman coding to reduce file size.
    Decompression: Decompresses previously compressed files to recover the original text.
    Compression Ratio Calculation: Calculates and displays the compression ratio achieved by the algorithm.
    Time Measurement: Measures and displays the time taken for compression and decompression operations.

##Dependencies

    C++ Compiler (supporting C++11 or later)
    Standard Template Library (STL)

##Usage

    Clone the repository to your local machine.
    Compile the source code using a C++ compiler.
    Run the executable file generated after compilation.
    Follow the on-screen instructions to choose between compression and decompression modes and provide input files accordingly.

##File Structure

    Huffman.h: Header file containing class and function declarations for Huffman coding.
    Huffman.cpp: Source file containing the implementation of Huffman coding functionalities.
    FrequencyCounter.h: Header file containing class and function declarations for counting character frequencies in input files.
    FrequencyCounter.cpp: Source file containing the implementation of character frequency counting.
    Node.h: Header file containing class declaration for Huffman tree nodes.
    main.cpp: Main source file containing the menu-driven interface and the main() function.

##Performance

The performance of the Huffman coding algorithm depends on the characteristics of the input data. Text files with a high frequency of repeated characters are expected to achieve better compression ratios compared to files with diverse character distributions.