#pragma once
#include "Table.h"

class Player {
	char** pack = new char *[22];
	int sizePack;
	char * lastChep = new char[5];
public:
	Player();
	~Player();

	int getSize();
	void removeDominoChip(int);
	void takeStartPack(Bazar&);
	bool pushDominoChip(Table&, int);
	void takeDomainChip(Bazar&);
	int getCountScore(int);
	void draw();
};