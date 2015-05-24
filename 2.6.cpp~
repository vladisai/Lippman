#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

//2.6

struct Sales_data
{
	string bookNo;
	unsigned unit_sold = 0.0; //new standard
	double revenue = 0.0;
};

int main()
{
//3.3
//list initializing a vector
	vector<int> v = {1, 2, 3, 4, 5};
	vector<int> v2{1, 2, 3,4, 5};
	vector<int> v3(10); //explicit initializer, ten zeroes in array
	vector<int> v4 = 10; //error, must be explicit
	vector<int> v5(10, 5); //array of ten fives
	vector<int> v6{10, 5}; //array of ten and five
	//vector tries to initialize with init-list whenever possible
	//if not possible, then it uses standard initializers
	vector<string> v7{10}; //ten empty strings
	
	//Introducing Iterators
	//iterators in container are const if container is const
	const vector<int> v8 = {1, 2, 3, 4, 5};
	v8.begin(); //is const iterator
	v7.begin(); //is iterator
	v7.cbegin(); //is const iterator
	//iterators of vectors and strings support arithetics
	auto it = v.begin();
	it += 3; // it points to 4, yo
	//iterators can be compared, too
	(it > v.begin()); //true

	//arrays	
	int arr[30]; // note, the dimension must be constexpr	
	constexpr int dim = 4;
	int dx[dim] = {0, 0, 1, -1};
	int dy[100] = {}; //all will be zero
	char a2[] = "C++"; //note: \0 added to the end
	char a3[3] = "C++"; //error, not space for \n

	int *ptrs[10]; //array of ten pointers to int
	int &refs[10]; //wtf, references?
	int (*Parray)[30] = &arr; //Parray is a pointer to an array of 30 ints
	int (&rarray)[30] = arr; //rarra is a reference
	int *(*parrp)[10] = &ptrs;//parrp is a pointer to an array of pointers, lol
	//range for works in standard arrays too
	for (auto i : dx)
		cout << i << endl;
	//for auto, array is actually a pointer, so:
	auto k = a3; //k is char*
	//although decltype behaves differently
	decltype(a3) k2; //k2 is array of 3 chars
	//library has two functions to learn beginning and end of an array
	begin(a3); //is &a3[0]
	end(a3); //is &a3[0] + 3, probably
	//subscripts can be used on any pointers
	int **p = &ptrs[4];
	p[-2]; //is ptrs[2]

	//cstyle strings funtions
	strlen(a3); //cobvious
	strcmp(a3, a2); //cobvious
	strcat(a2, a3); //concatenates a2 and a3, returns a2
	strcpy(a2, a3); // copies p2 in p1, returns p1

	//multidimensional arrays
	int a[2][2] = { {1, 1}, {2, 2} }; //although nested braces an not necessary
	int a1[2][2] = {1, 1, 2, 2};
	int (&row)[2] = a1[1];
	//can use nested range fors
	for (auto &row : a1)
		for (auto &col : row)
			col = 0;	

	for (auto &row : a1); //iterates through int*, not int[2]
	using int_arr = int[4];
	int_arr *psdfas; //pointer to int[4]


	return 0;
}
