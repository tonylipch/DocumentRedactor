#pragma once
#include "File.h"
#include <iostream>
#include "saveable.h"


using namespace std;


class Document : public File, public Saveable
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

