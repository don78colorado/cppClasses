#include <iostream>
#include <string>
#include <memory>
#include "Dog.h"

using namespace std;

void foofoo()
{
    Dog James("James");
    passByValue(James);
    passByReference(James);
    cout << "\n";
    Dog Wily("Wily");
    cout << "Calling returnConstByValue\n";
    Wily = returnConstByValue(James);  // copy assigned as expected
    cout << "Calling returnConstByReference\n";
    Wily = returnConstByReference(James);  //copy assigned as expected
    cout << "Address of James: " << &James << endl;
    cout << "Address of Wily: " << &Wily << endl;
    cout << "Initializing Joe from returnConstByValue with James\n";
    Dog Joe(returnConstByValue(James));    // copy constructed as expected
    cout << "Initializing Barbie from returnConstByReference with James\n";
    Dog Barbie(returnConstByReference(James));  //copy constructed as expected
    cout << "\n\n\n";
    Dog e(returnLocalObjectByValue()); //not expected - was expecting copy constructed
    //Dog d(returnLocalObjectByReference());  // crashes as expected
    cout << "\n\n\n";
}

void foo()
{
    shared_ptr<Dog> p(new Dog("Gunner"));
    {
        shared_ptr<Dog> p2 = p;
        p2->bark();
    }
    p->bark();
}

int getInt()
{
    int r=5;
    cout << "Address of r: " << &r << endl;
    return r;
}

void bar();
void barbar();

int main()
{
    //bar();
    //foofoo();
    barbar();
}

void barbar()
{
    Dog Johnny("Johnny");
    Dog Johnny2(Johnny); // same as Dog Johnny2 = Johnny;
    Dog &Johnny3(Johnny); // same as Dog &Johnny3 = Johnny;
    Johnny2.setname("Johnny2");
    Johnny3.setname("Johnny3");
    Johnny.bark();
    Johnny2.bark();
    Johnny3.bark();
}

void bar()
{
    Dog a("a");
    Dog b("b");
    Dog c("c");
    Dog d("Gunner");
    Dog e(d);
    Dog f=e;
    Dog g("Spark");
    Dog h;
    h = d + g;

    d.bark();
    e.bark();
    f.bark();
    g.bark();
    h.bark();

    cout << "\n\n\n";
    Dog j;
    j = a+b+c+d;
    j.bark();
    cout << "\n\n\n";

    cout << "getDog(d);\n";
    getDog(d);

    cout <<"\nDog k = getDog(g);\n";
    Dog k = getDog(g); // this is a special exception, k BECOMES the temp object
    cout << "Address of k: " << &k << endl;
    k.bark();
    cout << "\nDog l(\"l\");\n";
    Dog l("l");
    cout << "Address of l: " << &l << endl;
    l = getDog(g);     // copies by value using copy assignment operator, then destroys the temp object
    cout << "Address of l: " << &l << endl;
    l.bark();

    cout << "\nDog m(getDog(g));\n";
    Dog m(getDog(g)); // same situation as k...why?
    cout << "Address of m: " << &m << endl;
    m.bark();

    // l is being assigned, so it's using copy assignment operator as expected.
    // k is being initialized?  seems like it's &k=r and for some reason r is not being deleted
    // m seems like it's being copy constructed with an object returned from getDog but it's not, - m is just assigned to r, no construction happened.  it's basically &m=getDog();
    cout << "\n\n\n";
    int i = getInt();
    cout << "address of i: " << &i << endl;
    cout << endl;
    int ii(getInt());
    cout << "address of ii: " << &ii << endl;
    cout << endl;

    Dog n(getDog()+getDog()); // seems like this syntax n is (initialized?) to the object inside ().  Dog n(x) seem slike &n=&x or maybe *n=*x
    n.bark();
    n.setname("Joey");
    cout << "address of n: " << &n << endl;

    a+b;
    getDog();
    cout << endl;
    Dog o(a+b); // o never gets created.  a+b is created and o becomes it
    o = a+b;  // o is copy assigned to temp object a+b, then a+b is destroyed
    cout << "\n\n\n";
}
