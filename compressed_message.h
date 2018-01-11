#include <string>
#include <cstddef>
#include "decompressor.h"

#ifndef COMPRESSED_MESSAGE_H
#define COMPRESSED_MESSAGE_H

class Compressed_message {
public:
	Compressed_message (Decompressor& decompr, std::string& msg, std::size_t logic_size);
	~Compressed_message ();

	std::size_t get_size() const;
	std::string decompress () const;
	friend std::ostream& operator<< (std::ostream& stream, Compressed_message& m);
private:
	std::string& msg_;
	Decompressor& decompr_;
	std::size_t logic_size_;
};

#endif
