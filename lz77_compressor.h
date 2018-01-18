#include <string>
#include "compressor.h"
#include "lz77_decompressor.h"

#ifndef LZ77_COMPRESSOR_H
#define LZ77_COMPRESSOR_H

class Lz77_compressor : public Compressor {
public:
	Lz77_compressor (int window_size, int buffer_size);
	Compressed_message compress (const std::string& str) const;
private:
	Lz77_decompressor& get_decompressor () const;

	int win_size_;	
	int buf_size_;
};

#endif
