/* CardDeck is a class that represents a deck of cards 
Its job is to create 25 combinations: 5 animals and 5 backgrounds*/

#ifndef DECKFACTORY_H
#define DECKFACTORY_H

#include <vector>
#include <algorithm>

template <class C>
class DeckFactory {

protected:
    // Le paquet contient des pointeurs vers les objets.
    std::vector<C*> cards;

    // Position de la prochaine carte à retourner.
    unsigned int next;

    // Constructeur protégé :
    // DeckFactory n'est pas créé directement dans main.
    DeckFactory() : next(0) {
    }

public:

    // Mélange le paquet.
    void shuffle() {
        std::random_shuffle(cards.begin(), cards.end());

        // Après avoir mélangé, on recommence au début.
        next = 0;
    }


    // Retourne la prochaine carte/rubis.
    // Retourne nullptr s'il n'y en a plus.
    C* getNext() {

        if (isEmpty()) {
            return nullptr;
        }

        return cards[next++];
    }


    // Retourne vrai s'il ne reste plus rien à prendre.
    bool isEmpty() const {
        return next >= cards.size();
    }


    // Libère les objets créés dynamiquement.
    virtual ~DeckFactory() {

        for (C* card : cards) {
            delete card;
        }
    }
};

#endif