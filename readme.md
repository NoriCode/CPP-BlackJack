
# Blackjack
## Disclaimer
I am not a nativ speaker and a person who rarely writes in english. Please inform me if you find a typo or some grammar issues.

This is my final C/C++ exam after a 4 months course.

I used [Clion](https://www.jetbrains.com/clion/) and anything that is included to clean my code and optimize some parts.

Use this program on your own risk.

Thanks to [Simon Struck](https://github.com/AnyTimeTraveler) for cleaning the repository and showing me how to clean my code.



## General Information

[Hochschule](https://en.wikipedia.org/wiki/Hochschule): [Hochschule Emden/Leer](https://www.hs-emden-leer.de/en/)

Faculties: [Informatik](https://www.hs-emden-leer.de/en/current-students/faculties/technology/study-programs/computer-science)

Supervising lecturer: [Prof. Dr. Carsten Link](http://www.technik-emden.de/~clink/)

Period of origin: summer semester 2020

## The Game

This [Rules](https://bicyclecards.com/how-to-play/blackjack/) used as a baseline for this Game, some rules are modified:
```
Regeln
    Cards:
        played with 6 Decks with french deck (2 - 10, B, D, K ,A)
        reshuffeld when 75 cards are left
    Input:
        only numbers

    Betting:
       beginning of each round
       More then 2
       Less then 500
       Less then your Chips

    Goal:
        Get a value of 21
        detailed conditions are down below

    First two cards:
        player
            both face up
        dealer
            first face up
            second face down


    Your Turn:
        hit = new card
        stand = no new card

    Payout:
        win:
            2 Times your bet
        tie:
            your bet
        loose:
            you loose your bet

    Card Values:
        2 = 2
        3 = 3
        4 = 4
        ...
        10 = 10
        B = 10
        D = 10
        K = 10
        A = 1 or 11

    Win conditions:
        P = Player Value
        D = Dealer Value
        W = Win
        T = Tie
        L = Loose

       +--------+-----------+--------+--------+
       |        | P < 21    | P = 21 | P > 21 |
       |--------|-----------|--------|--------|
       | D < 21 | P < D = L | W      | L      |
       |        | P = D = T |        |        |
       |        | P > D = W |        |        |
       |--------|-----------|--------|--------|
       | D = 21 | L         | T      | L      |
       |--------|-----------|--------|--------|
       | D > 21 | W         | W      | L      |
       +--------+-----------+--------+--------+

```
### Change a few rules
You can modify some rules in the "bjRuleController.cpp" file. 
   ```C++
   bjRuleController::bjRuleController() {
       dealerMaxPoints = 17;
       reshuffelTrigger = 75;
       numberOfDecks = 6;
       initChips = 1000;
       minBet = 2;
       maxBet = 500;
   }
```      

## Installation

```
$ ./build.sh
```

## Usage

```
$ ./blackJack.out
```
## How to play
### Important Information
You can only enter a number. You have to repeat your input if you enter a number that is not shown on your screen. The only exception to this is the end screen, here can you enter any number between 0 and 9.

### Start of the game
Enter 1 or 2 or 3 to choose one of these options.
```
Welcome to Blackjack
Your options are:
1 - Play
2 - Rules
3 - Exit
Your choice: 
```

### Bet Screen
You have to enter a Value between 2 and 500. The value has to be less than your chips. There is an other screen if you are not able to bet.

The Values are defined in the bjRuleController.h


```
------------------------------------------
		Next Action
------------------------------------------
You have 1000 chips, place your bet.
Your minimum bet is 2
Your maximum bet is 500
Place your bet: 
```

### Your turn
Displayed are your cards and the open card of the dealer.

You wont see this screen if your cards have a value of 21 or more. The value of your cards is calculated in the background. The exact value of the cards is not display because it would remove a the skill part of blackjack. The player has in this case a value of 13.


```
------------------------------------------
		Next Action
------------------------------------------
The open Card of the dealer is: 
bells, 9 
You have this Cards: 
bells, 5
acorns, 8 


Your options are
1 -> hit
2 -> stand
Your choice: 
```

### Hit
If you choose to draw another card this screen will repeat but with an additional card. The value of your ace is always calculated to be the best case for your round. The Player has in this case a value of 14.
```
------------------------------------------
		Next Action
------------------------------------------
The open Card of the dealer is: 
bells, 9 
You have this Cards: 
bells, 5
acorns, 8 
hearts, A 


Your options are
1 -> hit
2 -> stand
Your choice:
```


### Stand
This screen repeats with every card the dealer draws. He draws until he has a value of 17 or above. The dealer has in this case a value of 20.
```
------------------------------------------
		Dealer Turn
------------------------------------------
The Dealer has this cards: 
bells, 9 
acorns, A 
```
### Round end

```
You:
The cards have a value of: 16

Dealer:
The cards have a value of: 20




******************************************
		You lost.




------------------------------------------
		Next Action
------------------------------------------
Do you want to play a new round?
Any other Value brings you to the menu. 
0 - no
1 - yes
Your choice:
```

## Contributing
This project was just my exam and is in the best state I am able to programm. If you find any bugs left in the code or some better ways to solve some functions of the game. Create a pull request. I dont guarantee that I will look at them.

## Explaining some stuff
### bjCards
The Cards that are used in this game. Each Card has a "unique" combination of Symbol, number and value.

### bjDeck:
Here are the cards stored.

### bjHand:
Here are the bet from the player and his cards stored.

### bjPlayer:
This is the player and the dealer. Both use in most cases the same functions. The difference between player and dealer is that the dealer has always 0 chips.

### bjRuleController:
This is the place where the rules are stored. 

### blackJack:
This is the class where the game takes place.

### enums:
These are my enums, they are in an extra ".h" for convenience purposes.

### main:
The only reason this exist is that I needed a place to start the game. 

### playingCard:
This is just an Interface for a normal card, without any funtions.

## License
[MIT](https://choosealicense.com/licenses/mit/)
