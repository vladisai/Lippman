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
	//associative containers	
	//map, set, multimap, multiset, + unordered versions	
	set<int> s = {1, 2, 3, 4};
	map<int, int> m = {{1, 1}, {2, 2}};
	map<int, int, bool (*)(const int, const int)> m2(..); //with comparer
	//can use inserter
	s.insert(1);//returns a pair of iterator where it was stored and a bool of whether it was stored at all
	s.emplace(43);
	s.insert(s.begin(), 43); //pointer is where one should start searching
	m.equal_range(4) = {m.lower_bound(4), m.upper_bound(4)};

	//unordered containers
	unordered_set<int> us;
	us.bucket_size(i); // i is the number of bucket
	us.bucket_count();
	us.max_bucket_count(); 
	us.bucket(k); // where k can be found
	us.load_factor(); // average filledness of a bucket
	us.max_load_factor(); // max filledness
	us.rehash(12); //reorganzie to keep at least 12 buckets
	us.reserve(12); //reserve space so that we can add at least 12 more elements
	unordered_multiset<int, int (*)(int), bool (*)(int, int)> uo(f1, f2); //overloaded hasher and compare
	return 0;
}
