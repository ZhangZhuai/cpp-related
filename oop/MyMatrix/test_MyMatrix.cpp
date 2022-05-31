#include "MyMatrix.cpp"
#include <iostream>
// cpp17
using std::cout, std::endl;

int main()
{
    MyMatrix<int> mymatrix1(3, 3);
    const MyMatrix<int> mymatrix2(3, 3);
    mymatrix1[1][1] = 1;
    // mymatrix2[1][1] = 1; immutablereference friend class
    auto res = mymatrix1 < mymatrix2;
    cout << res << endl;

    int tag = 32;
    for (int i = 2; i >= 0; --i)
    {
        for (int j = 2; j >= 0; --j)
        {
            mymatrix1[i][j] = tag++;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << mymatrix1[i][j] << " ";
        }
        cout << endl;
    }
    std::sort(mymatrix1.row_begin(0), mymatrix1.row_end(0));
    cout << "Sorted matrix" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << mymatrix1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}