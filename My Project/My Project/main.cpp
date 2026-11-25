#include <iostream>
using namespace std;

struct Tile { char tileLetter; bool filled; }

struct Clue { char clueLetter; int cluePosition; WordRow clueRow; }

struct Location { string locName; char letterClueLoc; int boardPosLoc; WordRow locRow; bool locSearchFlag; }

enum GameState { Menu, Playing, Won, Lost, Exit }

enum MenuChoice { New Game, Leader/Score Board, About, Rules, Exit }

enum WordRow { Word 1, Word 2 }


int main() {
	cout << "Hello World!" << endl;
	system("pause");
	return 0;
}
