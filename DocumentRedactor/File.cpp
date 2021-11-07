#include "File.h"
#include <string.h>
#include <iostream>


using namespace std;


File::File(long size, const char* date, const char* owner) {
	this->size = size;
	this->date = date;
	this->owner = owner;
	this->content = NULL;
}

File::~File() {
	if (this->content != NULL) delete this->content;
}

char* File::read() {
	return content;
}

void File::write(char* content) {
	if (this->content != NULL) delete this->content;
	this->size = strlen(content) + 1;
	this->content = new char[this->size];
	for (int i = 0; i < this->size; i++) // copy 
		this->content[i] = content[i];
}


void File::printStatus(std::ostream &out) {
	out << "size=" << this->size << "\n";
	out << "date=" << this->date << "\n";
	out << "owner=" << this->owner << "\n";

	if (content == NULL) out << "No content";

	else out << "content='" << this->content << "'\n";
}

