#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

void deletion(int *&p)
{
	delete p;
	p = nullptr;
}

int main()
{
		
	//dynamic memory
	//dynamic objects have indefinite lifetime, and die only when explicitly killed
	//stack memory - used for non static memory of objects inside
	//functions, such objects get destroyed by compiler
	//
	//free store, heap memory
	//used for dynamic allocation
	//
	//to allocate such memory, we use new and delete
	//
	//but the lovely new standard offers some new objects for treating memory
	//
	//shared_ptr
	shared_ptr<int> ptr;//holds a null pointer	
	unique_ptr<int> uptr;
	//converts to bool - true if not null
	ptr.get(); //gets the pointer from inside this class
	//don't use get to initialize other smart pointers
	ptr.swap(ptr);
	make_shared<int>(42); //making shared ptr that points to 42
	int t = 123;
	shared_ptr<int> nptr(&t);
	shared_ptr<int> nptr2(ptr);
	nptr = nptr2;
	nptr.unique();//returns true if nptr.use_count() equals 1
	nptr.use_count(); //returns amount of pointers that point to the same memory
	shared_ptr<string> sptr = make_shared<string> (10, '9'); 
	//once shared_ptr reference count becomes zero, the memory is freed
	//
	//managing memory directly
	int *ptr1 = new int;//default initialized, so it's gonna be wtf
	int *ptr2 = new int(); //value initialized
	vector<int> *pv = new vector<int> {1, 2, 3, 4};//initialized
	auto p1 = new auto(t);//p1 is pointer to int that has the 
	//same value as t
	auto p2 = new const auto(t);//const poinnter to const object
	//if new runs out of memory, it throws bad_alloc exception
	//if you don't want this to happen, use nothrow
	auto p3 = new (nothrow) auto(t);
	delete p3;
	//p3 is now dangling pointer that points to the memory that once stored an object
	//smart pointer can be initialized with an ordinary pointer
	shared_ptr<int> shp1(p1);
	shared_ptr<int> shp2(uptr); // uptr becomes null, shp2 assumes
	//ownership of that object
	shared_ptr<int> shp3(p1, deletion);//deletion func will be used to free p1
	shp3.reset(); //frees current object, makes p null
	//can take parameters just like constructor
	shp3.reset(ptr1);
	//cannot implicitly initialize shared_ptr with standard pointers
	shp3 = new int(123); //error

	//unique_ptr
	unique_ptr<int> up(new int(12));
	up = nullptr; //deletes the current object
	up.release(); //relinquishes the current object
	//returns the pointer 
	up.reset(); //deletes the object
	up.reset(ptr);//deletes the object and sets the pointer
	unique_ptr<int> up2(up.release());
	unique_ptr<int, delFunctionType> up3(new int(42), delFunction);

	//weak_ptr
	//can point to an object of shared_ptr
	weak_ptr<int> wp(shp1);
	wp.reset(); //makes null
	wp.use_count(); //return use count of corresponding shared ptr
	w.expired(); //return true if use count is zero
	w.lock(); //if expired is true, returns null shared ptr, otherwise
	//return shared ptr that points to the same object
	
	//dynamic arrays
	int *ptrarr = new int[132]; //returns pointer to the first element of the array, and allocates 132 elements of int
	//default initialized
	int *ptr2 = new int[132](); //value initialized
	int *ptr3 = new int[3]{1, 2}; //just like ordinary vector
	int *ptr4 = new int[0]; //ok, but can't be dereferenced
	delete[] ptr2;
	shared_ptr<int[]> shp4(new int[32], [](int *p){ delete[] p;});
	//shared ptr does not provide default deleter
	unique_ptr<int[]> uptr4(new int[10);
	//unique ptr does
	//cannot use range for or begin() end()
	
	//allocator class	
	allocator<int> al;
	int *ptrwtf = al.allocate(4);//alocates 4 ints
	al.deallocate(ptr2, 4);//deallocate 4 ints beginning at ptr2
	al.construct(ptr2, 12);
	al.destroy(ptr2); //destorys the pointer
	//alloc funcitons
	uninitialized_copy(ptr3, ptr3 + 2, ptr4);
	uninitialized_fill_n(ptr3, 3, 123);

	return 0;
}
