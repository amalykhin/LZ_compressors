#include <string>
#include "lz78_decompressor.h"

Lz78_decompressor::Lz78_decompressor (int dict_size)
: dict_size_(dict_size) {
}

std::string Lz78_decompressor::decompress (const std::string msg) const {
	return "LZ78 decompressor placeholder.\n";
}
