#pragma once
#ifndef Maze_H
#define Maze_H

#include<fstream>
using namespace std;

class Maze {

public:
	Maze(ifstream &);
	~Maze();
	void printmap();
private:
	void setmap(ifstream &);
	void  BFS();

	int hei;
	int wid;
	int **map;
	int **shortmap;
};




#endif 
