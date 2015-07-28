#include <bits/stdc++.h>
#include <functional>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;
using namespace std::placeholders;

const int N = 1111;

int frf = 123;

int foo(int k, int &c)
{
	return k < c;
}

int main()
{
	vector<int> v = {9, 2, 3, 4, 5, 6, 10};
	vector<int> v2 = {9, 23, 5324, 1};
	//generic algorithms		
	//find
	find(v.begin(), v.end(), 3); //find looks through entire array, returns a pointer to the first element of specified value, or off-the end pointer otherwise
	
	//read-only algorithms
	accumulate(v.begin(), v.end(), 0); // find the sum
	equal(v2.begin(), v2.end(), v.begin());//compare, although v must have at least as many items as v2	

	//write
	fill(v.begin(), v.end(), -12);
	fill_n(v.begin(), 3, 2);

	//back inserter
	//uses push_back
	vector<int> ev;
	fill_n(back_inserter(ev), 10, 12);
	replace(ev.begin(), ev.end(), 12, 3);//replace 12 with 3
	copy(v.begin(), v.end(), back_inserter(ev));
	replace_copy(ev.begin(), ev.end(), back_inserter(v), 3, 12);
	
	sort(ev.begin(), ev.end());
	auto it = unique(ev.begin(), ev.end());
	ev.erase(it, ev.end());

	int (*f)(int, int) = [](int a, int b){ if (a < b) return a; return b;};
	//f is a callable object

	int k = 0;
	{
		//lambda [] is a capture list, () is parameter list -> type is obvious, and {} is the body
		find_if(v.begin(), v.end(), [k](const int &a) -> int {return a == k;});//the last one is a predicate, find first 13 in the array
	}

	for_each(v.begin(), v.end(), [](int &k){cout << k; k = 0; });

	//return type can be omitted only if the return statement is the only statement 
	[&](){}; // capture everything by reference
       	[=](){}; // capture everything by value
	[&, k](){}; // capture everything but k by value	
	[=] () mutable { a++; b++; return a + b;};//mutable allows editing variables captured by value (copies of them, technically speaking)

	//bind
	//bind is used to modify these predicates, so that when you call something, some other arguemnts are passed too
	int kc = 123;
	auto bar = bind(foo, _22, ref(kc));  //must use std::placeholders	
	//ref return reference to kc
	//when we call bar, foo will be called with the first arguemtn of bar, and 6 as the second
	//
	//iterators
	//back_inserter, front_inserter, inserter
	//insert iterators have * and ++ operators, but they don't change
	//
	istream_iterator<int> iwit(iter, instream);
	istream_iterator<int> end; //off-the end iterator
	ostream_iteraotr<int> osit(ostream, "characters"); // "characters" may be omitted
	//to write into this stream, we simply assign
	osit = 5;
	//to read, we must do this
	cout << *iwit++;

	//iterator categories
	//input iterator - only ++, only read, one pass
	//output iterator - only ++, only write, one pass
	//forward iterator - read/write, multipass,increment only
	//bidirectional - read/write, multipass, increment and decrement
	//random-access - read/write, multipass, full iterator arithmeti
	//
	//list specific operations
	list.sort();
	list.remove_if(predicate);	
	list<int> li1 = {1, 2, 3, 4, 5}, li2 = {1, 23 ,55,1 2341};

	li1.merge(li2);// merge, just like in mege sort
	li1.splice(li1.begin(), li2);//moves all the elements from li2 to before the iterator in li1
	li.splice(li1.begin(), li2.begin(), li2.end()); //moves 
	return 0;
}
