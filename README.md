# TicTacToe-AI
Goal for this project is to make the pen-and-paper game [Tic-Tac-Toe](https://en.wikipedia.org/wiki/Tic-tac-toe) and a
[rational agent](https://en.wikipedia.org/wiki/Rational_agent), using C. The game window looks like this:

![](https://i.imgur.com/Xdk4HAt.png)

### Install
```
git clone https://github.com/GeorgeSittas/TicTacToe-AI.git
```

### Usage

#### Starting the game
##### 1) Computer plays first
```
cd TicTacToe-AI
make play
```
##### 2) User plays first
```
cd TicTacToe-AI
make play USER=first
```

#### File cleanup
```
cd TicTacToe-AI
make clean
```

### How to play
In each round, a player (either the user or the computer) makes a move, with the first move
being played by the player with the cross symbol (X). Whenever it is the user's turn to make
a move, he can type q or Q to quit the game, or choose a move in the form of \<letter\>\<number\>,
where letter is one of A, B and C, and number is one of 1, 2 and 3 (e.g. A3).

### Notes
In this version of the game, the computer plays the best move in each round (max-depth minimax search)
