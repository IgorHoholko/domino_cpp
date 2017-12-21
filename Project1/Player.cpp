#include "Bazaar.h"
#include "Player.h"
#include "Table.h"
#include<iostream>
#include <string.h>
#include <ctime>
using namespace std;

Player::~Player() {
	for (int i = 0; i < sizePack; i++){
		delete[] pack[i];
	}
	delete pack;
	delete[] lastChep;
}

Player::Player() {
	sizePack = 6;

	for (int i = 0; i < sizePack; i++){
		pack[i] = new char[5];
	}
}

void Player::removeDominoChip(int n) {
	strcpy_s(pack[n], 5, pack[sizePack - 1]);	
	delete[] pack[sizePack-1];
	sizePack--;
}

bool Player::pushDominoChip(Table& ob, int n) {
	
	if (!ob.getSize()) {
		ob.setChip(pack[n]);
		removeDominoChip(n);
		return true;
	}

	char* str = new char[10];
	strcpy_s(str, 5, ob.getLastChip());

	if (str[1] == pack[n][0]) {
		ob.setChip(pack[n]);
		removeDominoChip(n);
		return true;
	}
	else if (str[1] == pack[n][1]) {
		str[0] = pack[n][1];
		str[1] = pack[n][0];
		ob.setChip(str);
		removeDominoChip(n);
		return true;
	}


	return false;

}

int Player::getCountScore(int n) {
	int answer(0);
	answer = (int)pack[n][0] + (int)pack[n][1] -96;
	return answer;
}

int Player::getSize() {
	return sizePack;
}

void Player::takeStartPack(Bazar &ob) {
	for (int i = 0; i < sizePack; i++){
		strcpy_s(pack[i], 5, ob.getDominoChip());
	}
}

void Player::takeDomainChip(Bazar &ob) {
	pack[sizePack] = new char[20];
	strcpy_s(pack[sizePack], 5, ob.getDominoChip());
	sizePack++;
}

void Player::draw() {

	for (int i = 0; i < sizePack; i++) {
		cout << "_____ ";
	}
	cout << endl;
	for (int i = 0; i < sizePack; i++) {
		cout << '|' << pack[i][0] << '|' << pack[i][1] << "| ";
	}
	cout << endl;
	for (int i = 0; i < sizePack; i++) {
		cout << "  " << i+1 << "   ";
	}
	
}