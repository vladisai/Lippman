#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

//Type aliases
typedef double wages; //wages is double now
typedef wages base, *p; //base is double now, p is double*

//in new standard aliases were introduced. Look here:
using SI = long long;

int main()
{
	typedef char *pstring;		
	const pstring cstr = 0;//cstr is a constant pointer to char
	const pstring *ps; // ps is a pointer to a constant pointer to char, not pointer to const
	
	//auto type definition
	auto i = 0, *p = &i; //auto will become int
	auto sz = 0, pi = 3.14; //error, sz is int, pi is double
	int &r = 0;
	auto a = r; //a is int, not reference to int
	int *const p1 = 0;
	const int *p2 = &i;
	*p2 = 15; //error, *p2 returns a constant int lvalue
	auto p3 = p1; //int *, top-level const is ignored
	auto p4 = p2; //const int *, low-level const is kept
	// can have a top-level const, but have to say that explicitly
	const auto p5 = p2;
	// for references, top-level const is not ignored
	auto &r38 = p1;
	auto &r39 = 32;//error, must declare const explicitly
	const auto &r40 = 32;

	//decltype returns type of a variable
	decltype(p1); // int *const
	//decltype returns both top-level const and references
	decltype(r40) k132 = 5; // const int &	
	//decltype is the only place where a reference is not the same as the value to which it refers
	//for expressions, decltype returns lval wherever possible
	decltype(r + 0) b; //int
	decltype(*p2) c = 0; //int&
	//another tricky thing
	int intval = 100;
	decltype(intval); //int	
	decltype((intval)); //&int
	//that's because the expression in brackets gets evaluated, so it becomes a lval reference
	//but if decltype is applied to a variable, it uses only the type of that variable, and it will be a reference only if the variable is a reference
	return 0;
}
