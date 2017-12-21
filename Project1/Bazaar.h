#pragma once

class Bazar {
	int rowNow = 28;
	char * lastChep = new char[5];
	char ** p = new char*[28];
public:

	Bazar();
	~Bazar();
	int getSize();
	void removeDominoChip(int);
	void showAllDominoChip();
	char* getDominoChip();
};