#include<iostream>
#include<fstream>
#include<queue>
#include"Maze.h"

using namespace std;

Maze::Maze(ifstream &inf) {
	
	setmap(inf);//包含建立hei wid 
	BFS();//包含建立pie

}
void Maze::BFS() {
	
	//建立adj
	int ***adj;
	adj = new int**[hei];
	for (int i = 0; i < hei; i++) {
		adj[i] = new int*[wid];
		for (int j = 0; j < wid; j++) {
			adj[i][j] = new int[4];
		}
	}
	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			for (int a = 0; a < 4; a++) {
				adj[i][j][a] = 0;
			}
			if (map[i][j] != 1) {
				if (map[i - 1][j] != 1)
				{
					adj[i][j][0] = 1;
				}
				if (map[i + 1][j] != 1)
				{
					adj[i][j][1] = 1;
				}
				if (map[i][j - 1] != 1)
				{
					adj[i][j][2] = 1;
				}
				if (map[i][j + 1] != 1)
				{
					adj[i][j][3] = 1;
				}
			}
		}
	}
	
	//建立color
	char **color;
	color = new char*[hei];
	for (int i = 0; i < hei; i++) {
		color[i] = new char[wid];
	}
	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			color[i][j] = 'W';
		}
	}

	//建立pie
	int ***pie;
	pie = new int**[hei];
	for (int i = 0; i < hei; i++) {
		pie[i] = new int*[wid];
		for (int j = 0; j < wid; j++) {
			pie[i][j] = new int[2];
		}
	}

	//找s
	int s[2] = {-1};
	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			if (map[i][j] == 200) { s[0] = i; s[1] = j; break; }
		}
		if (s[0] != -1) { break; }
	}
	
	//初始s.color
	color[s[0]][s[1]] = 'G';

	//BFS
	queue<int> h;
	queue<int> w;
	h.push(s[0]);
	w.push(s[1]);
	
	int u[2];
	int v[2];
	while (!h.empty()) {

		u[0] = h.front();
		h.pop();
		u[1] = w.front();
		w.pop();

		for (int i = 0; i < 4; i++) {
			if (adj[u[0]][u[1]][i] == 1) {
				switch (i) {
				case 0:
					v[0] = u[0] - 1;
					v[1] = u[1];
					break;
				case 1:
					v[0] = u[0] + 1;
					v[1] = u[1];
					break;
				case 2:
					v[0] = u[0];
					v[1] = u[1] - 1;
					break;
				case 3:
					v[0] = u[0];
					v[1] = u[1] + 1;
					break;
				}
				if (color[v[0]][v[1]] == 'W') {
					color[v[0]][v[1]] = 'G';
					for (int i = 0; i < 2; i++) {
						pie[v[0]][v[1]][i] = u[i];
					}
					h.push(v[0]);
					w.push(v[1]);
				}
			}
		}
		color[u[0]][u[1]] = 'B';
	}
	
	//set shortmap
	shortmap = new int*[hei];
	for (int i = 0; i < hei; i++) {
		shortmap[i] = new int[wid];
	}

	//找f
	int f[2] = { -1 };
	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			if (map[i][j] == 201) { f[0] = i; f[1] = j; break; }
		}
		if (f[0] != -1) { break; }
	}

	while (map[f[0]][f[1]] != 200) {
		int a = pie[f[0]][f[1]][0];
		int b = pie[f[0]][f[1]][1];
		if (map[a][b] != 200) {
			shortmap[a][b] = 1;
		}
		f[0] = a;
		f[1] = b;
	}

	//delete
	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			delete[] adj[i][j];
		}
		delete[] adj[i];
	}
	delete[] adj;

	for (int i = 0; i < hei; i++) {
		delete[] color[i];
	}
	delete[] color;

	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			delete[] pie[i][j];
		}
		delete[] pie[i];
	}
	delete[] pie;

}
void Maze::printmap() {

	cout << endl;
	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			if (shortmap[i][j] != 1) {
				switch (map[i][j])
				{
				case 0:
					cout << "路";
					break;
				case 1:
					cout << "//";
					break;
				case 200:
					cout << "起";
					break;
				case 201:
					cout << "終";
					break;
				default:
					cout << " ?";
					break;
				}
			}
			else { cout << " X"; }
			cout << " ";
		}
		cout << endl;
	}

	cout << endl;
}
void Maze::setmap(ifstream &inf) {
	int maze;
	char com;

	inf >> wid >> com >> hei;

	map = new int*[hei];
	for (int i = 0; i < hei; i++) {
		map[i] = new int[wid];
	}

	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			inf >> maze;
			if (j < (wid - 1)) { inf.seekg(1, ios::cur); }
			map[i][j] = maze;
		}
	}
}
Maze::~Maze() {

	for (int i = 0; i < hei; i++) {
		delete[] map[i];
	}
	delete[] map;

	for (int i = 0; i < hei; i++) {
		delete[] shortmap[i];
	}
	delete[] shortmap;

}