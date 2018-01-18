#include <string>
#include <string_view>
#include <iostream>
#include <sstream>
#include <fstream>
#include "lz78_compressor.h"
#include "compressed_message.h"

int main (int argc, char **argv) {
	if (argc < 3) {
			std::cerr << "Usage: ./a.out FILE DICTIONARY_SIZE \n";
			return 1;
	}

	std::ifstream istream;
	istream.open(argv[1]);
	std::ostringstream str;
	istream >> str.rdbuf();

	int dict_size = std::stoi(argv[2]);
	Lz78_compressor lz78(dict_size);
	Compressed_message msg = lz78.compress(str.str());
	std::cout << 1-msg.get_size()/(str.str().size()*8.0) << "\n";
	std::cout << msg << "\n";
	
	istream.close();

	return 0;
}
