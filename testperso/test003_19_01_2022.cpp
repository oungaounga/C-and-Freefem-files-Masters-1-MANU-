#include <iostream>
#include <cmath>
//using namespace std;


int main() {
    using namespace std;
    string name;
    int a, b;
    cout << "Comment vous appelez vous ?" << endl;
    cin >> name;
    cout << "Donnez deux nombres entiers" << endl;
    cin >> a >> b;
    int sum = a + b;
    cout << name << " la somme de " << a << " et "<< b << " est : "<< sum << endl;
}
