
# Blackjack
## Vorwort
Das Program wurde mit [Clion](https://www.jetbrains.com/clion/) erstellt. Zustätzlich wurde ClangTidy verwendet um Teile des Codes zu optimieren. 

Verwendung auf eigene Gefahr. 

## Das Spiel

Diese [Regeln](https://bicyclecards.com/how-to-play/blackjack/) sind die Basis für diese Umsetzung von Blackjack. Einige Regeln wurden verändert. Die Regeln für diese Version von Blackjack sind folgende:
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
### Anpassen der Regeln
Einige Regeln können in der "bjRuleController.cpp" verändert werden. 
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

## Starten des Spiels

```
$ ./blackJack.out
```
## Beispielhafter Spielablauf
### Important Information
Du kannst nur Nummern eingeben. Bei eingabe einer Zahl die nicht zur Auswahl steht musst du deine Eingabe wiederholen. Mit Ausnahme vom Endscreen hier wird jede Nummer von 0 bis 9 akzeptiert

### Start des Spiels
Gebe 1 oder 2 oder 3 ein um eine der entsprechenden Optionen auszuwählen.
```
Welcome to Blackjack
Your options are:
1 - Play
2 - Rules
3 - Exit
Your choice: 
```

### Bet Screen
Du musst einen Wert zwischen 2 und 500 eingeben. Der Wert muss außerdem niedriger sein als die Gesamtanzahl deiner Chips. Solltest du nicht genug chips haben zum Wetten wird dir ein anderer Bildschirm angezeigt. 

Die Werte stehen in der "bjRuleController.h" 

```
------------------------------------------
		Next Action
------------------------------------------
You have 1000 chips, place your bet.
Your minimum bet is 2
Your maximum bet is 500
Place your bet: 
```

### Deine Runde
Es werden deine Karten und die offenen Karte des Dealers angezeigt.

Der Bildschirm wird dir nicht angzeigt wenn deine Karten einen Wert von 21 oder höher haben. Der Wert wird im Hintergrund berechnet. Damit das Spiel nicht zu stark vereinfacht wird bekommst du den Wert nicht angezeigt. Der Spieler hat in diesem Fall einen Wert von 13.


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
Wenn du dich dafür entscheidest eine Karte zu ziehen wird dir dieser Bildschirm angezigt. Der Wert deiner Karten ist immer für den best Case berechnet. Das heißt das Ass hat den Wert "1" wenn du über 21 kommen würdest. Der Spieler hat in diesem Fall den wert 14.
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
Dieser Bildschirm wird mit jeder neu gezogenen Karte des Dealers angzeigt. Der Dealer zieht bis er einen Wert von 17 oder höher hat. Der Dealer hat einen Wert von 20.
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

## Ein paar Erläuterungen
### bjCards
Die Karten die in diesem Spiel verwendet werden. Jede Karte hat eine "einzigartige" Kombination aus Symbol, Zahl und Wert.

### bjDeck:
Das Deck besteht aus der in der bjRuleController.h definierten anzahl an Spieldecks mit je 52 Karten.

### bjHand:
Die Karten und Wette des Spielers.

### bjPlayer:
Das ist der Spieler und der Dealer. Beide nutzen die selben Funktionen. Der unterschied besteht darin das der Dealer immer 0 Chips besitzt.

### bjRuleController:
Hier werden die Regeln des Spiels verwaltet. 

### blackJack:
Das ist das eigentliche Spiel.

### enums:
Hier stehen die Enums für das Spiel. Die sind der Einfachkeit halber ausgelagert.

### main:
Hier wird das SPiel gestartet 

### playingCard:
Ein Interface für die Normale Karten ohne Funktionen.

## License
[MIT](https://choosealicense.com/licenses/mit/)