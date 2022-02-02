#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int **map;
int **show;

void setmap(const int &,const int &,const int &,const int *);
void printanswer(const int &, const int &);
void setshow(const int &, const int &);
void printmap(const int &, const int &);
int whichcase(const int &, const int &);
int* boombplace(const int &, const int &, const int &);

void onboomb(const int &, const int &);
void nearboomb(const int &, const int &);
void noboomb(const int &, const int &);

bool winorlose(const int &, const int &, const int &);

int main(){

	int wid, len,boo;
	cout << "Hellow welcome to the game!!!" << endl;
	cout << endl << "Please choose the width:";
	cin >> wid;
	cout  << "Please choose the length:";
	cin >> len;
	cout  << "Please choose how many boombs:";
	cin >> boo;


	setmap(len, wid, boo, boombplace(wid, len, boo));
	setshow(len, wid);

	cout << endl << "Game start" << endl << "---------------------------------------------" << endl;
	cout << "Please check the map now." << endl;
	printmap(len, wid);
	int row,col;
	bool check;

	do
	{

		cout << endl << "Choose a row:";
		cin >> row;
		cout << "Choose a column:";
		cin >> col;
		cout << "Your choose:(" << row << "," << col << ")" << endl << endl;
		
		int cas = whichcase(row, col);

		switch (cas)
		{
		case 1:
			cout << "You choose on boomb!";
			onboomb(len, wid);
			break;
		case 2:
			cout << "There is boomb nearby!";
			nearboomb(row, col);
			break;
		case 3:
			cout << "There is no boomb nearby!";
			noboomb(row, col);
			break;
		}


		cout << endl << endl << "Please check the map now." << endl;
		printmap(len, wid);
		check = winorlose(len, wid, cas);

 	} while (check);

	cout << endl << "ANOSWER" << endl << "---------------------------------------------" << endl;
	printanswer(len, wid);
	system("pause");
	return 0;
}




void setmap(const int &l,const int &w,const int & b,const int *place) {
//call map
	map = new int *[l+1];
	for (int i = 0; i <= (l+1)  ; i++) {
		map[i] = new int[w+1];
	}
//put element
	for (int i = 0; i <= (l+1); i++) {
		for (int j = 0; j <= (w + 1); j++) {
			if (i == 0 || j == 0 || i == (l + 1) || j == (w + 1)) {
				map[i][j] = -2;
			}
			else { map[i][j] = 0; }
		}
	}
//add boomb place
	for (int i = 0; i < (l*w); i++) {

		if (place[i] == 1) {
			int a = (i / w) + 1;
			int b = (i % w) + 1;
			map[a][b] = -1;
//add number
			for (int j = (a - 1); j <= (a + 1); j++) {
				for (int u = (b - 1); u <= (b + 1); u++) {
					if (map[j][u] != -1 && map[j][u] != -2) {
						map[j][u]++;
					}
				}
			}
		}
	}

}


void printmap(const int &l, const int &w) {

	for (int i = 0; i <= (l + 1); i++) {
		for (int j = 0; j <= (w + 1); j++) {

			if (show[i][j] == 1) {

				switch (map[i][j])
				{
				case -2:
					cout << "//";
					break;
				case -1:
					cout << "¹p";
					break;
				case 0:
					cout << "ªÅ";
					break;
				default:
					cout << " " << map[i][j];
					break;
				}
			}
			else { cout << " ?"; }
		}
		cout << endl;
	}
}

int* boombplace(const int &l, const int &w, const int &b) {

	int *place = new int[l*w];
	
	for (int i = 0; i < (l*w); i++) {
		place[i] = 0;
	}

	srand(time(NULL));
	for (int i = 0; i < b; i++) {
		int pick = rand() % (l*w) ;
		if (place[pick] == 0) {
			place[pick] = 1;
		}
		else { i--; }
	}

	return place;
}

void setshow(const int &l, const int &w) {
	//call map
	show = new int *[l + 1];
	for (int i = 0; i <= (l + 1); i++) {
		show[i] = new int[w + 1];
	}
	//put element
	for (int i = 0; i <= (l + 1); i++) {
		for (int j = 0; j <= (w + 1); j++) {
			if (i == 0 || j == 0 || i == (l + 1) || j == (w + 1)) {
				show[i][j] = 1;
			}
			else { show[i][j] = 0; }
		}
	}

}

int whichcase(const int &r, const int &c) {

	switch (map[r][c])
	{
	case -1:
		return 1;
	case 0:
		return 3;
	default:
		return 2;
	}

}

//case 1
void onboomb(const int &l ,const int &w) {

	for (int i = 0; i <= (l + 1); i++) {
		for (int j = 0; j <= (w + 1); j++) {
		
			show[i][j] = 1;
	
		}
	}

}

//case 2
void nearboomb(const int &r, const int &c) {

	show[r][c] = 1;

}
 
//case 3
void noboomb(const int &r, const int &c) {

	for (int i = (r - 1); i <= (r + 1); i++) {
		for (int j = (c - 1); j <= (c + 1); j++) {
		
			if (show[i][j] == 0) {
				if (map[i][j] > 0 || (r == i && c == j)) {
					show[i][j] = 1;
				}

				else if (map[i][j] == 0) { noboomb(i, j); }
			}

		}
	}

}

bool winorlose(const int &l, const int &w, const int &c) {

	if (c == 1) {
		cout << endl << "GAME OVER" << endl;
		return 0;
	}

	else {
		for (int i = 0; i <= (l + 1); i++) {
			for (int j = 0; j <= (w + 1); j++) {

				if (map[i][j] > 0) {
				
					if (show[i][j] == 1) {}
					else { return 1; }
				
				}

			}
		}
	}

	cout << endl << "YOU WIN" << endl;
	return 0;
}

void printanswer(const int &l, const int &w) {

	for (int i = 0; i <= (l + 1); i++) {
		for (int j = 0; j <= (w + 1); j++) {
			switch (map[i][j])
			{
			case -2:
				cout << "//";
				break;
			case -1:
				cout << "¹p";
				break;
			case 0:
				cout << "ªÅ";
				break;
			default:
				cout << " " << map[i][j];
				break;
			}
		}
		cout << endl;
	}
}