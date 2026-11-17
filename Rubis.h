#include <iostream>
using namespace std;

//enum valeurRubis {un,deux,trois,quatre};
class Rubis{
    private:
        int valeur;
        Rubis(int v);
        friend class RubisDeck;
    public:
        operator int();
        void afficheRubis();
};

Rubis::Rubis(int val){
    if (val < 1 || val > 4 ){
        cout << "Cette valeur est invalide !" << endl; //S'assurer de ne rajouter que de 1 à 4 rubis
    }
    else{
        this->valeur = val;
    }  
}

Rubis::operator int(){
    return this->valeur;
}

void Rubis::afficheRubis(){ // SEE printing with cout << rubis (IDK)
    cout << "Le nombre de rubis est" << this->valeur << endl;
}
