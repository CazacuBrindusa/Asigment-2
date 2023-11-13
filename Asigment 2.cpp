#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cassert>
#include <string>
#include <cstring>

using namespace std;


//o clasa care sa lucreze cu siruri de chr
class Mystring
{
    char* stl;
    int len;
public:
//set, get
    char* getstl() { return this->stl; }
    int getlen() { return this->len; }

    void setstl(char* stl) { this->stl = stl; }
    void setlen(int len) { this->len = len; }

    Mystring();
    Mystring(char*, int);
    Mystring(const Mystring& m);
    Mystring& operator =(const Mystring& m);
    friend ostream& operator << (ostream& out, const Mystring& p);

    //destructor
    ~Mystring()
    {
        if (this->stl != NULL)
        {
            delete[] this->stl;
            this->stl = NULL;
        }
    }
};

Mystring::Mystring()
{
    this->stl = new char[2];
    strcpy(this->stl, "\n");
    this->len = 1;
    cout << "constructor fara parametrii" << endl;
}

//constructor cu 2 parametrii
Mystring::Mystring(char* stl, int len)
{
    this->stl = new char[len+1];
    strcpy(this->stl, stl);
    this->len = len;
    cout << "constructor cu 2 parametrii" << endl;
}

//copy constructor
Mystring::Mystring(const Mystring& m)
{
    this->stl = new char[m.len+1];
    strcpy(this->stl, m.stl);
    this->len = m.len;
    cout << "copy constructor" << endl;
}

//operator =
Mystring& Mystring:: operator =(const Mystring& m)
{
    if (this != &m)
    {
        if (this->stl != NULL)
        {
            delete[] this->stl;
            this->stl = NULL;
        }
        this->stl = new char[m.len+1];
        strcpy(this->stl, m.stl);
        this->len = m.len;
    }
    cout << "operator =" << endl;
    return *this;
}

ostream& operator << (ostream& out, const Mystring& p)
{
    out << "Sirul este: ";
    out << p.stl;
    out << endl << "Lungimea este: " << p.len << endl;
    return out;
}

int main()
{
//exemplificare in int main pt toate funct
//evidentiere apel constr cu toti param, cc, oper =
    Mystring a;
    char* stl = (char*)"abc";
    Mystring b(stl, 3);
    a = b;
    Mystring c(a);
    cout << "a" << endl << a << endl;
    cout << "b" << endl << b << endl;
    cout << "c" << endl << c << endl;
    return 0;
}