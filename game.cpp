#include<iostream>
#include<vector>
using namespace std;

void output(vector < vector<char> >);
void cincanput(vector < vector<char> >, int &);
void putin(vector < vector<char> > &,const int, const int);
bool winornot(vector < vector<char> >, int);
bool Draw(vector < vector<char> >);


int main() {
	int enter = 1;
	int contigame = 0;
	bool endagame = 1;
	int col = 0;
	int who = 0;

	while (contigame == 0) {
		endagame = 1;
		vector < vector<char> > chessboard(6, vector<char>(7, 0));
		system("cls");
		cout << "Now the game start!!!" << endl;
		cout << "We got two player!!!" << endl << endl;
		cout << "The disc type: " << endl << "Player1: R" << endl << "Player2: Y" << endl << endl;
		cout << "Enter any button to start the game!!!" << endl;
		system("pause");
		do {
			//Player1 turn
			system("cls");
			who = 1;
			cout << "Player1(R) turn" << endl;
			cout << "---------------" << endl;
			cout << "This is the board now!!!" << endl;
			output(chessboard);
			cincanput(chessboard, col);
			cout << endl << "---------------" << endl;
			cout << "You chose column: " << col << endl;
			putin(chessboard, col, who);
			cout << "Please check the chessboard now." << endl;
			output(chessboard);
			cout << endl << "Enter any button to conti the game!!!" << endl;
			system("pause");
			if (winornot(chessboard, who)) {
				system("cls");
				cout << "---------------" << endl;
				cout << "Player1(R) win the game!!!" << endl;
				cout << "Please check the final chessboard" << endl;
				output(chessboard);
				endagame = 0;
			}
			else if (Draw(chessboard)) {
				system("cls");
				cout << "---------------" << endl;
				cout << "DRAW!!!" << endl;
				cout << "Please check the final chessboard" << endl;
				output(chessboard);
				endagame = 0;
			}
			else {//Player2 turn
				system("cls");
				who = 2;
				cout << "Player2(Y) turn" << endl;
				cout << "---------------" << endl;
				cout << "This is the board now!!!" << endl;
				output(chessboard);
				cincanput(chessboard, col);
				cout << endl << "---------------" << endl;
				cout << "You chose column: " << col << endl;
				putin(chessboard, col, who);
				cout << "Please check the chessboard now." << endl;
				output(chessboard);
				cout << endl << "Enter any button to conti the game!!!" << endl;
				system("pause");
				if (winornot(chessboard, who)) {
					system("cls");
					cout << "---------------" << endl;
					cout << "Player2(Y) win the game!!!" << endl;
					cout << "Please check the final chessboard" << endl;
					output(chessboard);
					endagame = 1;
				}
				else if (Draw(chessboard)) {
					system("cls");
					cout << "---------------" << endl;
					cout << "DRAW!!!" << endl;
					cout << "Please check the final chessboard" << endl;
					output(chessboard);
					endagame = 1;
				}
			}
		} while (endagame);




		cout << "---------------" << endl;
		cout << "Play again(enter 0) or not(enter 1)?" << endl;
		do {
			cout << "Your choose: ";
			cin >> contigame;
			if (contigame == 0 || contigame == 1) {
				if (contigame == 0) {
					cout << "Let's go";
					enter = 0;
				}
				else {
					cout << "Have a nice day hope you love the game!!!";
					enter = 0;
				}
			}
			else { enter = 1; cout << "Please enter the number between 0~6" << endl;}
		} while (enter == 1);
	}
	system("pause");
	return 0;
}

void cincanput( vector < vector<char> > n1, int &c1){
	bool ok = 1;
	while (ok) {
		cout << endl << "Please enter which column you what to put your disc in: ";
		cin >> c1;
		if ( -1<c1 && c1<7 ) {
			if (n1[0][c1] == '\0') {
				ok = 0;
			}
			else {
				cout << "You can't put the disc in that colunm!!!"<<endl;
			}
		}
		else {
			cout << "Please enter the number between 0~6"<<endl;
		}
	}
}

void putin(vector < vector<char> > &n2, const int c2, const int w1) {

	int in=0;

	for (int i = 0; i <= 5; i++) {
		if (n2[i][c2] == '\0') {
			in = i;
		}
	}

	if (w1 == 1) {
		n2[in][c2] = 'R';
	}

	else if (w1 == 2) {
		n2[in][c2] = 'Y';
	}

}

bool winornot(vector < vector<char> > n3,int w2) {

	char disc='\0';

	if (w2 == 1) {
		disc = 'R';
	}

	else if (w2 == 2) {
		disc = 'Y';
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (j + 3 < 7) {
				if (n3[i][j] == disc && n3[i][j + 1] == disc && n3[i][j + 2] == disc && n3[i][j + 3] == disc) {
					return 1;
				}
			}
			if (i + 3 < 6) {
				if (n3[i][j] == disc && n3[i + 1][j] == disc && n3[i + 2][j] == disc && n3[i + 3][j] == disc) {
					return 1;
				}
			}
			if ((j + 3 < 7) && (i + 3 < 6)) {
				if (n3[i][j] == disc && n3[i + 1][j + 1] == disc && n3[i + 2][j + 2] == disc && n3[i + 3][j + 3] == disc) {
					return 1;
				}
			}
			if ((j - 3 >= 0) && (i + 3 < 6)) {
				if (n3[i][j] == disc && n3[i + 1][j - 1] == disc && n3[i + 2][j - 2] == disc && n3[i + 3][j - 3] == disc) {
					return 1;
				}
			}
		}
	}
	return 0;
}

bool Draw(vector < vector<char> > n4){

	int check = 0;

		for (int j = 0; j < 7; j++) {
			if (n4[0][j] != '\0') {
				check++;
		}
		}

		if (check == 7) {
			return 1;
		}
		else {
			return 0;
		}
}

void output(vector < vector<char> > n4) {
	cout << "      0 1 2 3 4 5 6" << endl;
	cout << "     ---------------" << endl;
	for (int i = 0; i < 6; i++) {
		cout << "  " << i << "  |";
		for (int j = 0; j < 7; j++) {
			cout << n4[i][j] << "|";
		}
		cout << endl;
	}
	cout << "     ---------------" << endl;
}