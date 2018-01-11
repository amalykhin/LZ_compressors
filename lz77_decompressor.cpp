#include <string>
#include "lz77_decompressor.h"

Lz77_decompressor::Lz77_decompressor (int win_size, int buf_size)
: win_size_(win_size), buf_size_(buf_size) {
}

std::string Lz77_decompressor::decompress (const std::string msg) const {
	return "LZ77 decompressor placeholder.\n";
}
