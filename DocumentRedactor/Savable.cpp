#include "saveable.h"
#include <fstream>





	void Saveable::saveToDisk(string fileName) {
		ofstream out;
		out.open(fileName);
		saveToStream(out);
		out.flush();
		out.close();

	}

	void Saveable::readFromDisk(string fileName) {
		ifstream in;
		in.open(fileName);
		loadFromStream(in);
		in.close();
	}


