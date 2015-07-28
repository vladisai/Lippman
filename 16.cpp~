#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

	//TEMPLATES
	//
	//template arguments can be types
	//and not types
	//non-types must be constant expressions when passed
	//

template<int a> void foo()
{

}

int a;
foo<a>(); //error, a is not a constexpr

template<typename T> class A;
template<typename T> class B;

template<typename T = int>  //arguments can be default, must write A<> a
class A
{
	//name T can't be reused
	friend class B<T>; //A<T> can access only B of the same type - one-to-one friendship
	//can also make our own T a friend
	friend T;
	public:
		template<typename D> bool cmp(D a, D b); //template function inside a template class

		static int a; //A<int> and A<double> will have different versions of a
		A ret() // note: this is not necessary to write A<T>, when inside the scope compiler infers that it is A<T>
		{
			return *this;
		}

		int reta()
		{
			//what is T::size_type, a variable or a type?
			//compiler assumes that it is a variable
			//to explicitly tell it that it is a type we should use typename word
			T::size_type * p;
			typename T::size_type *p; //now compiler knows that it is a type
		}
};

template<typename T>
template<typename D>
bool A<T>::cmp(D a, D b) //that's how we define a template function outside the scope
{
	return a < b;
}

template<typename T>
int A<T>::a = 0; //definition

template<typename T>
class B
{
	public:

};

typedef pair<int, int> pint; 
template<typename T> using twin = pair<T, T>;
//now we can do that
twin<int> tint;

//each file can have its own instantiation of a class with the same type
//it causes some overhead for large systems
//to avoid this, we can use declarations
extern template class std::vector<string>;//declaration and definition
template void foo<10>(); //declaration

//template deduction
//very limited amount of conversions is applied to templates
// 1.top level const is ignored
// 2.array or function to pointer conversions
// no other conversions, no derived to base, no int to float

template<typename T> T fobj(T, T);
template<typename T> T fref(const T&, const T&);
const string s1, s2;
int a[20], b[31];

fobj(s1, s2); //const is ignored
fobj(a, b); // int* is instantiated
fref(a, b); // oops, types don't match
//explicit arguments
fobj<int*>(a, b);
template<typename T1, typename T2, typename T3> T1 fooo(T2, T3);
fooo<int>(1, 2);
//templates are matched left to right
template<typename T1, typename T2, typename T3> T3 fooo(T2, T1);
//we would have to always specify the thee types
fooo<int, int, int> fooo(1.0, 2.4);
//note: it is no longer necessary to have ints, if you specify
//the template types explictily, then normal conversion rules apply

//if the return type can't be known, but it depends on arguments
//we can use trailing return and decltype
template<typename It>
auto foo(It begin, It end) -> decltype(*begin)
{
	return *begin;
}

//type transformation templates
//implemented in type_traits header

remove_reference<T>;
add_const<T>;
add_lvalue_reference;
add_rvalue_reference;
remove_pointer;
add_pointer;
make_signed;
make_unsigned;
remove_extent;
remove_all_extents;

//all these things have field type
//so you can use them as follows

template<typename T>
auto foo2(T iterator) -> remove_reference<decltype(*iterator)>::type
{
	return *iterator;
}

//we can use pointers to functions to store instantiated functions
//
//
template<typename T>
T compare(T a, T b)
{
	return a;
}

int (*ptrf)(int, int) = compare;//this would store an instantiation
//where T is int
//
//ARGUMENT deduction and references
//
template<typename T>
void f(T &p);//argument must be an lvalue
f(5);//this would cause an error
int a;
f(a); //ok, T would be int, not int&
//normal reference binding rules apply, all consts are low level
//
//rvalue references deduction
template<typename T>
void f2(T &&p);
f2(4); //that's alright
//T would be int again
int a;
f2(a); // this would be alright too, although
//t would be an int&
//what does that mean?
//a must be int&& &?
//references collapse together
//a& &&, a&& &, a& & all collapse to a&
//but a&& && collapses to a&&
//collapsing is possible for type aliasing and templates
//the only cases where it is possible to get a reference to a reference
//sooo
f2(a) is the same as
f2(int& &&);
//and this is the same as
f2(int &);
//as a consequence of this
//a function parameter that is an rvalue reference to a template type parameter can be bound to an rvalue
//if the argument is an lvalue, then the deduced type will be an lvalue reference

//we can use it to do some tricks
template<typename T> 
f5(T &&a)
{
	T b = a; //copy or reference?
	b = fcn(b); //changes a and b or only b?
	if (b == a) //true only if T is a reference
	{

	}
}

//how move works

template<typename T>
typename remove_reference<T>::type&& moveit(T &&a)
{
	return static_cast<remove_reference<T>::type&&>(a);	
	//note: static cast is allowed to convert lvalue to an rvalue reference
}

//how to retain information?
//e.g. when past an lvalue to make the reference stay
//just declare the variable as an rvalue reference
//
void f(int a, int &b)
{
	b = a;	
}

void g(int &&a, int &&b)
{
	cout << a << b;
}

template <typename F, typename T1, typename T2>
void flip2(F f, &&t1, T2 &&t2)
{
	//everything is preserved
	//consts and bla-bla
	f(t2, t1);
}

//but we can't call flip2(g, 2, 4) cuz T1 and T2 would be int while we need int&&
//for that purpose god gave us std::forward
//forward<T>(a) is T&& a
//so can we rewrite 

template <typename F, typename T1, typename T2>
void flip3(F f, &&t1, T2 &&t2)
{
	//everything is preserved
	//consts and bla-bla
	g(std::forward<T1>(t1), std::forward<T2>(t2));
}

//overloading with function templates
//any function that successfully completes deduction is a candidate
//if there is only one nontemplate function as good as all other template versions
//the nontemplate is called
//if there are only templates, the most specialized is called

//here are a couple of functions that can be used for debugging
//
template<typename T> string debug_rep(const T &t)
{
	ostringstream os;
	os << t;
	return os.str();
}

template<typename T> string debug_rep(T *t)
{
	ostringstream os;
	os << "pointer: ";
	if (t)
		os << debug_rep(t);	
	else
		os << "null pointer";
	return os.str();
}

const string *s = new string("");
debug_rep(s); //which one? the second one, it is more specialized, cuz not all the 
//types can be passed to it, unlike to the first version
//
//another thing - if we declare a function that overloads a template but don't define
//it will be instantiated without any complaining from compiler
//so if you want to have overloaded versions
//declare them before you declare the template
//
//VARIADIC Templates
//that's how you declare it
template <typename T>
void print(const T &t)
{
	cout << t;
}

template <typename T, typename ... Args>
void print(const T &t, const Args& ... rest)
{
	cout << T;
	cerr << sizeof...(Args) << endl; //outputs the number
	//of the additional parameters, 
	print(rest...);//recursive call
	//or we can write
	print(debug_rep(rest)...); //this would call debug_rep and print
	//the returned value
}

//fowarding with variadic templates
template<class ... Args> void emplace(Args&&..)
{
	string *s = null;
	allocator<string> al;
	al.construct(s, std::forward<Args>(args)...);//forwards all the args
	//note: it expands both Args and args
}

//specialization
template<typename T> 
int compare(const T &a, const T &b)
{
	if (a == b)
		return 0;
	if (a < b)
		return -1;
	if (a > b)
		return 1;
}

//sepcial version for char *
template<>
int compare(const char* const &p1, const char* const &p2)
{
	return strcmp(p1, p2);
}
//this does not affect function matching, it simply instantiates the
//template instead of the compiler

//we can also specialize class templates
//the most popular is hash

namespace std
{
	template<>
	struct hash<vector<int>>
	{
		typedef size_t result_type;
		typedef vector<int> argument_type;
		size_t operator () (const vector<int> &v)
		{
			return v.size() ? v[0] : 0; //crappy hash, I know
		}
	};
}
//partial specializtions of class templates (not function template)
template <typename T>
class a
{
	typedef type T;
};

template <typename T>//this will be used for references
class remove_reference<T&>
{
	typedef type T;
};

template <typename T> //this one for rvalue references
class remove_reference<T&&>
{
	typedef type T;
};

//we can create special versions only for members

template<>
void Foo<int>::Bar() //it will be used only with Foo<int> instatiation
{
}

int main()
{
		
	return 0;
}
