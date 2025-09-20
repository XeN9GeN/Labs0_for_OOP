#include "FileWork.h"
#include <fstream>
#include<string>
#include <iostream>


FileWork::FileWork(const std::string& input_name, const std::string& output_name) {
	input.open(input_name);
	if (!input.is_open()) {
		cerr << "Error: cannot open input file " << input_name << endl;
	}
	output.open(output_name);
	if (!output.is_open()) {
		cerr << "Error: cannot open output file " << output_name << endl;
	}
}

string FileWork::read_string() {
	std::string l;
	if (std::getline(input, l)) {
		return l;
	}
	return "";
}

void FileWork::write_string(std::string& str) {
	output << str << "\n";
}

void FileWork::close() {
	if (input.is_open()) 
		input.close();
	if (output.is_open()) 
		output.close();
}
