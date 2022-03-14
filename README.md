# uno
An abstract game of uno

### How it works:
The game starts by initializing two card hands with 7 randomly generated cards. These are assigned to the two players in the game. The same rule as uno applies. Player one starts first and places a card on top of a deck. Player two follows by inserting a corresponding card. This process repeats on until one player has run out of cards in their hands.

Both players may input cards in the format 'Number/Cards'. For example, A blue number 2 card will be 2B. A red +2 card will be +2R. A color change card may be inputted as 'CC' The player is then prompted to select the next color. After a draw +2 or +4 card, the next player will receive a notification alongside the appropriate penalty in their card hand. If the player does not have a matching card on the deck, they may request a new randomly generated card by inputting 'new'.

Both players are unable to see the other player's hand. This is done by clearing the screen after every turn and asking the player to press a button before displaying their hand. This allows a layer of anonymity to prevent cheating.

### Class functionality
This project was designed with OOP in mind. 

The three classes used are:
<ul>
    <li>Card class</li>
    <li>Hand class</li>
    <li>Player class</li>
</ul>

#### Card class
The card object simply describes the attribute of a single card. It is the deepest level from all classes above. The card class may create a new and randomized card upon request from the hand class.

#### Hand class
This class represents the card hand that a player may have. It consists of an array with card objects. It acts as a mediator between the player and the card class. All member accesses are done with this class.

#### Player class
The top most level of all classes. This class only triggers whole instructions by calling the hand class. It is only permitted to find, remove and display cards in the player hand. It also contains statistics about the player.