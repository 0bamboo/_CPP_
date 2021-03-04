#include <iostream>
#include <stdio.h>
using namespace std;
class point
{
    public:
        point()
        {
            cout << "++const point " << endl;
        }

        ~point()
        {
            cout << "--const point" << endl;
        }

        int abs, ord;
};

int main()
{
    point a;

    a = point();

}