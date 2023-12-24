#include <iostream>
#include <string>
class Super
{
    public:
        std::string name;
        int v;
    Super()
    {

    }
    Super(std::string name, int v)
    {
        this->name = name;
        this->v = v;
    }
    Super operator =(const Super &obj)
    {
        this->name = obj.name;
        this->v = obj.v; 
        return *this;
    }
    Super operator +(const Super &obj)const
    {
        Super ob;

        ob.v = this->v + obj.v;
        return (ob);
    }
};
std :: ostream & operator << (std::ostream &os, const Super &data)
{
    os << data.name+" {with }";
    return (os);
}

int main()
{
    Super ob1("ali",55);
    std:: cout << ob1 << " end";
    return (0);
}