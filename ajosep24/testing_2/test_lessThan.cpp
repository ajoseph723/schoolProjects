#include <iostream>
#include "string.hpp"

int main()
{

	{
		// testing 2 default strings

		String a;
		String b;

		assert(!(a < b) && !(b < a));
	}

	{
		// testing 2 equal strings that contain a char

		String a('a');
		String b('b');
		String c('a');

		assert(a < b);
		assert(!(b < a));
		assert(!(a < c) && !(c < a));
	}

	{
		// testing string of character arrays of the same size
		String a("abc");
		String b("abc");
		String c("abb");

		assert(!(a < b));
		assert(c < a);
	}

	{
		// testing strings of different sizes
		String a("abc");
		String b("abcd");
		String c("aabb");

		assert(a < b);
		assert(c < a);
	}

	{
		// testing strings less than different data types and vice versa
		String a("abc");
		String b("abcd");
		String c('a');

		// Verify
		// testing String < char[]
		assert(a < "abcd");
		assert(!("abcd" < a));
		// testing String < String
		assert(a < b);
		// testing String < char
		assert(c < 'b');
		assert(!('b' < c));
	}

	return 0;
}
