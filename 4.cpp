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
	//rvalues and lvalues
	//lvalue - value that can be used on the left side of = expression
	//rvalue - on the right
	//assignment requires lvalue on the left
	//address-of requires lvalue
	//dereference and subscript yield lvalues
	//iterator inc and dec yield lvalues
	//
	//decltype applied to an lvalue expression (other than a variable) yields a reference
	int a = 0;
	int *p = &a;	
	decltype(*p); // &int
	decltype(&p); // int**

	//4.1.3 order of evaluation
	//for binary operators, there is no way of knowing which side will be evaluated first
	cout << a << ++a; //undefined
	int i = f1() * f2(); //which one is first - who knows
	//the only operators that guarantee the order are && || , ?:
	a + b * c - d; // no guarantees as to the order of evaluation, but
	//it is guaranteed that b is multiplied by c, and a is added and d is subtracted from the result
	//precedence of operators
	//+a or -a
	//then a * b, a / b, a % b
	//ten a + b and a - b
	//when precedence levels are the same, operations group left to right
	//
	//Logical operators oreder, from first evaluated to last
	//!
	//< <= > >=
	//== !=
	//&&
	//||
	//The right side of && is evaluated only if the left is true
	//the right side of || is evaluated only if the left is false
	
	int val = 3;
	if (val == true) // false, because true is converted to int, i.e. 1
	//assignment operator is left associative, that means that
	//if there are several expressions with =, they get
	//executed from right to left
	int *p = &val;
	*p++; //will first increment, and then dereference
	//equal to *(p++);
	char str[10] = "ABACABA";
	char *b = str;
	while (b != end(str))
		*b = tolower(*b++); //undefined behavior, what is first? increasing the b, or assigning? no way of knowing
	//dereference is of lower precedence that . operator
	//so we have to parenthesize
	string *ps = new string();
	(*ps).empty();//not *ps.empty()
	cout << 10 < 5 ? 10 : 5; //fatal : cout << 10 will be compared

	//bitwise operators
	// ~
	// << >> note: right hand operand must be positive
	// &
	// ^
	// |
	// shift operators are of higher precedence than = < >, but of lower precedence, than + - / *
	//
	//sizeof operator returns size in bytes
	//it is right associative and has the same precedence as *
	sizeof pair<int, int>::first; // not necessary to instantiate
	//sizeof char is 1
	//size of reference is size of referenced object
	//size of pointer is size of pointer
	//size of array is size of the entire array, size of doesn't convert array to a pointer
	//size of vector does not inlucde not fixed memory
	//
	//comma operator
	//result of a comma expression is the rightmost expression
	1,2,3;//is 3

	//conversions
	//they happen in initializations, assignments, expressions of mixed types and in other situations
	//e.g. if double and int are added, all are converted to double
	//note: int will be converted to unsigned, not vice versa
	//however, if both signedness and size of variable differ, behavior is different
	//if values of unsinged fit in the larger type, unsinged is converted to signed
	//if not, signed is converted to unsigned
	bool      flag;         char           cval;
	short     sval;         unsigned short usval;
	int       ival;         unsigned int   uival;
	long      lval;         unsigned long  ulval;
	float     fval;         double         dval;
	3.14159L + 'a'; //  'a' promoted to int, then that int converted to long double
	dval + ival;    //  ival converted to double
	dval + fval;    //  fval converted to double
	ival = dval;    //  dval converted (by truncation) to int
	flag = dval;    //  if dval is 0, then flag is false, otherwise true
	cval + fval;    //  cval promoted to int, then that int converted to float
	sval + cval;    //  sval and cval promoted to int
	cval + lval;    //  cval converted to long
	ival + ulval;   //  ival converted to unsigned long
	usval + ival;   //  promotion depends on the size of unsigned short and int
	uival + lval;   //  conversion depends on the size of unsigned int and long	
	//other conversions
	//array to pointer
	int ia[10];
	int *ip = ia; // ia converted to *int
	//array is not converted in decltype, sizeof, typeid nad if used as operand of the address-of &
	//
	//non const can be converted to const (pointers and refs too)
	//
	//casts
	//static_cast, const_cast, dynamic_cast, reinterpret_cast
	static_cast<double> 1; //1.0
	const char c = '1';
	char &c2 = const_cast<char&>(c);//casts away the low-level const, lol
	//reinterpred_cast can mess with pointers
	char *p172 = &c2;
	string *s = reinterpret_cast<string*> (p172);//wtf is that?

	//operations precedence, complete talbe, omg
	//1.  ::
	//2.  . -> [] () 
	//3.  postfix++ postfix-- typeid explicit cast
	//4.  prefix++ prefix-- unary(~ ! - +) * & () sizeof new new[] delete delete[] noexcept
	//5.  ->* .*
	//6.  * / %
	//7.  + -
	//8. << >>
	//9. < <= > >=
	//10. == !=
	//11. &
	//12. ^
	//13. |
	//14. &&
	//15. ||
	//16. ? :
	//17. = *= /= %= ...
	//18. throw
	//19. , 

	return 0;
}
