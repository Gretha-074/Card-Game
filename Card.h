#ifndef CARD_H
#define CARD_H

#include <string>

// Les cinq animaux possibles
enum FaceAnimal {
    crabe,
    pingouin,
    pieuvre,
    tortue,
    morse
};

// Les cinq couleurs d'arrière-plan possibles
enum FaceBackground {
    rouge,
    vert,
    mauve,
    bleu,
    jaune
};

// Déclaration anticipée.
// CardDeck pourra créer les Card grâce à friend.
class CardDeck;

class Card {
private:
    FaceAnimal animal;
    FaceBackground background;

    // Constructeur privé :
    // seulement CardDeck pourra créer des cartes.
    Card(FaceAnimal a, FaceBackground b);

    friend class CardDeck;

public:
    // Conversion d'une Card vers son animal
    operator FaceAnimal() const;

    // Conversion d'une Card vers sa couleur d'arrière-plan
    operator FaceBackground() const;

    // Une carte est représentée sur 3 rangées
    int getNRows() const;

    // Retourne une rangée de l'affichage 3 x 3 de la carte
    std::string operator()(int row) const;

    // Getters optionnels
    FaceAnimal getAnimal() const;
    FaceBackground getBackground() const;
};

#endif