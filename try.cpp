#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

void a(int &&k)
{
	cout << k;
}

template<typename F, typename T>
void foo(F f, T &&a)
{
	f(a);
}

int main()
{
	foo(a, 4);
	return 0;
}
