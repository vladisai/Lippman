#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

int main()
{
	//io objects
	//no assign, no copy		
	//
	//condition states
	//Input
	//strm::iostate = integral type that represents condition state of a stream
	//strm::badbit = value that is used to indicate that a value is corrupted
	//strm::failbit = IO operation failed flag
	//strm::eofbit = end of file bit flag
	//strm::goodbit = 0, means that the state is good
	//s.eof() = end of file
	//s.fail() = true if failbit or badbit
	//s.bad() = badbit
	//s.good() = goodbit
	//s.clear() = reset conditions
	//s.clear(flags) = reset condition to flags
	//s.setstate(flag) = adds a flag to the state
	//s.rdstate() = read current state
	//
	//all streams hold buffers
	//data can be read or write one by one, or by buffers
	//there are several guarantees
	//	1. if program is completed normally, buffer is flushed at the end
	//	2. if buffer becomes full, it is flushed. (but there is no way to know when it happends) 
	//	3. when using endl, buffer is flushed
	//	4. buffers are not flushed if the program crashes
	//	5. we can use unitbuf to set the stream internal state to empty the buffer
	cout << unitbuf;
	cout << nounitbuf;
	cout << 1 << flush; //flushes the stream
	cout << 1 << ends; //flushes the stream, but after adding null character
	//	6. buffer is always flushed when a tied stream is used
	//
	// tying two streams together
	auto c = cin.tie(&cout);//returns a pointer to the previous stream, cout is flushed when cin is used
	//multiple streams can tie themselves to the same ostream
	//
	//fstreams
	//fstream() = new fstream, unbound to any file
	//fstream(s) = new fstream bound to file s
	//fstream(s, mode) = new fstream bound to file s with mode mode
	//fstrm.open(string file) = open a file to read or write
	//fstrm.open(strin file, int mode) = open a file with a given mode
	//fstrm.close() = close a stream
	//fstrm.is_open() = bool, checks whether a file stream is opened and not closed
	//when a stream goes out of scope, it is automatically closed
	//
	//file modes
	//in : open for input
	//out : open for output
	//app : seek to the end before every write
	//ate : seek to the end after opening
	//trunc : truncate the file (delete all the contents)
	//binary : do io operations in binary mode
	//whenever open is used, all the flags are reset, or set to default, if not specified
	//
	//stringstream
	//sstream s1;
	//sstream s2("file name string");
	//strm.str() = returns a string
	//strm.str(s) = copies the string s into strm

	return 0;
}
