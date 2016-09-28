#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Dog {
    string name_;
public:
    Dog() { cout << "Nameless() dog at: " << this << " created." << endl; name_ = "nameless()"; }
    Dog(string name) { name_ = "(" + name + ")"; cout << "Dog is created at: " << this << " from name: " << name_ << endl; }
    Dog(const Dog &d) { name_ = "[Copy constructed of " +
                d.name() + "]";
                        cout << "Dog at:" << this << " named " << name_ << " is copy constructed from: " << d.name() << endl;  }
    Dog& operator=(const Dog &d) { name_ = "{Copy assigned of " + d.name() + "}";
                                   cout << "Dog " << name_ << " is copy assigned from: " << d.name() << endl;
                                 return *this; }
    ~Dog() { cout << "dog is destroyed: " << name_ << endl; }
    void bark() { cout << "Dog " << name_ << " rules!" << endl; }
    inline string name() const { return name_; }
    inline void setname(string name) { name_=name; }
};

const Dog operator+(const Dog &lhs, const Dog &rhs)
{
    return Dog(lhs.name()+"+"+rhs.name());
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

Dog getDog()
{
    Dog r("Joey");
    cout << "Address of Joey: " << &r << endl;
    return r;
}

const Dog getDog(const Dog &d)
{
    return getDog();
    /*
    Dog r(d);
    cout << "Address of r: " << &r << endl;
    r.setname("Billy");
    return r;
    */
}

int getInt()
{
    int r=5;
    cout << "Address of r: " << &r << endl;
    return r;
}

void bar();
int main()
{
    bar();
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
