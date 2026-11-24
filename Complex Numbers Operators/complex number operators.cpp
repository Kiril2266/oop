#include <bits/stdc++.h>
using namespace std;

class cpx
{
    public:
    float re;
    float im;

    cpx(float re = .0f, float im = .0f) : im(im), re(re) {}
    cpx(const cpx& og) : re(og.re), im(og.im) {}

    void print()
    {
        cout << this->re;
        if(this->im > 0)
        {
            cout << "+";
        }
        cout << this->im << "i";
    }
};

cpx operator +(cpx x, cpx y)
{
    cpx rez(x);
    rez.re += y.re;
    rez.im += y.im;
    return rez;
}

cpx operator -(cpx x, cpx y)
{
    cpx rez(x);
    rez.re -= y.re;
    rez.im -= y.im;
    return rez;
}

cpx operator *(cpx x, cpx y)
{
    cpx rez;
    rez.re = (x.re * y.re) - (x.im * y.im);
    rez.im = (y.im * x.re) + (y.re * x.im);
    return rez;
}

cpx operator /(cpx x, cpx y)
{
    cpx rez;
    rez.re = ((x.re * y.re) + (x.im * y.im)) / ((y.re * y.re) + (y.im * y.im));
    rez.im = ((x.im * y.re) - (x.re * y.im)) / ((y.re * y.re) + (y.im * y.im));
    return rez;
}

float operator ~(cpx n)
{
    return sqrt((n.re * n.re) + (n.im * n.im));
    //modul
}

int main()
{

float re1, im1, re2, im2;

cout << "Vnesi go prviot kompleksen broj (realen i imaginaren del):" << endl;
cin >> re1 >> im1;
cpx x(re1, im1);

cout << "Vnesi go vtoriot kompleksen broj (realen i imaginaren del):" << endl;
cin >> re2 >> im2;
cpx y(re2, im2);
cout << endl;

cout << "Zbirot e:" << endl;
(x + y).print();
cout << endl << endl;

cout << "Razlikata e:" << endl;
(x - y).print();
cout << endl << endl;

cout << "Proizvodot e:" << endl;
(x * y).print();
cout << endl << endl;

if(re2!=0 || im2!=0)
{
cout << "Kolicnikot e:" << endl;
(x / y).print();
}
else
{
    cout << "Ne e mozno delenjeto";
}
cout << endl << endl;

cout << "Modulot na prviot e: " << ~x << endl << endl;
cout << "Modulot na vtoriot e: " << ~y << endl;

return 0;
}
