//Topic 13:  Object Orientation: Inheritance

#include "bjDeck.h"
#include <random>

void bjDeck::addCardtoDeck(const std::shared_ptr<bjCards> &card) {
    deck.push_back(card);
}


std::vector<std::shared_ptr<bjCards>> bjDeck::getDeck() {
    return deck;
}

std::shared_ptr<bjCards> bjDeck::playFirstCardFromStack() {
    std::shared_ptr<bjCards> output = deck.front();
    collectPlayedCards(output);
    deck.erase(deck.begin());
    return output;
}


void bjDeck::reduceCardCounter() {
    cardCounter--;
}

void bjDeck::collectPlayedCards(const std::shared_ptr<bjCards> &card) {

    playedCards.push_back(card);
    reduceCardCounter();
}

void bjDeck::generatePlayCardsAndAddtoDeck(int maxDecks) {
    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    for (int i = 0; i < maxDecks; ++i) {
        //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
        for (int j = 0; j < 13; j++) {
            int value = j + 2;
            //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
            if (value > 10) {
                value = 10;
                //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
                if (j == 12) {
                    value = 11;
                }
            }
            //Topic 17: Object Orientation: Object Lifecycle
            addCardtoDeck(std::make_shared<bjCards>("hearts", getNumberX(j), value));
            addCardtoDeck(std::make_shared<bjCards>("bells", getNumberX(j), value));
            addCardtoDeck(std::make_shared<bjCards>("leaves", getNumberX(j), value));
            addCardtoDeck(std::make_shared<bjCards>("acorns", getNumberX(j), value));
        }
        deckShuffel();
    }
    deckShuffel();

    setCardCounter(static_cast<int>(deck.size()));
}

void bjDeck::deckShuffel() {
    //Topic 22: wichtige Algorithmen der C++-Standardbibliothek
    std::shuffle(deck.begin(), deck.end(), std::mt19937(std::random_device()()));
}

void bjDeck::setCardCounter(int i) {
    cardCounter = i;
}

std::string bjDeck::getNumberX(int x) {
    return numberList[x];
}


int bjDeck::getTotalValue() {
    int value = 0;
    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    //Topic 26: Häufige fehlerquellen -> Index out of Bounds wird durch for each abgefangen
    for (const std::shared_ptr<bjCards> &card : deck) {
        value += card->getValue();
    }
    return value;
}

void bjDeck::reshuffelIfNeeded(int trigger) {
    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    if (cardCounter <= trigger) {
        deckShuffel();
    }
}
