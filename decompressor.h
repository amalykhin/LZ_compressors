#include <string>

#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

class Decompressor {
public:
	virtual std::string decompress (const std::string msg) const = 0;
};

#endif
