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
	//tuples		
	//tuple is a set of variables
	auto tu = make_tuple(1, "23", 1.3);
	tuple<int, const char*, double> a = tu;
	get<0>(a);
	cout << tuple_size<decltype(tu)>::value; //size of a tuple - amount of objects, 3 in this case
	tuple_element<0, decltype(tu)>::type intvar = 0;//get the type of an element

	//bitset type
	bitset<32> b(1u); //32 bits, the first one is 1, the rest is 0, the number must be unsigned
	bitset<32> b2(string("---+--++--"), 0, 10, '-', '+'); //- is 0, + is 1, from 0th character, 10 characters
	//operations
	b.any(); //any bit there is 1?
	b.all(); //all bits are 1?
	b.none(); 
	b.count(); //number of 1s
	b.size(); 
	b.test(2); //tests 2nd bit, true if 1
	b.set(2, true);
	b.set(2);
	b.set();
	b.reset(2);
	b.reset();
	b.flip(2);
	b.flip();
	b[2];
	b.to_ulong();
	b.to_ullong();
	b.to_string('0', '1');
	cout << b;
	cin >> b;

	//regular expressions
	string pattern = "123*";
	regex r(pattern);
	smatch m; //info about a match
	//seq, m, r, mft - paramters for regex_match and search
	//seq - string, iterators, whatever
	//m - smatch object
	//mft - regex_constants::match_flag_type, it is optional
	//r - regex object
	//can be used without m
	cout << regex_match("123", r);
	if (regex_search(string("123"), m, r))
		cout << m.str();
	return 0;
}
