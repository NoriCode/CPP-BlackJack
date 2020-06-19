#ifndef CCPP_EXAM_PLAYCARDDECK_H
#define CCPP_EXAM_PLAYCARDDECK_H

class playCardDeck{
private:
    int cardCounter;
public:
    static void generateCards();
    int doStuff();
    void setCardCounter(int i) {
        cardCounter = i;
    }
    int getCardCounter(int i) {
        return cardCounter;
    }
};


#endif //CCPP_EXAM_PLAYCARDDECK_H
