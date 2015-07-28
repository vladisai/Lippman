#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

int operator + (int b, int a); //error, can't redefine the standard operations

struct A
{
	int val;
	A operator - (A b)
	{
		return {val - b.val};
	}

	A& operator ++ ()
	{
		val++;
		return *this;
	}

	A operator ++ (int b)
	{
		A a = *this;
		val++;
		return a;
	}

	//-> must return either a pointer or an object with overloaded ->
	int * operator -> ()
	{
		return &val;
	}
	
	//there can be multiple versions of (), each with different parameters
	int operator () ()
	{
		return val;
	}

	void operator () (int a)
	{
		val = a;
	}

	//lambdas are call objects
	

	//conversion operators
	//have no return types
	//should generally be defined as const
	operator int() const
	{
		return val;
	}

	operator double() const
	{
		return val;
	}
	//we have both int and double, so when we need to cast to
	//long double, we're going to have a bad time
	//to avoid this, we should define a conversion
	//only to one built-in type

	//compiler still can use explicit conversions
	//to cast to bool when used in if while or for - in condition
	explicit operator double() const
	{
		return val;
	}

	operator bool() const
	{
		return val;
	}
};

A operator + (A a, A b)
{
	return {a.val + b.val};
}

int main()
{
	//operator overloading	
	//if an overloaded operator funcitons is a class-member,then
	//this function has one less explicit parameter (this is passed
	//implicitly)
	//explicit operator call
	A a = {1}, b = {2};
	operator+(a, b); //explicit non-member
	a.operator-(b); //explicit member

	//= [] () -> operators must be members
	//+= etc are not required to be, but usually are, members
	//arithmetic and equality are usually non-members
	//mixed types must be non-members to be mixed
	//
	string s = "world";
	string h = "hello" + s;//if s + const char * were member operations, it wouldn't work cuz char * is not a class at all

	//library defined callables
	plus<int>;
	negate<int>;
	modulus<int>;
	less<int>;
	less_equal<int>;
	equal_to<int>;
	logical_and<int>;

	//lambdas cannot be assigned to a variable of a type because
	//they all have different types - they are callable objects
	//to solve this, we have functional header
	function<int(int, int, int)> f;//f is a null funciton
	function<int(int, int)> f1(nullptr); //explicit null function
	function<int(int, int)> f2([](int a, int b){ return max(a, b);} );
	function<int(const int&, const int&)> f3 = max<int>;
	//f casts to bool - true if not null
	f(1, 3, 4); //calls it
	//casts can be ambiguous
	
	struct B;
	struct A
	{
		A() = default;
		A(const B&);
	};

	struct B
	{
		operator A() const;
	};
	
	A foo(const A&);
	B b;
	A a = f(b); //ambiguous - what to do? construct from b or cast to?
	a = f(b.operator A());//explict call

	//another piece of shit in c++
	struct C
	{
		C(int);
	};
	struct D
	{
		D(double);
	}
	void manip(C);
	void manip(D);
	manip(10); //ambiguous, yeah, even though D is double
	return 0;
}
