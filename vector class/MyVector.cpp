#include <bits/stdc++.h>
using namespace std;

class MyVector
{
    size_t vsize, vcap;
    int *vec;

public:

    MyVector (const size_t sz = 0, const int value = 0)
    {
        vsize = sz;
        vcap = 8;

        while (vcap < sz) vcap *= 2;

        vec = new int[vcap];

        for (int i = 0; i < sz; i++) vec[i] = value;
    }

    MyVector (const MyVector& Vi)
    {
        vsize = Vi.vsize;
        vcap = Vi.vcap;

        vec = new int[vcap];

        for (size_t i = 0; i < vsize; i++) vec[i] = Vi.vec[i];
    }

    ~MyVector ()
    {
        delete[] vec;
    }

    size_t size() const
    {
        return vsize;
    }
    size_t capacity() const
    {
        return vcap;
    }
    bool empty() const
    {
        if(vsize==0) return true;
        else return false;
    }

    void recap(size_t new_cap)
    {
        if (vsize >= vcap)
        {

        if (vcap == 0) new_cap = 1;
        else new_cap = vcap * 2;

        int* temp = new int[new_cap];

        for (size_t i = 0; i < vsize; i++)
        {
            temp[i] = vec[i];
        }

        delete[] vec;

        vec = temp;
        vcap = new_cap;
        }
    }

    void push(int value)
    {
        if(vsize==vcap) recap(vcap *= 2);

        vec[vsize] = value;
        vsize ++;
    }
    void pop()
    {
        if(vsize >= 1)
        {
            vsize--;
        }
    }

    int& back()
    {
        if(vsize==0)
        {
            cout << "Prazen e vektorot";
        }
        else
        {
            cout << vec[vsize - 1];
        }
    }
    int& at(const size_t index)
    {
        if(vsize==0)
        {
            cout << "Prazen e vektorot";
        }

        if(vsize<index)
        {
            cout << "Ne postoi elementot, nadvor od goleminata na vektorot";
        }
        else
        {
            cout << vec[index];
        }
    }

    void Print() const
    {
        cout << "vector(" << vsize << ", " << vcap << "):" << endl;
        for(size_t i=0; i<vsize; i++)
        {
            cout<<vec[i]<<" ";
        }
    }
};

int main()
{
    MyVector v1;

    v1.back();
    cout << endl << endl;

    v1.push(1);
    v1.push(5);
    v1.push(3);
    v1.push(8);
    v1.push(10);

    cout << "Prvicen vektor: ";
    v1.Print();
    cout << endl << endl;

    cout << "Elementot so index 3 e ";
    v1.at(3);
    cout << endl << endl;
    cout << "Elementot na kraj e ";
    v1.back();
    cout << endl << endl;

    cout << "Size: " << v1.size() << endl;
    cout << "Capacity: " << v1.capacity() << endl;
    cout << "Empty: " << v1.empty() << endl << endl;

    MyVector v2(v1);
    //Kopiran vektor;

    v2.pop();

    for (int i = 1; i <= 5; i++)
    {
        v2.push(i * 10);
    }

    cout << "New Size: " << v2.size() << endl;
    cout << "New Capacity: " << v2.capacity() << endl << endl;;
    //Kapacitetot avtomatski se duplirase poradi recap funkcija;

    v2.at(12);
    cout<<endl<<endl;

    v2.pop();

    cout << "Vektorot posle site promeni e: ";
    v2.Print();
    cout<<endl;

return 0;
}

