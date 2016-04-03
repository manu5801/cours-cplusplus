#include <stdint.h>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

#define MASK 0x20
int8_t lc(int8_t c) { return (c>=65&&c<=90)?MASK|c:c; };
int8_t id(int8_t c ) { return c;};

int main() {
	istream_iterator<int8_t> i (cin);
	istream_iterator<int8_t>  eoi;
	ostream_iterator<int8_t> o (cout);
	transform(i,eoi,o,id);
}

