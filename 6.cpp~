#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

int k()
{
	static int ctr = 0;
	return ctr++;
}

void el(int f, ...)
{
	va_list ap;
	va_start(ap, f);
	int a1 = va_arg(ap, int);
	int a2 = va_arg(ap, int);
	int a3 = va_arg(ap, int);
	cout << a1 << " " << a2 << " " << a3 << endl;
	va_end(ap);
}

int *f1(int a[100])
{
	a[0] = 15;
	return a;
}

int (*f2(int (&a)[100]))[100]
{
	a[0] = 15;
	return (&a);
}


int main()
{
	//functions	
	//
	//types of arguments in a funciton must match parameters in a way initializer must match created variable
	//can declare xplicit void
	int f(void);

	//objects inside a {} scope are called automatic-objects, they exist after definition and until }
	//parameters are automatic objects 
	//built in types of unitialized objest have undefined values
	//
	//local static objects
	//see k()
	//static object is created only the first time control flows through the line, after that every call uses the same instatiation
	//if not initialized, it's value init, i.e. int would be 0
	//
	//function declarations: 
	//functions without body, aka function prototypes
	//prototypes should be in header files
	int fuasdf(int, string, int);//like that

	//some off-topic rambling
	//separate compilation:
	//g++ -c file.cpp 
	//generates file.o or obj
	//file.o may be used later for linking
	//g++ 1.o 2.o 3.o -o res
	
	//
	//functions can be called by reference or by value, depending on its parameters
	//parameters that are not changes should be passed by const reference to avoid wasting extra memory and operations
	//
	//top level consts are ignored when calling a function, so these two are basically the same and cause an error
	void fcn(const int);
	void fcn(int);
	//like in an ordinary initialization, we can initialize a low-level const from non const, but not vice versa, and plain reference must be initialized by the same type
	//
	//arrays as parameters
	//arrays are sneaky bastards that are always converted to pointers, and can't be passed by value, so these three bitches here
	int fcn(int *a);
	int fcn(int a[]);
	int fcn(int a[100]);
	//are freaking identical	
	//although we can use references to limit functionality
	int fcn(int (&a)[14]); // this asshole can be called only with an array of 14 ints as an arguemnt
	void fcn(int (*matrix)[10], int rows); //matrix is a pointer to the first row
	//compiler ignores the first dimension
	void fcn(int matrix[][10], int rows); //identical

	//main function parameters:
	//main(int argc, char **argv);
	//argv[0] is an empty string or filename of the program, the next are the parameters passed from cmd
	//varying number of arguments
	//two solutions for that
	//the first one is initializer list
	//values of such list are always const
	initializer_list<int> il1 = {1, 2, 3};
	initializer_list<int> il2(il1);
	il1.size();
	il1.begin();
	il1.end();
	//ellipsis parameters, look up
	//
	//return statement
	//
	//return values are used to initialize the result, just like args and params
	//note: one should never return reference or pointer to a local to the function object, that's an error, all local storage is freed
	//
	//returning a pointer to an array
	using arrT = int[10];
	arrT* func();//returns a pointer to an array
	int (*func2())[10];//the same 
	//and the lovely new standard introduced another way of declaring functions' return types
	auto func3() -> int (*)[10];//the same as func and func2
	

	return 0;
}
