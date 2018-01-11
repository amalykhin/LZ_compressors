#include <string>
#include "compressor.h"
#include "lzss_decompressor.h"

#ifndef LZSS_COMPRESSOR_H
#define LZSS_COMPRESSOR_H

class Lzss_compressor : public Compressor {
public:
	Lzss_compressor (int window_size, int buffer_size);
	Compressed_message compress (const std::string& str) const;
private:
	Lzss_decompressor& get_decompressor () const;

	int win_size_;	
	int buf_size_;
	int logic_size;
};

#endif
