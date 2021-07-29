#include<iostream>
#include<fstream>
#include<string>
#include"Maze.h"


using namespace std;

int main() {

	string map_name;
	int num;
	cout << "Please input the file number: ";
	cin >> num;

	switch (num)
	{
	case 1:
		map_name = "maze1.txt";
		break;
	case 2:
		map_name = "maze2.txt";
		break;
	case 3:
		map_name = "maze3.txt";
		break;
	case 4:
		map_name = "maze4.txt";
		break;
	default:
		break;
	}

	ifstream inputmap(map_name, ios::in);
	if (!inputmap) {
	
		cerr << "Cannot open the file" << endl;
		exit(1);

	}


	Maze map(inputmap);
	map.printmap();





	system("pause");


	return 0;
}