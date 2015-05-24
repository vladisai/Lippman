#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

constexpr int af(int k)
{
	return k * 2;
}

const string &shorter(const string &s1, const string &s2)
{
	if (s1.size() <= s2.size())
		return s1;
	else
		return s2;
}

string &shorter(string &s1, string &s2)
{
	const string &r = shorter(const_cast<const string&>(s1), const_cast<const string&> (s2));
	return const_cast<string&>(r);
}

int mymax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

double mymax(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;

}

bool lengthCompare(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main() //main can't be recursive and can't be overloaded
{
	//overloaded funcitons	
	//they must differ in their parameters' type or by parameter's amount
	//note, that const is ignored, so
	int f(int);
	int f(const int); //are the same
	//but it's not the same with references
	int f(int &);//these are different
	int f(const int &);//

	//function matching:
	//3 outcomes:
	//best match
	//no match
	//ambiguous call
	//
	//funcitons in local scope hide all funcitons with the same name in outer scope
	shorter(int);
	cout << shorter("a", "ab"); //error, no such funciton

	//also, for default variables, every function declaration must add only one default value for a parameter, but cannot overload existing ones
	//default argument initializers can by anything but local variables
	int a(int x = rand(), int b = rand(), int c = CLOCKS_PER_SEC);

	//constexpr funcitons - funcitons that return a constexpr, but they are not required to do so - if they don't return a const expr, they are just ordinary functions, constexpr are always inline
	//see above, function af, if k is constexpr then af is constexpr, otherwise it's not
	//
	//digression
	//macros
	//__LINE__
	//__FILE__
	//__TIME__
	//__DATE__
	
	//function matching
	//several steps:
	//1. candidate matching - seeing all the funcitons in scope
	//2. viable functions - all functions that can be called with given arguments : types and amount of variables must match
	//
	//functions that do not require a conversion are prefered over those that do
	//funcitons that selected must
	//1.for each argument, match must be no worse that for any other
	//2.for at least one argument, the match must be better than in any other funciton
	//otherwise the call is ambiguous
	mymax(1, 2); //ok, int, int is better than double and double
	mymax(2.0, 34.1); //ok too
	mymax(1, 4.1); //what the hell?

	//argument type conversions
	//conversion rankings
	//1. exact match
	//	types are identical
	//	argument is converted from array to corresponding poninter
	//	top-level const is added or discarded	
	//2. match through const conversion
	//3. match through promotion
	//	i.e. from short to int
	//	from double to long double
	//	void manip(float);
	//	void manip(long);
	//	manip(3.5); is shit because 3.5 is double an can be
	//	converted to anything - no precedence for conversions
	//4. match through an arithmetic or pointer conversion
	//5. match through class-type conversion
	//
	//pointers to functions
	//note: no conversions. at all. and no overloads.
	bool (*pf)(const string &, const string &); // pointer to a function
	pf = lengthCompare; //no need to use address-of operator
	pf = &lengthCompare; //but there is no bad in doing so
	//see next
	cout << pf(" ", "  ");	
	cout << (*pf)("a", "ab+");
	cout << lengthCompare(" a", "adsf");
	//they are all eqivalent
	//pointers to function may be funciton arguments, although sometimes it doesn't look like it
	foo(int f(int, int));
	//can use typedefs and decltypes
	decltype(lengthCompare) f1; //is a function
	decltype(lengthCompare) *f2; //is a pointer to function
	typedef bool (*func)(const string &s1, const string &s2);//the same
	//can return pointers to functions
	//this is a mess :D
	int (*f(int, int, int))(int a, int b);//a function that takes three ints and returns a function that takes 2 ints and returns int
	//or
	using PF = int (*)(int, int);
	PF f4(int, int, int);
	//or
	auto f6(int, int, int) -> int (*)(int, int);
	//or
	decltype (lengthCompare) *ff(int x);

	return 0;
}
