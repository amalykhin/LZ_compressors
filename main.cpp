#include <string>
#include <string_view>
#include <iostream>
#include <sstream>
#include <fstream>
#include "lz77_compressor.h"
#include "lzss_compressor.h"
#include "compressed_message.h"

int main (int argc, char **argv) {
	if (argc < 4) {
			std::cerr << "No input string\n";
			return 1;
	}

	std::ifstream istream;
	istream.open(argv[1]);
	std::ostringstream str;
	istream >> str.rdbuf();

	int win_size = std::stoi(argv[2]);
	int buf_size = std::stoi(argv[3]);
	Lz77_compressor lz77(win_size, buf_size);
	Lzss_compressor lzss(win_size, buf_size);
	std::cout << "Original size: " << str.str().size()*8 << "\n";
	Compressed_message msg1 = lz77.compress(str.str());
	std::cout << "-- LZ77 --\nSize: " << msg1.get_size() << "\n";
	std::cout << msg1;
	Compressed_message msg2 = lzss.compress(str.str());
	std::cout << "-- LZSS --\nSize: " << msg2.get_size() << "\n";
	std::cout << msg2;
	
	istream.close();

	return 0;
}
