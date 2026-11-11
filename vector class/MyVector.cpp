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
            cout << "Празен е векторот";
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
            cout << "Празен е векторот";
        }

        if(vsize>index)
        {
            cout << "Не постои елементот, надвор од големината на векторот";
        }
        else
        {
            cout << vec[vsize - 1];
        }
    }

    void fit ()
    {
        recap(vsize);
    }

    void PrintVector() const
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



return 0;
}
