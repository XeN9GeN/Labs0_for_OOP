#include "FreqPersentage.h"
#include "WordStats.h"
#include <algorithm>
#include<vector>


void FreqPersant::calc_word_freq_pers(vector<WordStats>&stats, int total_words){
	for (auto& i : stats) {
		i.freq_persentage = (static_cast<double>(i.freq) / total_words) * 100;
	}
}

bool FreqPersant::comparesion(const WordStats& a, const WordStats& b) {
	return a.freq > b.freq;
}


void FreqPersant::sort_by_freq_pers(std::vector<WordStats>stats) {
	sort(stats.begin(), stats.end(), FreqPersant::comparesion);
}