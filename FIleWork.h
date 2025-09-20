#ifndef FILEWORK_H
#define FILEWORK_H

#include<string>
#include<fstream>
using namespace std;

class FileWork {
private:
	fstream input;
	ofstream output;

public:
	FileWork(const string& input_name, const string& output_name);
	string read_string();
	void write_string(string& str);
	void close();
};

#endif