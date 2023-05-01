#include <iostream>
#include <cassert>
#include <cmath>

/*----------------------------------------------------------------------------------
Vector
----------------------------------------------------------------------------------*/
using namespace std;
class Vector {
    private : 
    
    double * M_data; int M_size;

    
    public :

    //Construction
    Vector(int size, double v = 0);  //constructeur ? on est pas obligé de mettre v
    Vector(Vector const &v); //copie de vecteurs
    int size() const; //{return M_size;}
    void affiche();
    
    //delete operator
    ~Vector();
    
    //overload operators 
    Vector& operator =(Vector const &v);
    double& operator [](int i); //const{return M_data[i];}
    //Rmq : - [] est unaire (il prend un seul argument)
    //-Operator : Effectue un operation. Unaire : Effectue une operation
    //sur un seul argument. Binaire : Effectue une operation sur deux
    //argument etc..
    //- L'opérateur [] fournit la i-ième (-1) valeur du vecteur
    //souhaité. Ici nos vecteur sont des doubles, donc la fonction 
    //opetaor+ renvoie un double, elle est donc du type double.. 
    double operator[](int i) const; //{return M_data[i];}
    //C'est une définition inline
    friend Vector operator+(const Vector&);
    friend Vector operator-(const Vector&);
    friend Vector operator+(Vector const&, Vector const &);
    friend Vector operator-(Vector const&, Vector const &);
    friend Vector operator*(double , const Vector &);
    friend Vector operator*(const Vector&, double);

    friend double dot(const Vector&, const Vector&);
    double maxnorm() const;// le const à la fin veut dire que la fonction peut travailler sur des const, mais pas obligatoirement un const en arg
    double twonorm() const;
    Vector& operator+=(const Vector& vec);
    Vector& operator-=(const Vector& vec);

    //Le terme ami c'est pour donner l'accès au membres privées
    //Une fonction ami est une fonction indé

    //Les Class::foo c'est pour les fonctions membres


    //overload of <<
    friend std::ostream& operator << (std::ostream&, const Vector&); 
};
Vector::Vector(int size,double value){
    cout << " "<< endl;
    M_size= size;
    M_data= new double[size];
    //cout << "Constructeur: allocation du tableau: " << M_data << endl;
    for (int kk=0; kk<M_size;++kk){
        M_data[kk]=value;
    }
}
Vector::~Vector(){
    //cout << "destruction du vecteur: " << M_data << endl;
    delete[] M_data;
}
void Vector::affiche(){
    cout << " "<< endl;
    cout << "Les composantes du vecteur sont " <<endl;
    cout << " "<< endl;
    for (int ii=0;ii<M_size;++ii){
        cout << "v["<< ii+1 << "] " << M_data[ii] << endl;
    }
    cout << " "<< endl;
}
Vector::Vector(Vector const &v) {
    v.M_size==0? M_data = nullptr : M_data = new double[v.M_size];
    M_size= v.M_size;
    //cout << "Copy constructor: allocation du vecteur: " << M_data << " de taille ";
    //cout << " " << endl;
    for (int kk=0;kk<M_size;++kk) M_data[kk]=v.M_data[kk];
}
Vector& Vector::operator=(Vector const&v){
    if (this!= &v){
        delete[] M_data;
        M_data= new double[M_size=v.M_size];
       // cout << "Assign du vecteur: "<<v.M_data<<"\n";
        for(int kk=0;kk<M_size;++kk) {
            M_data[kk]=v.M_data[kk];
        }
        cout << " "<<endl;
    }
    return *this;
}
double& Vector::operator[](int i){return M_data[i];}
double Vector::operator[](int i)const{return M_data[i];}
int Vector::size() const {
    return M_size;
}
std::ostream& operator<< (std::ostream& s, const Vector& v){
        using std::endl;
        for(int i=0; i<v.M_size;i++){
        s << "v["<< i <<"] "<< v[i] << endl;
        }
        return s;
}
Vector operator+(const Vector& vv){
    return vv;
}
Vector operator-(const Vector& vv){
    Vector tmp(vv.size());
    for(int ii=0;ii<vv.size();++ii) tmp[ii]=-vv[ii];
    return tmp;
}
Vector operator+(const Vector& v1, const Vector& v2)
{
    if(v1.size() == v2.size())
    {
        Vector tmp(v1.size());
        for(int ii=0; ii<v1.size(); ++ii) tmp[ii] = v1[ii] + v2[ii];
        return tmp;
    }
    else{
        cout << "operator+ : vectors dimensions do not match" << endl;
        exit(0);
    }
}
Vector operator-(const Vector& v1, const Vector& v2)
{
    if(v1.size() == v2.size())
    {
        Vector tmp(v1.size());
        for(int ii=0; ii<v1.size(); ++ii) tmp[ii] = v1[ii] - v2[ii];
        return tmp;
    }
    else{
        cout << "operator- : vectors dimensions do not match" << endl;
        exit(0);
    }
}
Vector operator*(double a, const Vector& v){
    Vector tm(v.M_size);
    for(int i = 0; i<v.M_size ; i++){
        tm[i] = a*v[i];
        return tm;
    }  
}
Vector operator*(const Vector& vec, double scalar){
    Vector tm(vec.M_size);
    for(int i = 0; i<vec.M_size ; i++){
        tm[i] = scalar*vec[i];
        return tm;
        }
    }
double dot(const Vector& v1, const Vector& v2) {
    if ( v1.M_size != v2.M_size){
        cout << "Bad vec size"<< endl;
        exit(0);
    }
    double tm = v1[0]*v2[0];
    for(int i=1; i <v1.M_size; ++i) tm += v1[i]*v2[i];
    return tm;

}
Vector& Vector::operator+=(const Vector& vec){
    if (M_size != vec.M_size){
        cout << "operator += bad vec sizes" << endl;
        exit(0);
    }
    for (int i=0; i < M_size; ++i){
        vec.M_data[i+1] += vec.M_data[i];
        }

}
Vector& Vector::operator-=(const Vector& vec){
    if (M_size != vec.M_size){
        cout << "operator -= bad vec sizes" << endl;
        exit(0);
    }
    for (int i=0; i < M_size; ++i){
        vec.M_data[i+1] -= vec.M_data[i];
        }

}
double Vector::maxnorm()const {
    double max = abs(M_data[0]);
    for (int i=1; i< M_size; ++i){
        if (max<abs(M_data[i])){
            max = abs(M_data[i]);
        }
    }
    return max;

}
double Vector::twonorm()const{
    double nm = pow(abs(M_data[0]), 2);
    for (int i=1; i<M_size; i++){
        double vi = abs(M_data[i]);
        nm += vi*vi;
        }
    return sqrt(nm);

}
/*----------------------------------------------------------------------------------
Matrix
----------------------------------------------------------------------------------*/
class Abstract_Mat
{
    protected :
        int n_rows;
        int n_cols;

    public:
    int nrows(){return n_rows;};
    int ncols(){return n_cols;};
    Abstract_Mat(int size){n_rows = size; n_cols = size;};
    virtual Vector operator*(const Vector&) const = 0; 
    //Le =0, c'est pour dire que l'utilisateur n'a pas le droit
    //de créer des objets du type Abstract_Mat
    int Conjugate_Gradient(Vector& x, const Vector& b, double eps, int & iter);
    //virtual ~Abstract_Mat();
};
int Abstract_Mat::Conjugate_Gradient(Vector& x, const Vector& b, double eps, int 
& iter){
    if (n_rows != b.size()){
        cout << "CG : Full_Mat and vector sizes do not match" << endl;
    }

    const int maxiter = iter;
    Vector r = b - (*this)*x;
    Vector z = r;
    Vector p = z;
    double zr = dot(z,r);
    const double stp = eps*b.twonorm();

    if (r.maxnorm() == 0.0){
        eps = 0.0;
        iter = 0;
        return 0;
    }
    for (iter = 0; iter < maxiter; iter++) {     // main loop of CG method
        Vector mp = (*this)*p;                     // one Full_Mat-vector multiply
        double pap = dot(mp,p);                         // one of two inner products
        double alpha = zr/pap;                          // pap is 0 only when r is 0
        x += alpha*p;                              // update the iterative soln
        r -= alpha*mp;                             // update residual
        if (r.twonorm() <= stp) break;             // stop if convergence achieved

    //z = preconding(r,prec);                    // preconditioning
        z=r;
        double zrold = zr;
        zr = dot(z,r);                             // another of two inner products
        double beta= zr/zrold;                          // zrold = 0 only when r is 0
        p = z + beta*p;                           
        }
  eps = r.twonorm();
  if (iter == maxiter) return 1;
  else return 0;

}
/*----------------------------------------------------------------------------------
Matrix
----------------------------------------------------------------------------------*/
class Full_Mat : public Abstract_Mat
{
   private :
   double** values;
   public :
   Full_Mat(int size, double value=0.);
   Full_Mat (Full_Mat const &);
   int Conjugate_Gradient(Vector& x, const Vector& b, double& eps, int & iter);
   Full_Mat& operator=(const Full_Mat&);
   double* operator[](int i) const;
   friend ostream& operator<<(ostream&, const Full_Mat&);
   Vector operator*(const Vector &) const; 
   ~Full_Mat();
};
Full_Mat::Full_Mat(int size, double value):Abstract_Mat(size){
    n_rows = size;
    n_cols = size;
    values = new double*[n_cols];
    // ici values est un pointeur vers le 1er element du tableau de taille n_cols
    // en fait, values pointe vers tout le tableau, il est par défaut pointé vers le 
    // premier element, puis on peut parcourir le reste du tableau
    //Le plus important est d'avoir le 1er element du tableau
    for (int ii =0; ii<n_rows; ++ii){
        values[ii] = new double[n_rows];
    }

    for (int i_row =0; i_row<n_rows; ++i_row){
        for (int i_col =0; i_col<n_cols; ++i_col)
        {
            values[i_row][i_col] = value;
        }  //values[i] = *values +i 
    }
}
Full_Mat::Full_Mat(Full_Mat const &A):Abstract_Mat(A.n_rows){
    if(A.values == 0){values = nullptr;}
    else
    {
        n_rows = A.n_rows;
        n_cols = A.n_cols;
        // values = A.values //ne fonctionne pas
        values = new double*[n_cols];
        for (int ii =0; ii<n_rows; ++ii)
        {
            values[ii] = new double[n_rows];
        }
        for (int i_row =0; i_row<n_rows; ++i_row)
        {
            for (int i_col =0; i_col<n_cols; ++i_col)
            {
                values[i_row][i_col] = A.values[i_row][i_col];
            }  //values[i] = *values +i 
        }
    }

}
Full_Mat::~Full_Mat()
{
    for (int ii =0; ii<n_cols; ++ii)
    {
    delete [] values[ii];
    }
    delete [] values;
    // cout << "Destruction de la matrice "<< values << endl;

}
Full_Mat& Full_Mat::operator=(const Full_Mat& A){
    if (&A == this){
        return *this;
    }
    else
    {
        for (int i=0; i<n_cols; ++i){
            delete [] values[i];
        }
        delete [] values;
        n_rows = A.n_rows;
        n_cols = A.n_cols;
        values = new double*[n_cols];
        for (int ii =0; ii<n_rows; ++ii)
        {
            values[ii] = new double[n_rows];
            }
        for (int i_row =0; i_row<n_rows; ++i_row)
        {
            for (int i_col =0; i_col<n_cols; ++i_col)
            {
                values[i_row][i_col] = A.values[i_row][i_col];
                }  //values[i] = *values +i 
        return *this;
        }
        

    }

}
std::ostream& operator<< (std::ostream& s, const Full_Mat& A){
        for(int i=0; i<A.n_rows;i++){
        s << "\n"<< i <<"-th row:   \n";
        for(int j = 0; j<A.n_cols; j++){
            s << A.values[i][j]<<" ";
            if (j%10==9)s << "\n";
        }
            s;
        }
        return s;
}
double* Full_Mat::operator[](int i) const{
    return values[i];
}
Vector Full_Mat::operator*(const Vector &v) const {
    if(v.size()==n_cols){
    Vector result(n_rows);
    for (int i=0; i<n_rows; ++i){
        for (int j=0; j<n_cols; ++j){
            result[i] += values[i][j]*v[j];
            }
        }
    return result;
    }
    else{
        cout << "operator* : bad Full_Mat/vector sizes" << endl;
        return 0;
    }
}




int main()
{
    
    int n = 20, m = 20;
    Full_Mat mat1(n,m);
    for(int i = 0; i<n; i++){
         for (int j = 0; j <m; j++){
             mat1[i][j] = n/(abs(i-j) + 1.0);
         }
    }
    Vector vec1(n);
    for (int i = 0; i <n; i++) vec1[i] = i;
    Vector res(vec1.size());
    // Vector res(vec1.size());
    Abstract_Mat* ptm = &mat1;
    double eps = 1.0e-14;
    int iter = 200;
    int ret = ptm->Conjugate_Gradient(res, vec1, eps, iter);
    if (ret==0) cout << "CG returned succefuly "<< endl;
    cout << iter << " iterations used" << endl;
    cout << "Residual in CG = "<< eps << endl;
    return 0;
}

