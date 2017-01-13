#ifndef DOG_H
#define DOG_H

#include <string>
#include <iostream>

using namespace std;
class Dog {
    std::string name_;
public:
    Dog() { std::cout << "Nameless() dog at: " << this << " created." << endl; name_ = "nameless()"; }
    Dog(std::string name) { name_ = "(" + name + ")"; std::cout << "Dog is created at: " << this << " from name: " << name_ << endl; }
    Dog(const Dog &d) { name_ = "[Copy constructed of " +
                d.name() + "]";
                        std::cout << "Dog at:" << this << " named " << name_ << " is copy constructed from: " << d.name() << endl;  }
    Dog& operator=(const Dog &d) { name_ = "{Copy assigned of " + d.name() + "}";
                                   std::cout << "Dog " << name_ << " is copy assigned from: " << d.name() << endl;
                                 return *this; }
    ~Dog() { std::cout << "dog is destroyed: " << name_ << endl; }
    void bark() { std::cout << "Dog " << name_ << " rules!" << endl; }
    inline std::string name() const { return name_; }
    inline void setname(std::string name) { std::cout << name_ << "\'s name is set to " << name << endl; name_=name; }
};

const Dog operator+(const Dog &lhs, const Dog &rhs)
{
    return Dog(lhs.name()+"+"+rhs.name());
}

void passByReference(const Dog &d)
{
    cout << d.name() << " at " << &d << " is passed by value\n";
}
void passByValue(Dog d)
{
    cout << d.name() << " at " << &d << " is passed by reference\n";
}

const Dog &returnConstByReference(const Dog &d)
{
    return d;
}

Dog returnConstByValue(const Dog &d)
{
    return d;
}

Dog returnLocalObjectByValue()
{
    Dog d("Local");
    return d;
}

Dog getDog()
{
    Dog r("Joey");
    cout << "Address of Joey: " << &r << endl;
    return r;
}

const Dog getDog(const Dog &d)
{
    Dog r(d);
    cout << "Address of r: " << &r << endl;
    r.setname("Billy");
    return r;
}


#endif
