#include "decompressor.h"

#ifndef LZ78_DECOMPRESSOR_H
#define LZ78_DECOMPRESSOR_H

class Lz78_decompressor : public Decompressor {
private:
	Lz78_decompressor (int dict_size);

	std::string decompress (const std::string msg) const;

	int dict_size_;

	friend class Lz78_compressor;
};

#endif
