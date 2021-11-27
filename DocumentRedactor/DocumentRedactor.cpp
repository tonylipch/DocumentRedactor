

#include <iostream>
#include "File.h"
#include "Document.h"

#include <conio.h>
#include <fstream>

//using namespace std;



int nFiles = 0;
Document ** files = new Document*[10];


void clrscr() {
    system("cls");
}

void anykey() {
    cout << "\n\nPress any key to continue ...";
    _getch();
}

void bad_choice(int c) {
    clrscr();
    cout << "Invalid choice '"<< c<<"'\n";
    anykey();
}

int isNumber(char* c) {
    for (; *c; c++) {
        if (!isdigit(*c)) return 0;
    }
    return 1;
}


void getStr(char* dest, int l) {
    fgets(dest, l, stdin); // Читаем строку с консоли в размере не более L байт
    if (dest[strlen(dest) - 1] == '\n')//Отсекаем завершающий CR
    {
        dest[strlen(dest) - 1] = 0;
    }
}

int getNumber() {
    char* s = new char[256];
    getStr(s, 256);
    int  result = -1;
    if (isNumber(s)) {
        result = atoi(s); //Arr to Int
    }
    delete s;
    return result;

}


void list() {

    clrscr();
    if (nFiles == 0) {
        cout << "No files present\n";
        anykey();
        return;
    }

    for (int i = 0; i < nFiles; i++) {
        cout << i << "\n";
        files[i]->printStatus(cout);
    }
    anykey();

    _getch();
}

void create_file() {
    char* ownerName = new char[256];
    char* date = new char[256];
    char* color = new char[256];
    int fontSize;
    cout << "Enter owner name=";
    getStr(ownerName, 256);
    cout << "Enter date=";
    getStr(date, 10);

    cout << "fontSize=";

    fontSize = getNumber();

    cout << "Color=";
    getStr(color, 256);

    Document* doc = new Document(0l, date, ownerName, fontSize, color);
    files[nFiles++] = doc;
}



void write_to_file() {
    int fileNo;
    cout << "Which file numer to write: ";
    fileNo = getNumber();
    cout << "Type content for writing (up to 256 symbols): ";
    char *content = new char [256];
    getStr(content, 256);
    files[fileNo]->write(content);
    cout << "Content has written to file #" << fileNo;
    anykey();
}

void saveFileToDisk()
{
    int fileNo;
    cout << "Enter id of file to write to disk ";
    fileNo = getNumber();

    string filepath;
    cout << "enter file path";
    cin >> filepath;
    
    files[fileNo]->saveToDisk(filepath);
        
}

void readFileFromDisk()
{
    int fileNo;
    cout << "Enter id of file which you wann to read";
    fileNo = getNumber();

    string filepath;

    cout << "Enter path of file\n";

    cin >> filepath;

    files[fileNo]->readFromDisk(filepath);
    files[fileNo] ->printStatus(cout);

    cin.get();
    cin.get();

}


void merge_files() {

 
    int fileNo1;
    
   cout <<"Chose first file for merge" ;

   fileNo1 = getNumber();
    
    if (fileNo1 < 0 || fileNo1 > nFiles) {
        cout << "Error";
        return;
    }

    int fileNo2;

    cout <<"Chose second file for merge" ;

    fileNo2 = getNumber();

        if (fileNo1 == fileNo2) {
            cout << "Error";

        }
        int fileNo3;
        

        Document& Merge = (Document&)*files[fileNo1]+ (Document&)*files[fileNo2];
        int fileId = nFiles++;

        files[fileId] = &Merge;
        cout << "Result is file #" + fileId;
        Merge.printStatus(cout);




}





void printMenu(const char* filename) {
    char* str = new char[256];
    clrscr();
    ifstream openfile(filename);
    if (openfile.is_open())
    {
        while (openfile.getline(str, 256))
        {
            cout << str << endl;
        }
    }
}

void mainControl() {
    

    int key;
    while (1) {
        printMenu("mainmenueng.txt");
        key = getNumber();
        switch (key) {
        case 1:
            list();
            break;
        case 2:
            create_file();
            break;
        case 3:
            write_to_file();
            break;
        case 4:
            merge_files();
            break;
        case 5:
            saveFileToDisk();
          
            break;
        case 6:
            readFileFromDisk();

            break;

        case 0:
            break;

        default:
            bad_choice(key);

        }

    }

}







int main()
{
    setlocale(LC_ALL, "Russian");
    mainControl();

//    File* f = new File (100l, "2021-09-12", "anton");

    return -1;
}



