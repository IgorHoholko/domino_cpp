#pragma once

class Table {
	char** pack = new char*[28];
	int sizePack;
public:
	Table();
	~Table();


	void setChip(char*);
	void drawChip();
	char* getLastChip();
	int getSize();

};