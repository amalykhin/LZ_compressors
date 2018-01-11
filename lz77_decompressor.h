#include "decompressor.h"

#ifndef LZ77_DECOMPRESSOR_H
#define LZ77_DECOMPRESSOR_H

class Lz77_decompressor : public Decompressor {
private:
	Lz77_decompressor (int window_size, int buffer_size);

	std::string decompress (const std::string msg) const;

	int win_size_;	
	int buf_size_;

	friend class Lz77_compressor;
};

#endif
