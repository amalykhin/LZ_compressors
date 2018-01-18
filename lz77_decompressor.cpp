#include <sstream>
#include "lz77_decompressor.h"

Lz77_decompressor::Lz77_decompressor (int win_size, int buf_size)
: win_size_(win_size), buf_size_(buf_size) {
}

std::string Lz77_decompressor::decompress (const std::string msg) const {
	std::string out;
	std::istringstream m(msg);
	int b, n;
	char c, d;

	while (m) {
		m >> d >> b >> d >> n >> d;
		m.get(c);
		m.get(d);
		out.append(out, std::distance(out.begin(), out.end()-b), n);
		out.push_back(c);
	}

	return out;
}
