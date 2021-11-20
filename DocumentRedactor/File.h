#include <iostream>


using namespace std;


#pragma once
class File
{
protected:
	long size;
	const char* date;
	const char* owner;
	char* content;

public:
	File(long size, const char* date, const char* owner);
	~File();
	char* read();
	void write(char* content);
	void printStatus(std::ostream& out);

	void saveToDisk(string fileName);
	void readFromDisk(string fileName);


protected:
	virtual void saveToStream(ostream& out);
	virtual void loadFromStream(istream& in);


};

#define _CRT_SECURE_NO_WARNINGS


