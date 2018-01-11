#include <string>
#include "compressed_message.h"

#ifndef COMPRESSOR_H
#define COMPRESSOR_H

class Compressor {
public:
	virtual Compressed_message compress (const std::string& str) const = 0;
};

#endif
