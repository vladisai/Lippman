#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

class LinearSort; //it is declared, but incomplete
//we can only define pointers or references to such types
//and can declare (not define) functions that use it as a parameter or return type

class Sales_data;

class Constructors
{
	public:
		Constructors(int a) : b(a)
		{
			//now, anywhere where Constructors type is required, int will be accepted	
		}
		Constructors(string s) 
		{
			b = 0;
		}
		explicit Constructors(long k) //there won't be any conversions from long
			//explicit only allowed only in class, no definitions outside can use it
		{

		}
		int b;
};

bool is(Constructors c)
{
	return c.b > 4;
}
//it is ok to call it with integer as an argument
//although it is not ok to call it with c-style string, because only one conversion is allowed
//not char * -> string
//and string ->  Constructors
//it is logical, because arguments are = initialized with parameters
//to suppress such converions, we can declare constructors as explicit

class A
{
	public:
		A(Sales_data sd);
		int B(Sales_data sd);
};

void f(Sales_data);

class B
{
	public:
		//we cannot omit defining constructor for this class as it holds a reference
		//the same applies to const variables
		B(int &a) : r(a) //this is ok, r is initialized with an object.
			    //values are initialized in the order in which they appear in the class
		{
			r = a;//now it is not ok, r is assigned, so if not for init list, an error would be generated
		}
		int &r;
};

class C
{
	public:
		C(int d = 0, int e = 0, int f = 0) : c(d), b(c), a(c) // it is wrong, because value of c is not known when a is innitialized, and a is 
					 //initialized first because a comes first in the class
					 //constructor that defines default values for all arguments is also a default constructor
					 //
					 //default constructor is called when
					 //when we define nonstatic variables or arrays without initializers
					 //when it is inside another class
					 //when members are not explicitly initialized
					 //
					 //value initialization is used when
					 //during array initialization when we provide fewer elements than there are
					 //when we define local static object without an initializer
					 //when we explicitly request value initialization
		{	}
		int a, b, c;
};

class D
{
	public:
		C() : C(0, 0)
		{}
		
		C(int a, int b) : a(a), b(b)
		{}
	private:
		int a, b;
};

//aggregate classes
//they have no constructors
//all data members are public
//no in-class initializers
//no base classes or virtual functions
//such classes can be initialized {1, 2, 3}
//although elements must appar in the same order as in the class itself
//if there are fewer elements in the braces, the rest is value initialized
struct Aggregate
{
	int a, b, c;
};

//literal classes
//aggragate classes are literal
//literal class must
//have data members of literal type
//must have constexpr constructor (at least one)
//initializers in the class must be constexpr constructors
//class must use defalut destructor
//
//constexpr constructor must initialize every data member
class cste
{
	public:
		constexpr cste(int k = 0) : k(k) {};
	private:
		int k;
};

class Sales_data 
{
	friend ostream &print(ostream &os, const Sales_data &sd);
	friend class A;//classes are bros too
	friend A::A(Sales_data sd);
	friend void f(Sales_data sd)//defines f, but f must be declared outside the class
	{
		cout << sd.bookNo;
	}

	//also note that all the names of variables are considered when looking up class scope, not only preceeding ones
	//friends, the friend function must be declared in the same file
	public: //access control this is, and important it is, only inclass function can use private parts (if you understand what I'm talking about)
		//public and private are basically encapsulation
		//constructor
		//it can't be const, object is not const until after constructor is run	
		//if no constructor was defined, then synthesized default is used
		//it uses any in-class values to initialize objects 
		//if object does not have a value, it is default initialized
		//so built-ins are random :(
		//and default is generated only if there are no other constructors
		//and also if it is possible to generate one, i.e. if all objects can be generated with their constructors
		//initializer list uses its values to initialize variables (1st time), if there are no value for a variable in the list, it is initialized with 
		//a value in the class, if this is not found it is default initialized
		Sales_data(const string &isbn, const int &units) : bookNo(isbn), units_sold(units)
		{
			
		}

		mutable int whatever{0}; //value that can change even in constant objects
		//and even const member functions can change it
		//and references to const
		//and pointers
		//and whatever
		//P.S. in class initializer must be provided with = initialization or {}


		Sales_data() = default; //default only to empty constructors
		//default does not work with initlists
		Sales_data() : bookNo("ad") = default; //error

		//compiler also automatically defines copy, destruction and assign operations
		//sometimes we may want to use our own versions
		//copy = copy every member one by one
		//assign = assign every member one by one
		//destroy = destroy every member one by one
		//the problems may arise if we use dynamic memory
		//in such case, there may be memory leaks

		string isbn() const //in-class functions are implicitly inline
			//and every functions has implicitly defined this
			//parameter
			// so whenever we see isbn() it is actually
			// Sales_data::isbn(*object_sales_data);
			// this is 
			// const Sales_data *this;
			// const after the funciton means that this is a 
			// constant pointer to the object
			// so this is
			// const Sales_data *const this;
			// 
			// const objects (or references and pointers)
			// can only call const functions, like this isbn
		{
			return bookNo;
		}

	private:
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};

A::A(Sales_data sd)
{
	cout << sd.bookNo;	
}

ostream &print(ostream &os, const Sales_data &sd)
{
	os << sd.bookNo;//see, it uses private variable, and no fuss about it, our bros and friends can use our stuff	
	return os;
}

int main()
{
	//classes	
	//key ideas behind classes are abstraction and incapsulation
	//abstraction - is a technique of separation interface and implementation
	//interface - operations that a user can perform
	//implementation - bodies of the functions
	//encapsulation - forcing of separation of interface and implementation. class hides its implementation. users only use interface
	//class that uses abstraction is an abstract data type, i.e. users need not know how the class works
	//
	//our old sales_item class is not an abstract data type, it allows users to edit its contents
	//but now we are going to define a new abstract one
	return 0;
}
