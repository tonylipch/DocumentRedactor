#include "Document.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ios>



Document::Document(long size, const char* date, const char* owner, int fontSize, char* fontColor)
	: File(size, date, owner) {
	this->fontColor = fontColor;
	this->fontSize = fontSize;
}


void Document::setColor(char* color) {
	this->fontColor = color;
}

void Document::setSize(int size) {
	this->fontSize = size;
}

// Overrides operatior + 
Document& Document::operator+ (Document& doc) {
	int newSize = this->size + doc.size-1;
	char* newContent = new char[newSize];

	int i = 0;
	for (; i < this->size-1; i++) newContent[i] = this->content[i];
	for (int j=0; j < doc.size; i++, j++) newContent[i] = doc.content[j];



	Document* newDocument = new Document(
		newSize, this->date, this->owner, this->fontSize, this->fontColor
		);
	newDocument->content = newContent;
	return *newDocument;
}

void Document::printStatus(std::ostream& out) {
	File::printStatus(out);
	out << "fontColor=" << this->fontColor<< "\n";
	out << "fontSize=" << this->fontSize << "\n";
}






void Document::saveToStream(ostream& out) {
	out << size << "\n" << owner << "\n" << date << "\n" << content << "\n";

	out << fontColor << "\n" << fontSize << "\n";
	
}

void Document::loadFromStream(istream& in) {
	string line;

	std::getline(in, line);
	size = atoi(line.c_str());

	std::getline(in, line);
	owner = _strdup(line.c_str());// line.c_str() - is reference to character buffer inside the string type

	std::getline(in, line);
	date = _strdup(line.c_str());

	std::getline(in, line);
	content = _strdup(line.c_str());


	std::getline(in, line);
	fontColor = _strdup(line.c_str());
	

	std::getline(in, line);
	fontSize = atoi(line.c_str());

	std::getline(in, line);
	date = _strdup(line.c_str());

	std::getline(in, line);
	content = _strdup(line.c_str());
}


