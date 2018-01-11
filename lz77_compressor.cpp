#include <string>
#include <string_view>
#include <sstream>
#include <cmath>
#include <cstddef>
#include "lz77_compressor.h"
#include "lz77_decompressor.h"
#include "compressed_message.h"

Lz77_compressor::Lz77_compressor (int win_size, int buf_size)
: win_size_(win_size), buf_size_(buf_size) {
}

Compressed_message Lz77_compressor::compress (const std::string& str) const {
	std::size_t logic_size = 0;
	int b_size = buf_size_;
	//Buffer beginning.
	auto b_i = str.begin()+1;
	//Dictionary beginning.
	auto d_i = str.begin();
	//Compressed message.
	std::ostringstream msg;
	msg << "<0,0," << *d_i << ">";
	logic_size += std::ceil(std::log2(win_size_-buf_size_+1))
			   +  std::ceil(std::log2(buf_size_)) + 8;
	
	while (b_i < str.end()) {
		std::string_view 	    	buf(&(*b_i), b_size-1);
		std::string_view   	    	dict(&(*d_i), std::distance(d_i, b_i));
		//Beginning of buffer suffix match in dictionary.
		std::string_view::size_type m;
		std::string_view::size_type m_len;

		//Search for the longest match.
		while (buf.length() > 0) 
			if ((m = dict.rfind(buf)) == std::string::npos)
				buf.remove_suffix(1);
			else
				break;
		//Make it count from buffer start.
		if (m == std::string::npos || buf.length() == 0)
			m = 0;
		else
			m = std::distance(d_i+m, b_i);

		m_len = buf.length();
		msg << "<" << m << "," << m_len 
		    << "," << b_i[m_len] << ">";	
		logic_size += std::ceil(std::log2(win_size_-buf_size_+1))
			   +  std::ceil(std::log2(buf_size_)) + 8;

		b_i += m_len+1;
		//At the beginning, there are no enough read characters to
		// fill the dictionary full.
		d_i += std::distance(d_i, b_i) <= win_size_-b_size ? 0 : m_len+1;
		//Also at the end of input, there are not enough characters to
		// fill the buffer full.  
		b_size = std::min((int)(std::distance(b_i, str.end())), b_size);
	}
	std::string *msg_str = new std::string(msg.str());
	Compressed_message comp_msg(get_decompressor(), *msg_str, logic_size);
	return comp_msg;
}

Lz77_decompressor& Lz77_compressor::get_decompressor () const {
	return *(new Lz77_decompressor(win_size_, buf_size_));
}

