#include "Document.h"


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
