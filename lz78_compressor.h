#include <string>
#include "compressor.h"
#include "compressed_message.h"
#include "lz78_decompressor.h"

#ifndef LZ78_COMPRESSOR_H
#define LZ78_COMPRESSOR_H

class Lz78_compressor : public Compressor {
public:
	Lz78_compressor (int dict_size);
	Compressed_message compress (const std::string& str) const;
private:
	Lz78_decompressor& get_decompressor () const;

	int dict_size_;
};

#endif
