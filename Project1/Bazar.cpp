#pragma once

#include"Bazaar.h"
#include<iostream>
#include <string.h>
#include <ctime>
using namespace std;


Bazar::~Bazar() {
	for (int i = 0; i < rowNow; i++) {
		delete[] p[i];
	}
	delete p;
	delete []lastChep;
}

Bazar::Bazar() {
	char item_char[2];
	int order(0), item(0), flag(6);
	
	for (int j = 0; j < rowNow; j++) {
		p[j] = new char[20];
		sprintf_s(item_char, "%d", item);
		strcpy_s(p[j], 5 ,  item_char);
		if (order == flag) {
			flag--;
			item++;
			order = 0;
		}
		else
			order++;
	}


	item = 0;
	flag = 6;
	order = 0;
	
	for (int j = 0; j < rowNow; j++){
		sprintf_s(item_char, "%d", item);
		strcat_s(p[j] , 5 , item_char);
		if (order == flag) {
			flag--;
			item = 6-flag;
			order = 0;
		}
		else {
			item++;
			order++;
		}
	}
}

int Bazar::getSize() {
	return rowNow;
}

void Bazar::showAllDominoChip() {
	for (int i = 0; i < rowNow; i++) {
		cout << p[i];
		cout<< endl;
	}
}

void Bazar::removeDominoChip(int n) {
	char *r = p[rowNow - 1];
	p[rowNow-1] = p[n];
	p[n] = r;

	delete[] p[rowNow-1];
	rowNow--;
}

char* Bazar::getDominoChip() {
	srand(time(0));
	int n = rand() % rowNow;
	strcpy_s(lastChep, 5, p[n]);
	removeDominoChip(n);
	return lastChep;
}


