# Easy-Games
Design and implement several games using C++.

## Gobang
### Usage
* Start the game

```
Now the game start!!!
We got two player!!!

The disc type:
Player1: R
Player2: Y

Enter any button to start the game!!!
```
* Try to get a line(4 disc) to win the game!!!
```
Player2(Y) turn
---------------
This is the board now!!!
      0 1 2 3 4 5 6
     ---------------
  0  ||||||||
  1  ||||||||
  2  ||||||||
  3  ||||||||
  4  |||||R|Y||
  5  |R|Y|||Y|R|R|
     ---------------

Please enter which column you what to put your disc in: 6

---------------
You chose column: 6
Please check the chessboard now.
      0 1 2 3 4 5 6
     ---------------
  0  ||||||||
  1  ||||||||
  2  ||||||||
  3  ||||||||
  4  |||||R|Y|Y|
  5  |R|Y|||Y|R|R|
     ---------------

Enter any button to conti the game!!!
```

## KMines
### Usage
* Choose the width, length, and numbers of boombs.
```
Hellow welcome to the game!!!

Please choose the width:10
Please choose the length:10
Please choose how many boombs:15
```
* Choose the save place until there is no more save place, and you will win the game.
```
Choose a row:4
Choose a column:5
Your choose:(4,5)

There is no boomb nearby!

Please check the map now.
////////////////////////
// ? ? 1空空空空空空空//
// ? ? 1空空空 1 1 1空//
// 1 1 1空空空 1 ? 1空//
//空空空空空 1 2 2 1空//
//空空空空空 1 ? 1空空//
//空空 1 2 2 2 ? 2 1空//
//空空 1 ? ? ? ? ? 1空//
//空空 1 ? ? 1 1 1 1空//
//空 1 1 ? 1 1空空空空//
//空 1 ? ? ? 1空空空空//
////////////////////////

Choose a row:
```

## Maze
Develop a game to escape from the maze based on Breadth-First Search(BFS), using object-oriented programming(OOP).

### Usage
* Input the number between 1 to 4.

```
Please input the file number: 
```

* You will get the shortest path showing by "X". 

```
Please input the file number: 1

// // // // // // // // // // // //
// 起 路 路 路 路 路 路 路 路 路 //
//  X // // // // // // // // 路 //
//  X  X // 路 路 路 路 路 路 路 //
// //  X // // // // 路 // // // //
// 路  X  X  X  X 路 路 路 路 路 //
// 路 // // //  X // // // // 路 //
// 路 // 路 //  X 路 路 路 路 路 //
// 路 路 路 //  X // // // // // //
// 路 // 路 //  X //  X  X  X 路 //
// 路 // 路 //  X  X  X //  X 終 //
// // // // // // // // // // // //
```
