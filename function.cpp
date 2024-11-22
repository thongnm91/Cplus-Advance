#include "function.h"

void unsignedChar(unsigned char a, unsigned char b) {
	unsigned char result = a + b;
	std::cout << "a (" << static_cast<int>(a) << ") + b ("
		<< static_cast<int>(b) << ") = "
		<< static_cast<int>(result) << std::endl;
}

void  signedChar(signed char a, signed char b) {
	signed char result = a + b;
	std::cout << "  " << std::bitset<8>(a) << "  (" << static_cast<int>(a) << ")\n";
	std::cout << "+ " << std::bitset<8>(b) << "  (" << static_cast<int>(b) << ")\n";
	std::cout << "  --------\n";
	std::cout << "  " << std::bitset<8>(result) << "  (" << static_cast<int>(result) << ")\n";
}

void loopOverFlow() {
	int b = 0;
	for (signed char a = 0; a < 128; a++) {
		b++;
		std::cout << static_cast<int>(a) << "\n";
		if (b == 500) break;
	}
}
