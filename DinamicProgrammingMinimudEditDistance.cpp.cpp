#include <iostream>
#include <algorithm>
using namespace std;

int getMinimum(const int& a, const int& b, const int& c);

int main()
{

    string str1("trials"), str2("Zeil");

    int T[str1.length()+1][str2.length()+1];
    for (size_t i = 0; i < str1.length()+1; i++)
        for (size_t j = 0; j < str1.length()+1; j++)
            if (i == 0 and j == 0)
                T[i][j] = 0;
            else if (i == 0)
                T[i][j] = T[i][j-1] + 1;
            else if (j == 0)
                T[i][j] = T[i-1][j] + 1;
            else
                if (str1[i-1] == str2[j-1])
                    T[i][j] = T[i-1][j-1];
                else
                    T[i][j] = 1 + getMinimum( T[i][j-1], T[i-1][j], T[i-1][j-1] );

    cout << "The result is " << T[str1.length()][str2.length()];
    return 0;
}


int getMinimum(const int& a, const int& b, const int& c)
{
    if(a <= b and a <= c)
        return a;
    else if (b <= a and b <= c)
        return b;
    else if ( c <= a and c <= b)
        return c;
}
















