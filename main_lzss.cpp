#include <string>
#include <string_view>
#include <iostream>
#include <sstream>
#include <fstream>
#include "lzss_compressor.h"
#include "compressed_message.h"

int main (int argc, char **argv) {
	if (argc < 4) {
			std::cerr << "Usage: ./a.out FILE WINDOW_SIZE BUFFER_SIZE \n";
			return 1;
	}

	std::ifstream istream;
	istream.open(argv[1]);
	std::ostringstream str;
	istream >> str.rdbuf();

	int win_size = std::stoi(argv[2]);
	int buf_size = std::stoi(argv[3]);
	Lzss_compressor lzss(win_size, buf_size);
	Compressed_message msg = lzss.compress(str.str());
	std::cout << 1-msg.get_size()/(str.str().size()*8.0) << "\n";
	std::cout << msg << "\n";
	
	istream.close();

	return 0;
}
