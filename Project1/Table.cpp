#pragma once

#include "Table.h"
#include"Bazaar.h"
#include<iostream>
#include <string.h>
#include <ctime>
using namespace std;

Table::Table() {
	sizePack = 0;
}

Table::~Table() {
	for (int i = 0; i < sizePack; i++){
		delete[] pack[i];
	}
	delete pack;
}

void Table::setChip(char* str) {
	
		pack[sizePack] = new char[20];
		strcpy_s(pack[sizePack], 6, str);
		sizePack++;
}

void Table::drawChip() {
	for (int i = 0; i < sizePack; i++){
		cout << "_____ ";
	}
	cout << endl;
	for (int i = 0; i < sizePack; i++) {
		cout << '|' << pack[i][0] << '|' <<pack[i][1] << "| ";
	}
}



int Table::getSize() {
	return sizePack;
}

char* Table::getLastChip() {
	return pack[sizePack - 1];
}