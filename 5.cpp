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
	//Statements
	;//empty statement
	1 + 2;//useless statement
	
	//dangling else
	int a = 5;
	if (a < 10)
		if (a < 5)
			cout <<"lol";
	else//this is for the a < 5, not a < 10
		cout << "omg";
	//else is always matched to the closest unmatched if
	//
	//switch statement
	//expression in switch is always converted to integral
	//execution begins with the first statement of that label
	a = 4;	
	switch (a)
	{
		case 1:
			cout << "more than or equal 1" << endl;
			//int k = 1;//if we initialize the variable here, we can't jump to any statement below
			int j;//it's ok, because j is not initialized, I don't understand wtf
		case 2:
			//j is not initialized here, must do something
			j = 15;
			cout << j;
			cout << "more than or equal 2" << endl; //if not breaking at each case, execution will continue to the next case
		case 3:
			cout << "more than or equal 3" << endl;
			break;
		case 4:
			cout << "more than or equal 4" << endl; //falls through 
		default:
			cout << "lol" << endl;
	}
	
	do
	{
		break;
	}while (true); //does and then checks, unlike ordinary while, which checks and then does

	//for statements
	//for (init; condition; expression);

	//jump statements
	//continue, break, goto, return
	//
	//break - terminates nearest loop or switch
	//continue - terminates current iteration of a loop and begins the next, does not affect switch
	//
	//goto
	end:int x = 0; x++; 
	     cout << x;
	     goto pastend;
	goto end;//will work indefinetly, if not for pastend
	int y = 0;
pastend:
	//like switch, goto can't jump from a place where a variable is not defined to a place where it is defined
	//but it can jump back over a definition
	//
	//try blocks
	//
	int b; //if throw is called inside a function, then function is searched for a catch, if it is not found, the function terminates, and catch is searched in caller function
	try 
	{
		cin >> a >> b;
		if (b == 0)
			throw runtime_error("can't divide by 0");
	}
	catch (runtime_error err)
	{
		cout << err.what();
	}
	//stdexcept classes:
	//exception
	//runtime_error
	//range_error
	//overflow_error
	//underflow_error
	//logic_error
	//domain_error
	//invalid_argument
	//length_error
	//out_of_range


	return 0;
}
