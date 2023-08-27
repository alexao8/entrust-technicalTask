// Alexandre Alemany Orfila
// technical task for Entrust application
// C++ file for paging problem

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// sepateLine function adds a new line to the given file, reset the string lines
// and update the number of lines of the current page.
void separateLine(ofstream &file, string &lines, int &numLines) {
    file << (lines += "\n");
    lines = "";
    ++numLines;
}


// sepatePage function adds a line to the given file to differenciate pages.
// It adds a separation line using hastags and indicating the number of pages.
// It also restarts the number of lines and updates the number of pages.
void separatePage(ofstream &file, int &numPages, int &numLines) {
    ++numPages;
    string separation = "#######################################";
    string separationMark = "\n" + separation + " "+ to_string(numPages) + \
        " " + separation + "\n";
    file <<  separationMark + "\n";
    numLines = 0;
}


// reafFile function reads the text file named "name" and stores its content in
// the string line_. If it doesn't exist, the function will output that the
// file cannot be opened.
void readFile(string name, string &line_) {
	ifstream file_(name);
	if(file_.is_open()) {
	    getline(file_,line_);
		file_.close();
	}
	else {
		cout << "file not opened" << endl;
	}
}


// writeFile function creates a file named "name" that will content the string
// line_ divided by diferent lines and pages in the text file.
void writeFile(string name, string &line_) {
    ofstream outputFile_; 
    outputFile_.open("document1.txt");

    string lines = "";      // string that stores a text line
    int numLines = 0;       // number of lines in the current page
    int numPages = 0;       // number of pages
    
    for (char ch : line_) {
        if (lines.length() >= 80 and ch == ' ') {
            separateLine(outputFile_, lines, numLines);

            if (numLines == 25) separatePage(outputFile_, numPages, numLines);
        }
        else lines += ch;
        
    }
    if (lines.length() != 0) separateLine(outputFile_, lines, numLines);
    if (numLines != 0) separatePage(outputFile_, numPages, numLines);
    outputFile_.close();
}


int main() {
	string line_;      // string that will store the content of the text file.
    readFile("document.txt", line_);
    writeFile("documentPaged.txt", line_);
}
