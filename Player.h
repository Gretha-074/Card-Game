#include <iostream>
#include <string>
#include <cstdlib>
#include "Rubis.h" 
using namespace std;

enum Side {TOP, BOTTOM, LEFT, RIGHT};

class Player{
private:
    string name;
    Side side;
    int rubis;
    bool active;
public:
    Player(string name, Side side);
    string getname() const;
    void setActive(bool);
    bool isActive();
    int getNRubies() const;
    void addRubis(const Rubis&);
    void setDisplayMode(bool endOfGame);
    Side getSide() const;
    void setSide(Side);

};
Player::Player(string n, Side s) {
    this->name = n;
    this->side = s;
    this->rubis = 0;
    this->active = true; // On met l'état par défault à actif, à la création
}
string Player::getname() const{
    return this->name; //Retourne le nom du joueur
}

void Player::setActive(bool actif_state){
  this->active = actif_state;
}

bool Player::isActive(){
    return this->active;
}

int Player::getNRubies() const {
    return this->rubis;
}

void Player::addRubis(const Rubis& r){
    Rubis rubisCopy = r;
    int valeurRubis = int(rubisCopy); // Conversion du Rubis en int grâce à l'opérateur de conversion
this->rubis = this->rubis + valeurRubis;
}

void Player::setDisplayMode(bool endOfGame){
    string position;
    switch (this->side)
    {
    case TOP: 
    position = "top"; break;
    case BOTTOM: 
    position = "bottom"; break;
    case LEFT: 
    position = "left"; break;
    case RIGHT: 
    position = "right"; break;

    default:
        break;
    }
    if (endOfGame == false){
        cout << getname() << " : " << position << " (active) " << endl;
    }
    else{
        cout << getname() << " : " << getNRubies << " rubies." << endl;
    }
}

Side Player::getSide() const{
return this->side;
}

void Player::setSide(Side s){
this->side = s;
}




