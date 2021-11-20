#include "File.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ios>




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


void File::saveToStream(ostream& out) {
	out << size << "\n" << owner << "\n" << date << "\n" << content << "\n";
}

void File::loadFromStream(istream& in) {
	string line;

	std::getline(in, line);
	size = atoi(line.c_str());

	std::getline(in, line);
	owner = _strdup(line.c_str());// line.c_str() - is reference to character buffer inside the string type

	std::getline(in, line);
	date = _strdup(line.c_str());

	std::getline(in, line);
	content = _strdup(line.c_str());

}



void File::saveToDisk(string fileName) {
	ofstream out;
	out.open(fileName);
	saveToStream(out);
	out.flush();
	out.close();

}

void File::readFromDisk(string fileName) {
	ifstream in;
	in.open(fileName);
	loadFromStream(in);
	in.close();

}


