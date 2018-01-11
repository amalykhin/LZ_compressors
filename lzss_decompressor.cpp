#include <string>
#include "lzss_decompressor.h"

Lzss_decompressor::Lzss_decompressor (int win_size, int buf_size)
: win_size_(win_size), buf_size_(buf_size) {
}

std::string Lzss_decompressor::decompress (const std::string msg) const {
	return msg;
}
