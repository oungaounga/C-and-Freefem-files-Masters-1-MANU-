#include <iostream>
using namespace std;




class Rational{
    public :
        void set(int num, int den){M_n = num; M_d = den;}
        int den() const {return M_d;}
        int num() const {return M_n;}
    private :
        int M_n;
        int M_d;
};