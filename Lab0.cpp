#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Word_Struct {
	string word;
	int freq;
	double freq_persent;
};

bool word_compare(Word_Struct& a, Word_Struct& b) {
	return a.freq > b.freq;
}

bool checking(char c) {
	return isalnum(char(c));
}

int main(int argc, char* argv[]) {
	ifstream inputf(argv[1]);
	ofstream outputf("output.csv");

	vector<Word_Struct>massiv_of_words;
	string cur_line;
	char c;
	int total_words = 0;

	while (getline(inputf, cur_line)) {
		string cur_word;
		for (char c : cur_line) {

			if (checking(c))
				cur_word += tolower(c);

			else if (!cur_word.empty()) {
				total_words++;

				bool word_was_found = false;

				for (Word_Struct& i : massiv_of_words) {

					if (i.word == cur_word) {
						i.freq++;
						word_was_found = true;
						break;
					}
				}

				if (!word_was_found) {
					Word_Struct new_wd;
					new_wd.word = cur_word;
					new_wd.freq = 1;
					new_wd.freq_persent = 0.0;
					massiv_of_words.push_back(new_wd);
				}
				cur_word.clear();
			}
		}
		if (!cur_word.empty()) {
			total_words++;
			bool word_was_found = false;

			for (Word_Struct& i : massiv_of_words) {
				if (i.word == cur_word) {
					i.freq++;
					word_was_found = true;
					break;
				}
			}

			if (!word_was_found) {
				Word_Struct new_wd;
				new_wd.word = cur_word;
				new_wd.freq = 1;
				new_wd.freq_persent = 0.0;
				massiv_of_words.push_back(new_wd);
			}
		}
	}


	for (Word_Struct& i : massiv_of_words) {
		i.freq_persent = (static_cast<double>(i.freq) / total_words) * 100;
	}

	sort(massiv_of_words.begin(), massiv_of_words.end(), word_compare);
	
	outputf << "Word  Frequency  Percentage\n";
	for (Word_Struct& i : massiv_of_words) {
		outputf << i.word << "  |  " << i.freq << "  |  " << i.freq_persent << "%" << "\n";
	}

	return 0;


}
