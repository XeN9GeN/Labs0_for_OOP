#include <iostream>
#include <vector>
#include"WordStats.h"
#include"Text.h"
#include"FreqPersentage.h"
#include"FreqCounter.h"
#include"FileWork.h"
using namespace std;

int main(int argc, char* argv[]) {
	FileWork FW(argv[1], "output.csv");

	WordFreqCount WFC;
	FreqPersant FP;
	string str;
	while (!(str = FW.read_string()).empty()) {
		vector<string> massive_of_words = TextReading::reader(str);
		WFC.scan_mass_of_words(massive_of_words);
	}

	int total_w = WFC.get_total_words();
	if (total_w == 0) {
		cerr << "0 words in your text" << "\n";
	}

	vector<WordStats>stats = WFC.get_stats_of_word();
	FP.calc_word_freq_pers(stats, total_w);
	FP.sort_by_freq_pers(stats);

	string s = "WORD | FREQ | PER%";

	FW.write_string(s);
	for (WordStats& i : stats) {
		string l = i.word + "  |  " + to_string(i.freq) + "  |  " + to_string(i.freq_persentage) + "%";
		FW.write_string(l);
	}
	
	cerr << "Completed" << "\n";
	FW.close();
	return 0;
}

