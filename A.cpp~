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
	//2.1 TYPES
	//signed and unsigned
	unsigned u1 = 42, u2 = 62;
	int i1 = 10, i2 = 82;
	cout << i1 - u1 << endl;// all signed values are converted to unsigned 
	cout << ((int)-5 < (unsigned)5) << endl; // comparisons are no exceptions
	//LITERALS
	//specifying types of literals
	{	
		4.0f; //float
		4.0l; //long double
		4u; //unsigned
		4l; //long
		4ll; //long long

		u'1'; //unicode char16_t
		U'1'; //unicode char32_t
		L'1'; //wchar_t
		u8"1";//utf-8 char
	}

	//INITIALISATION
	//{} initialization does not allow any loss of precision for
	//built-in types
	double a = 3.4123;
	//int b = {a};//compilation-error here
	int c = (a);//ok, but value is rounded

	//Declaration vs Definition
	//extern gives us a declaration without definition
	
	extern int i; //declaration without definition
	int j; //declafinition

	//pointers and references
	int *p = &j;
	int **p1 = &p;
	int **&k = p1;//read right to left - reference to pointer to pointer
	
	//const qualifier
	const int bufSize = 512;//const value must be initialized (just
	// like a reference, and cannot be changed
	// To declare a const varialbe that would be visible in all the 
	// files, one should use extern keyword
	//extern const int bufSize = 512;
	//To use it in other files, you should first declare it
	//extern const int bufSize;
	
	//const references are actually references to const
	//and can refer to temporary objects, lol
	const int &ref64 = 123.123;

	//pointers are similar
	double pie68 = 3.14;
	const double *ptr69 = &pie68;
	//although const pointers are declared differently
	const double *const ptr71 = &pie68;
	//read right to left - constant pointer to double const
	//1st const - low-level, 2nd - top-level
	//
	//when copying, top-level const is ignored, but low-lewel is not
	//we can convert non-const to const, but not vice-versa
	double *ptr77 = ptr71; //error

	//Constant Expressions
	//literals and const values that can be evaluated at runtime are constant expressions
	constexpr int ci81 = 14;//constexpr
	constexpr int ci82 = max(13, 43);//not a constant expression	
	//constexpr variables can be initialized by constexpr functions
	constexpr int *p84 = nullptr; //top-level const
	constexpr const int *p85 = &i;//constant pointer to const int
	return 0;
}
