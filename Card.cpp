#include "Card.h"

// Constructeur privé
Card::Card(FaceAnimal a, FaceBackground b)
    : animal(a), background(b) {
}


// Conversion Card -> FaceAnimal
Card::operator FaceAnimal() const {
    return animal;
}


// Conversion Card -> FaceBackground
Card::operator FaceBackground() const {
    return background;
}


// Chaque carte occupe 3 rangées
int Card::getNRows() const {
    return 3;
}


// Retourne une rangée de la carte
std::string Card::operator()(int row) const {

    // Lettres utilisées pour représenter les animaux.
    // Majuscule parce que l'animal doit être affiché
    // en majuscule au centre de la carte.
    const char animalLetters[] = {
        'C',    // crabe
        'P',    // pingouin
        'O',    // pieuvre / octopus
        'T',    // tortue
        'W'     // morse / walrus
    };

    // Lettres utilisées pour représenter les couleurs.
    // Minuscules parce que le background est affiché
    // en minuscule.
    const char backgroundLetters[] = {
        'r',    // rouge / red
        'g',    // vert / green
        'p',    // mauve / purple
        'b',    // bleu / blue
        'y'     // jaune / yellow
    };

    char backgroundChar = backgroundLetters[background];
    char animalChar = animalLetters[animal];

    std::string result(3, backgroundChar);

    // L'animal apparaît seulement au centre,
    // donc sur la rangée 1.
    if (row == 1) {
        result[1] = animalChar;
    }

    return result;
}


// Getter pour l'animal
FaceAnimal Card::getAnimal() const {
    return animal;
}


// Getter pour le background
FaceBackground Card::getBackground() const {
    return background;
}