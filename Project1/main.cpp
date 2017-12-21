#include<iostream>
#include <string.h>
#include "Bazaar.h"
#include "Player.h"
#include "Table.h"
#include <ctime>
#include <windows.h>

void indent(int);
void gameOver(Player&, Player&);
void bot(Player&, Table&, Bazar&);

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);
	Table t;
	Bazar bazar;
	Player I, Bot;

	I.takeStartPack(bazar);
	Bot.takeStartPack(bazar);

	int my_case;
	int num;


	while (true) {
		system("cls");

		if (!bazar.getSize() || !I.getSize() || !Bot.getSize()) {
			system("cls");
			t.drawChip();
			gameOver(I, Bot);

			system("pause");
			return 0;
		}

		cout << "-----1--Set Chip" << endl
			 << "-----2--Take Chip"<< endl
			 << "-----3--Exit";
		
		indent(2);
		cout << "Table" <<endl;
		t.drawChip();

		indent(2);

		cout << endl << "Bazar (" << bazar.getSize() << ')' << endl;
		cout <<  "Bot (" << Bot.getSize() << ')' << endl;

		cout << "My chips : " << endl;
		I.draw();
		cout << endl << endl << "Case: " << endl;
		cin >> my_case;

	

		switch (my_case)
		{
		case 1:
			cout << "_";
			cin >> num;
			if (!I.pushDominoChip(t, num - 1)) {
				I.takeDomainChip(bazar);
			}
				
			break;
		case 2:
			I.takeDomainChip(bazar);
			break;
		case 3:
			exit(1);
			break;
		default:
			exit(1);
			break;
		}
		// ход бота
		bot(Bot, t, bazar);
	}

	
	system("pause");
}


void indent(int n) {
	for (int i = 0; i < n; i++){
		cout << endl;
	}
}

void bot(Player& player, Table& t, Bazar& b) {
	//int* last = new int[20];
	for (size_t i = 0; i < player.getSize() ; i++){
		if (player.pushDominoChip(t, i)) {
			return;
		}
	}
	player.takeDomainChip(b);
}

void gameOver(Player& I, Player& Bot) {

	
	int I_score(0), Bot_score(0);

	for (int i = 0; i < I.getSize(); i++){
		I_score += I.getCountScore(i);
	}

	for (int i = 0; i < Bot.getSize(); i++) {
		Bot_score += Bot.getCountScore(i);
	}

	if (Bot_score < I_score) {
		cout << endl
			<< "//////////////////////"<<endl
			<<"You are lost" <<endl 
			<< "//////////////////////";
	}
	else if (Bot_score >
		I_score) {
		cout << endl
			<< "//////////////////////" << endl
			<< "You are won" << endl
			<< "//////////////////////";
	}
	else 
		cout << endl
		<< "//////////////////////" << endl
		<< "NICHA" << endl
		<< "//////////////////////";

	cout << endl <<
		"My score: " << I_score<< endl<<
		"Bot's score: " << Bot_score<<endl ;


	
}