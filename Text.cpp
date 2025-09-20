#include "Text.h"
#include <cctype>
#include <ctype.h>


vector <string> TextReading::reader(std::string& text) {
	std::vector <std::string> mass_of_words;
	std::string cur_word;

	for (char c : text) {
		if (isalnum(c)) {
			cur_word += tolower(c);
		}
		else if (!cur_word.empty()) {
			mass_of_words.push_back(cur_word);
			cur_word.clear();
		}
	}

	if (!cur_word.empty()) {
		mass_of_words.push_back(cur_word);
	}

	return mass_of_words;
}

