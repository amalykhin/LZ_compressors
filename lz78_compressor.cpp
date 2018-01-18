#include <string_view>
#include <vector>
#include <sstream>
#include <cstddef>
#include <cmath>
#include "lz78_compressor.h"
#include "lz78_decompressor.h"

Lz78_compressor::Lz78_compressor (int dict_size)
: dict_size_(dict_size) {
}

Compressed_message Lz78_compressor::compress (const std::string& str) const {
	std::size_t logic_size = 0;
	std::vector<std::string_view> dict(1, "");
	int buf_len = 1;
	std::ostringstream msg;
	int last_match_pos = 0;
	for (auto b_i = str.begin(); b_i < str.end(); ) {
		std::string_view buf(&(*b_i), buf_len);
		//Search for a match in the dictionary.
		//Read new characters from input until buf doesn't have a match in
		// the dictionary anymore, then add that word to the dictionary.
		int i = 0;
		for (std::string_view word : dict) {
			if (word == buf) {
				last_match_pos = i;
				buf_len++;
				break;
			} 
			i++;
		}
		if (i >= dict.size()) {
			if (dict.size() >= dict_size_)
				if (last_match_pos != 1) {
					dict.erase(dict.begin()+1);
					if (last_match_pos > 0)
						last_match_pos--;
				}
				else
					dict.erase(dict.begin()+2);
			dict.push_back(buf);
			msg << "<" << last_match_pos << "," << buf.back() << ">";
			logic_size += std::ceil(std::log2(dict_size_)) + 8;
			last_match_pos = 0;
			buf_len = 0;
			b_i += buf.length();
		}
	}
	std::string *msg_str = new std::string(msg.str());
	Compressed_message comp_msg(get_decompressor(), *msg_str, logic_size);
	return comp_msg;
}

Lz78_decompressor& Lz78_compressor::get_decompressor () const {
	return *(new Lz78_decompressor(dict_size_));
}
