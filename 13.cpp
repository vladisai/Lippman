#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

//tools for class authors
//copy control		
//
//copy constructor
//copy-assignment operator
//move consturctor
//move-assignment operator	

//if a class does not defines all of the copy-control members,
//compiler provides its own versions	

class Aza
{
	public:
		Aza() = default; //default constructor
		//can generate default copy, assign and etc
		//before the new standard, they moved constructor to private to achieve this
		//also, we are allowed to declare and not define a 
		//member function to prevent any usage of it

		Aza(const Aza &x) //copy constructor
		//copy initiialization happens whan we define vars
		//using =, when we pass an object as an arguemnt
		//to a parameter of nonreference type
		//when we return an object from a function that has a 
		//nonreference return type
		//when we brace initialize elements
		{

		}

		Aza(const Aza &&x)  noexcept // can't throw any exceptions
			//here we can steal resouces of without
			//fearing that x will ever be used again
			//move constructor
			//moved object must be destructible
		{
			if (this != &x)
			{

			}
		}
		//compiler can synthesize move operations if every nonstatic data member of the class can be moved
		//built in types can be moved
		//and classes with move can be moved
		//
		//move is defined as deleted if the class or one of its members defines copy but doesn't defien move
		//or if a member has a deleted move
		//or if a destructor is deleted
		//or if it has a const or reference member
		//also, if a class has copy defined, move will be defined
		//as deleted	
		
		
		Aza & operator = (Aza &&x) & noexcept  //reference qualifier
			//can only be used ln lvalues
			//move assignment
		{
			if (this != &x)
			{

			}
		}

		void assign() && //can only be used on lvalues
		{

		}
		//note: all or none functions named assign must have ref qualifiers

		void assign() const & noexcept
			//can be used on any value
		{

		}

		void assign(Aza &&x) //ordinary member functions can use
			//rvalue refs as well
		{
			
		}

		Aza& operator = (const Aza &x) //copy-assignment operator
			//default is deleted if a member has deleted =
			//or if the class has a const or reference member
		{
			//must work correctly even if x == this
			return *this;
		}

		~Aza()
		{
			//desturctor
			//gets generated
			//simply deletes every object there is
			//if a class needs a destructor
			//it needs both copy and assignment
			//generally, all three come together
		}

	private:


};

void swap(Aza &a, Aza &b) // if we need destructor and copy-assign, then
	//we need our own swap
{
	Aza c = a;
	a = b;
	b = c;
}

class strm
{
	public:
		strm() = default;
		strm(const strm& x) = delete;//deleted, cannot be used
		//can be used on any functions
	private:
		~strm(); //now any class that has strm has deleted destructor
};

int main()
{
	Azaza a = 123; //compiler is allowed to rewrite this as
	Azaza a(123);//but not obliged. However, copy-initializer must 
	//exist at this point of the program
	//
	//new standard introduced a new feature : moving
	//rvalue references
	//&&
	//can be bound only to an object that is about to be destroyed
	//cannot be bound directly
	int i = 14;
	int &&r = i;//cannot bind to an lvalue
	int &&r2 = i * 14;
	//reference types cannot be bound to an rval, only to lval
	//rvals can be bound to rval references and to const lval references
	//any variable is an lvalue, even rval reference
	int &&r3 = 123;
	int &&r4 = r3;
	//there exists a move operation, that allows us to bind to lvals
	int &&r5 = std::move(r3);//that's ok
	//after we call move, we cannot use the moved object anymore
	//
	//if a class defines both move and copy, ordinary function matching happends
	//rvalues are moved, (copied, if there is no move, even when using
	//std::move)
	//lvalues are copied
	return 0;
}
