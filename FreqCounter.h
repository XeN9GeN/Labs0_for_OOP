#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string>
#include <vector>
#include <map>
#include "WordStats.h"

class WordFreqCount {
private:
    std::map<std::string, int> mass_of_words;
    int total_words;

public:
    WordFreqCount();
    int get_total_words();
    void scan_mass_of_words(std::vector<std::string>& mass_of_words);
    std::vector<WordStats> get_stats_of_word();
};

#endif