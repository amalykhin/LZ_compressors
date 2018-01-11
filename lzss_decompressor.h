#include "decompressor.h"

#ifndef LZSS_DECOMPRESSOR_H
#define LZSS_DECOMPRESSOR_H

class Lzss_decompressor : public Decompressor {
private:
	Lzss_decompressor (int window_size, int buffer_size);

	std::string decompress (const std::string msg) const;

	int win_size_;	
	int buf_size_;

	friend class Lzss_compressor;
};

#endif
