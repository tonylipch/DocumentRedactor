#pragma once
#include "File.h"
#include <iostream>


using namespace std;


class Document : public File
{
private:
	int fontSize;
	char* fontColor;

public:
	Document(long size, const char* date, const char* owner, int fontSize, char* fontColor);

	void setColor(char* color);
	void setSize(int size);
	Document& operator+ (Document& doc); 
	void printStatus(std::ostream& out);

protected:
	virtual void saveToStream(ostream& out);
	virtual void loadFromStream(istream& in);

};

