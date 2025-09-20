#include <iostream>
#include "FreqCounter.h"
#include "WordStats.h"

WordFreqCount::WordFreqCount() {
	total_words = 0;
}

void WordFreqCount::scan_mass_of_words(std::vector<std::string>&words) {
	for (auto& i : words) {
		mass_of_words[i]++;
		total_words++;
	}
}

std::vector<WordStats> WordFreqCount::get_stats_of_word() {
	std::vector<WordStats> stats;
	
	for (auto&i :mass_of_words) {
		WordStats stat_of_word;
		stat_of_word.word = i.first;
		stat_of_word.freq = i.second;
		stats.push_back(stat_of_word);
	}
	return stats;
}

int WordFreqCount::get_total_words() {
	return total_words;
}