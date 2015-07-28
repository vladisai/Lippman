#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

class RangeQuery; // no inhertiance list can be here

//class Query must be defined, not only declared, to be used as a base class
//for RangeQuery

class wtf final //nothing can be inherited from final class
{
	public:
		int a = 0;
};

class Query
{
	public:
		static int qcount;
		Query()
		{
			qcount = 1;
		}

		//virtual is a keyword that tells the compiler that
		//we expect this function to be overridden
		//virtual functions must always be defined
		//compiler has no way to know which version is to be used
		virtual vector<int> apply(const vector<int> &v) const
		{
			vector<int> res;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] != 0)
					res.push_back(v[i]);
			}
			return res;
		}

		virtual ~Query() = default;
		
};

int Query::qcount = 0;

class RangeQuery : public Query //access all public members of Query
{
	public:
		//should use base constructor to contruct
		//the base part of the class
		RangeQuery(int mn, int mx) : Query(), mn(mn), mx(mx)
		{ }

		//override the standard filter
		//if functions is marked as override doesn't override
		//anything, an error will be generated
		//final - no other class that inherits from RangeQuery
		//can override this function
		vector<int> apply(const vector<int> &v) const override final
		{
			//this call uses the Query version of apply
			//we can use scope operator to reach it
			vector<int> res = Query::apply(v);
			for (auto e : v)
			{
				if (e >= mn && e <= mx)
					res.push_back(e);
			}
			return res;
		}
		int mn, mx;
};

vector<int> siftVector(const vector<int> &v, const Query &q)
{
	auto res = q.apply(v);
	return res;
}

ostream& operator << (ostream &os, const vector<int> &v)
{
	for (auto e : v)
		os << e << " ";
	return os;
}

class A
{
	//protected members are just like private in terms of accessibility
	//for users, but these members can be used by inhertied classes
	//can be used only using inherited classes, not from base
	public:
		A()
		{
			a = 0;
		}

		A(int a)
		{
			this->a = a;
		}

		int usingExample;

	protected:
		int a;

	public:
		virtual const A& clone() const & = 0;
		virtual A&& clone() && = 0;

		virtual void foo1(int k)
		{
			cout << 1;
		}

		virtual void foo1(double a)
		{
			cout << 2;
		}

		virtual void foo1(string s)
		{
			cout << "s";
		}

		virtual void print() = 0;//has to be overridden
		//no variable can be created with type A
		//this class is purely abstract as long as it 
		//contains such a function
		
		//destructor must be virtual in order to be dervied 
		//correctly
		//if a base has a non-virtual destructor, derived
		//class destructors have undefined behavior
		//as we defined the destructor, no move would be
		//generated
		virtual ~A() = default;
};

class B : A
	  //default access - public, i.e. inherited public 
	  //members become public in B
	  //protected remains protected
	  //derived-to-base conversion may be used only if public
	  //members of base are accessible
	  //i.e. users can use only public
	  //member functions can use anything
	  //derived can use only protected
{
	//B default constructor uses A default constructor to construct
	//base parts of B, and then it uses its own in-class initializers
	//to initialize the rest
	//
	//the same is applied to copy-move and other shit like that
	//derived uses the corresponding function from the previous
	//class in heirarchy
	private:
		using A::usingExample;//now usingExample is private
		//can only be used on accessible members
	public:
		//clone funcitons
		//they can be used in order to create new objects with the same
		//values and to preserve inhertiance features
		const B& clone() const & override
		{
			return B(*this);
		}

		B&& clone() && override
		{
			return std::move(*this);
		}

		using A::A; //not only causes the constructors to be visible, but also generates code that implements all the 
		//constructors for B, with the same parameters as in A, members of B are default initialized
		//also, it doesn't change the access level of inherited constructors, constexpr and explicit are unchangeable too
		//if some inherited constructor has the same parameters as an existing one - the one created in current class
		//will be used
		//default, copy and move constructors are not inherited at all
		using A::foo1;

		B(const B &b) : A(b) //generated version does this
				//if we want to declare our own
				//we should call base constructor
				//explicitly
		{
		}

		B& operator = (const B &b)
		{
			A::operator=(b);//calling the operator explicitly
			return *this;
		}

		virtual void print() override
		{
			cout << a << " " << a;
		}

		~B()
		{
			//here, we must deallocate only the data-fields
			//pertaining to B, ~A is called automatically
		}
};
//friendship is not inhertied

struct C : A //private inheritance by default
{
	void print()
	{
		cout << usingExample;
		//name lookup continues through the whole heirarchy until
		//the needed name is found
	}
};

class someRandomContainer //container for elements of different types
{
	public:
		void add(const A &a) // copy an element
		{
			ms.insert(make_shared<A>(a.clone()));
			//uses clone function to create an object with the same values
			//preserves inheritance
		}

		void add(A &&a) // move an element
		{
			ms.insert(make_shared<A>(a.clone()));
		}

		void printAll()
		{
			for (auto e : ms)
			{
				e->print();
			}
		}
		multiset<shared_ptr<A>> ms;
};

int main()
{
	//object-oriented programming
	//incapsulation, polymorphism and inheritance
	//
	//inherited classes can be passed as initializer to references or
	//pointers to base classes.
	//in this case, inherited versions will be used while the class is base
	//can pass both Query and RangeQuery
	cout << siftVector({0, 0, 1, 2, 3}, Query()) << endl;	
	cout << siftVector({1, 2, 3, 5, 31, 43, 23, 11, 4}, RangeQuery(3, 15));

	//two types are typically distinguished:
	//dynamic type - not know until runtime
	//static type - supposed type when compiling
	//when we call siftVector, static type is always Query, but 
	//dynamic type is RangeQuery in the second call
	//and parameter is initialized being aware of only the Query part of RangeQuery
	//there is no conversion from Base to Derived
	return 0;
}
