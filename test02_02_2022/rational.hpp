
class Rational{
    public :
        Rational(int num, int den);
        Rational(int num);
        Rational();
        //overload
        Rational& operator =(Rational const &);


        friend Rational& operator -(Rational const &); //cette fonction n'est pas 
        // une fonction membre de rational


        friend Rational& operator-(Rational const &, Rational const &); 
        //cette fonction n'est pas
        //opérateur binaire, reçoit deux arguments 




        //copy constructor
        Rational(Rational const &);

        // void set(int num, int den);
        int den() const; //une autre fonction
        int num() const; //une autre fonction

        //destructor (déclaration) 
        ~Rational();
    private :    
        int M_n;  //variables qu'on peut pas changer 
        int M_d;
        void M_normalize();
};
//Tout ce qui est déclaration on le garde ici !
