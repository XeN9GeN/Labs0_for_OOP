#ifndef FREQPERSANT_H
#define FREQPERSANT_H
#include "WordStats.h"
#include "FreqCounter.h"
#include<vector>

class FreqPersant {
public:
	static void calc_word_freq_pers(std::vector<WordStats>&stats, int total_words);
	void sort_by_freq_pers(std::vector<WordStats>stats);
	static bool comparesion(const WordStats& a, const WordStats& b);
};

#endif // !FREQPERSANT_H
