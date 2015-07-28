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
	//sequential containers		
	//the order of the elements depends on the order they were added in
	//
	//vector
	//deque
	//list
	//forward_list
	//array
	//string
	//
	//type aliases of these containers:
	//iterator
	//const_iterator
	//size_type
	//difference_type
	//value_type
	//reference	
	//const_reference
	//
	//
	//size operations
	//c.size()
	//c.max_size()
	//c.empty()
	//
	//inserting
	//c.insert(args)
	//c.emplace(args)
	//c.erase(args)
	//c.clear()
	//
	array<int, 42> ar; //array of 42 ints, must always include amount of elements, if not provded with initializer, values will be default-initialized
	array<int, 42> ar1 = {14, 12}; //the rest is 0
	ar1.swap(ar);
	ar1 = {0}; //error, cannot assign
	ar1[1] = 12;
	//excepting array, swap is fast and constant time

	//assign
	vector<int> a, b;
	a.assign({1, 2, 3});
	a.assign(b.begin(), b.end());
	a.assign(10, 3);
	//emplace
	a.emplace_back(12);
	a.emplace(a.begin(), 21);
	a.insert(a.begin(), 10, 10); //inserts ten tens, before a.begin()
	a.insert(a.begin(), {1, 2, 3});

	//accessing an element
	a[0];
	a.back();
	a.front();
	a.at(0);	
	//only at is protected from out of range errors
	
	//forward list has off-the beginning iterators
	//forward list inserts after the given iterator, not before
	forward_list<int> li = {1, 2, 3};
	li.insert_after(li.before_begin(), 12);
	//essentially, everything is the same, but with after
	//
	a.resize(100, -1); //added elements will be -1, if not specified, everything is value-initialized

	//pointers invalidation	
	//pointers, references and iterators are invalidated if a container was reallocated because of adding a new element	
	//deque preserves its iterators if we add in the front or back
	//after deleting, only iterators after deletion point are invalidated in vectors
	//lists always preserve iterators
	a.shrink_to_fit(); // stop reserving extra memory

	//string functions
	string s("abacabaadsaf", 10); //s is first 10 characters of the given string
	string s2(s, 4); // s2 is s after 4th character
	string s3(s, 4, 3); // s3 is three symbols after 4th in s
	s3.insert(s3.size(), s, 3, 2); // insert 2 characters starting from 3rd of s to the end of s
	s3.append(s); // captain
	s3.append(3, 'a');

	//string search functions
	s.find("123", 3); //find the first occurence of constructed string, start from 3rd symbol in s
	s.rfind("123", 1, 2); //find the last occurence of constructed string, start from the 1st symbol in s, use 2 first characters of 123
	s.find_first_of("123");//find first character that belongs to the given string
	s.find_last_of("123"); // the same, but in reverse
	s.find_first_not_of("123"); // captain
	s.find_last_not_of("123"); // captain again

	//comparing
	s.compare("123");
	s.compare(1, 2, "123", 1); //compare the substring from 1 to 1 + 2 from s to first symbol of "123"
	
	s.compare(1, 2, s3, 1, 2); // compare the 1 to 3 sybmols from s to 1 to 3 symbols from s3

	//numeric conversions
	to_string(123);//return string 123
	
	stoi(s, p, b);//return numeric initial substring of s, p=0 is pointer to a variable where to store the first nonnumber in s, b=10 is base
	stol(s, p, b);
	stoul(s, p, b);
	stoll(s, p, b);
	stoull(s, p, b);
	stof(s, p, b);
	stod(s, p, b);
	stold(s, p, b);

	//container adaptors
	//size_type
	//stack, queue, priority_queue
	//by default, stack and queue are deques, and pq is a vector
	//

	return 0;
}
