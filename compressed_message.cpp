#include <string>
#include <ostream>
#include <cstddef>
#include "decompressor.h"
#include "compressed_message.h"

Compressed_message::Compressed_message ( Decompressor& decompr,  std::string& msg, std::size_t logic_size) 
: decompr_(decompr), msg_(msg), logic_size_(logic_size) {
}

Compressed_message::~Compressed_message () {
	delete &decompr_;
	delete &msg_;
}

std::string Compressed_message::decompress () const {
	return decompr_.decompress(msg_);
}

std::ostream& operator<< (std::ostream& stream, Compressed_message& m) {
		stream << m.msg_ << "\n";

		return stream;
}

std::size_t Compressed_message::get_size () const {
	return logic_size_;
}
