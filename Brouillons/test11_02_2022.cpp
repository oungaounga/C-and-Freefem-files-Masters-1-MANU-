#include <iostream>

using namespace std;


struct ture{
    int entier1;
    int entier2;
};

struct date{
    char jour[3];
    char mois[3];
    int annee;
};



enum prenoms {Omar, Djazia, Hamza, Amina, Zakaria};
struct id{
    char nom[10];
    char prenom[10];
    date date_de_naissance;
};

struct noeud{
    float x;
    float y;
    noeud * suivant;
};

void foo(ture*  a){
    a -> entier1 = 11; 
    a -> entier2 = 13 ;

}

void affiche (char * nPoint){
    cout << nPoint << endl;
}





int main(){
    ture ex1 {10, 103};
    foo(&ex1);
    //ture ex2 {3, 2};
    //cout << ex1.entier1 + ex2.entier2 << endl;
    //exemple.entier1 = 10;
    //cin >> exemple.entier2;
    cout << ex1.entier1<< endl;

    noeud point {13.0, 14.5, nullptr};
    noeud point2 {1.2, 3.5, &point};
    noeud point3 {0.3, 1.3, &point2};


    id moi {"Zouiche","Omar",{"05","09",1998}};
    // ture ex1 {23};
    cout << "Je m'appelle " << moi.nom << " " << moi.prenom;
    cout << " et j'ai "<< ex1.entier1<< " ans"<< endl;
    cout << "Je suis ne le : "<< moi.date_de_naissance.jour<< "/"<<moi.date_de_naissance.mois<<"/"<<moi.date_de_naissance.annee<<endl;
    cout << "Mes initiales sont "<< moi.nom[0]<<"."<<moi.prenom[0]<< endl;
    cout << "Mon nom comporte "<< sizeof(moi.nom)<<" lettres"<< endl;

    string message;
    message = "message test pour l'affichage";
    //char a = 'a';
    affiche("Hola hoo");


}

