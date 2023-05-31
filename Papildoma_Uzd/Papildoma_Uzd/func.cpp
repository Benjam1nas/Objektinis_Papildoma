#include "MyLib.h"

void simboliuPasalinimas(string& zodis) {
	string galutinis;
	for (char c : zodis) {
		if (std::isalnum(c)) {
			galutinis += std::tolower(c);
		}
	}

	zodis = galutinis;
}

void count(string eil, unordered_map<string, int>& zodziai, unordered_map<string, vector<int>>& eilutes, int eil_sk) {
	stringstream ss(eil);
	string zodis;
	while (ss >> zodis) {
		simboliuPasalinimas(zodis);
		zodziai[zodis]++;
		eilutes[zodis].push_back(eil_sk);
	}
}

void ieskotiURL(string failo_pav) {
	fstream data_file(failo_pav, ios_base::in);
	regex urlRegex(R"((https?:\/\/[^\s]+)|(www\.[^\s]+)|(?:[^\.\/]+\.[^\.\/]+))");
	smatch matches;
	string eilutes;
	while (getline(data_file, eilutes)) {
		for (auto it = sregex_iterator(eilutes.begin(), eilutes.end(), urlRegex); it != sregex_iterator(); ++it) {
			string url = it->str();
			if (regex_match(url, regex(R"(https?:\/\/[^\s]+)")) || regex_match(url, regex(R"(www\.[^\s]+)")) ||
				regex_match(url, regex(R"(^[^\s]+\.(?:com|lt)$)"))) {
				cout << url << endl;
			}
		}
	}

	data_file.close();
}

void WordCount() {
	unordered_map<string, int> zodziai;
	unordered_map<string, vector<int>> eilutes;
	string eil, failo_pav;
	int eil_sk = 0;
	cout << "Iveskite failo pavadinima: "; cin >> failo_pav;
	fstream data_file(failo_pav, ios_base::in);
	while (!data_file.is_open()) {
		cout << "Programa neranda tokio duomenu failo!" << endl << "Iveskite failo pavadinima: ";
		cin >> failo_pav;
		cout << endl;
		fstream data_file(failo_pav, ios_base::in);
	}
	while (getline(data_file, eil)) {
		eil_sk++;
		count(eil, zodziai, eilutes, eil_sk);
	}
	data_file.close();
	cout << "Rasti URL: " << endl;
	ieskotiURL(failo_pav);
	fstream result_file("zodziu_pasikartojimas.txt", ios_base::out);
	for (const auto& pair : zodziai) {
		if (pair.second > 1) {
			result_file << pair.first << ": " << pair.second << endl << "Eilutes, kuriose buvo rastas zodis " << pair.first << ": ";
			for (int i = 0; i < pair.second; i++) {
				result_file << eilutes[pair.first][i] << " ";
			}
			result_file << endl;
		}
	}
	result_file.close();
}

