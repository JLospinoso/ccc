#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

enum class CharCategory { Ascender, Normal, Descender };

CharCategory categorize(char x) {
  switch(x) {
  case 'g':
  case 'j':
  case 'p':
  case 'q':
  case 'y':
    return CharCategory::Descender;
  case 'b':
  case 'd':
  case 'f':
  case 'h':
  case 'k':
  case 'l':
  case 't':
    return CharCategory::Ascender;
  }
  return CharCategory::Normal;
}

bool ascension_compare(char x, char y) {
  return categorize(x) < categorize(y);
}

bool interesting(const string& x) {
  const auto grade = count_if(x.begin(), x.end(), [](char x) { return categorize(x) != CharCategory::Normal; });
  return grade > 4;
}

int main() {
  try {
    unordered_set<string> words;
    ifstream words_file("G:\\words\\words.txt");
    copy(istream_iterator<string>(words_file), istream_iterator<string>(), inserter(words, words.begin()));

    vector<string> results;
    results.reserve(words.size());
    for(const auto& word : words) {
      auto sorted{ word };
      sort(sorted.begin(), sorted.end(), ascension_compare);
      if(sorted == word)
        results.emplace_back(move(sorted));
    }
    sort(results.begin(), results.end(), [](const auto& x, const auto& y) { return x.size() > y.size(); });
    for(const auto& result : results)
      if(interesting(result))
        cout << result << "\n";
  } catch(const std::exception& e) {
    cerr << e.what() << endl;
  }
}