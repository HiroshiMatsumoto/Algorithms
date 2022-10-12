#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <regex>
#include <vector>
#include <string>
#include "cmdline.h"
#include "spdlog/spdlog.h"
#include "progressbar/include/progressbar.hpp"
#include <chrono>
// #include "CppProgressBar/include/CppProgressBar.hpp"
#include "pbar/pbar.hpp" 

using namespace std;

int get_line_count(string filepath){
  ifstream read_file;
  read_file.open(filepath, ios::in);            
  string line = ""; 
  int count = 0;                              
  while(getline(read_file, line))             
    count++;                                  
  return count;
}

vector<string> split(string str, char del) {
  int first = 0;
  int last = str.find_first_of(del);

  vector<string> result;

  while (first < (int)str.size()) {
    string subStr(str, first, last - first);

    result.push_back(subStr);

    first = last + 1;
    last = str.find_first_of(del, first);

    if (last == (int)string::npos) {
      last = (int)str.size();
    }
  }
  return result;
}

void strip(string *text) {
  (*text).erase(std::remove((*text).begin(), (*text).end(), ' '),
                (*text).end());
}


string load_regex(string filepath){
  string reg = "";
  ifstream read_file;
  read_file.open(filepath, ios::in);
  getline(read_file, reg);
  return reg;
}


void split(string line, string delim){
  // auto elems = line.find(delim);
  // cout << elems << endl;
}

typedef vector<int> Ngram;
typedef tuple<Ngram, int> NgramFreq;
typedef map<int, NgramFreq> NgramList;
NgramList load_ngram(string filepath, string ngram_regex_filepath){
  // cout << "loading ngram: ";

  ifstream read_file;
  read_file.open(filepath, ios::in);
  string line = "";

  string reg = load_regex(ngram_regex_filepath);
  regex re(reg);
  smatch match;
  int frequency;
  NgramList ngram_list;
  vector<int> ngram;

  int total = get_line_count(filepath);

  pbar::pbar bar(total, 100, "[load_ngram]");
  bar.init();
  while(getline(read_file, line)){
    bar++;
    if(regex_match(line, match, re)){
      frequency = stoi(match[1]);
      for(int i = 2; i < (int)match.size(); i++){
        ngram.push_back(stoi(match[i]));
      }
      ngram_list.emplace(ngram[0], make_tuple(ngram, frequency));
    }
  }
  return ngram_list;
}


typedef map<int, pair<int, string>> Vocab;
typedef pair<int, pair<int, string>> VocabEntry; 

Vocab load_vocab(string vocab_filepath, string vocab_regex_filepath) {


  ifstream read_file;
  read_file.open(vocab_filepath, ios::in);
  
  // load vocab
  string line = "";
  Vocab vocab;
  string reg = load_regex(vocab_regex_filepath); 
  std::regex re(reg);
  std::smatch match;
  int total_frequency = 0;
  int token_id = 0; 
  int frequency = 0; 
  string lemma = "";
  int total = get_line_count(vocab_filepath);
  // progressbar bar(count);
  pbar::pbar bar(total, 100, "[load_vocab]");
  bar.init();
  while (getline(read_file, line)) {
    ++bar;
    // bar.update();
    if(regex_match(line, match, re)){
      token_id = stoi(match[1]);
      frequency = stoi(match[2]);
      lemma = match[3];
      VocabEntry entry = {token_id, {frequency, lemma}};
      vocab.insert(entry);

      total_frequency += frequency;
    }
  }
  return vocab;
}


int main(int argc, char *argv[]) {
  // Command Line Options
  cmdline::parser argopt;
  // add specified type of variable.
  // 1st argument is long name
  // 2nd argument is short name (no short name if '\0' specified)
  // 3rd argument is description
  // 3th argument is mandatory (optional. default is false)
  // 5th argument is default value  (optional. it used when mandatory is false)
  argopt.add<string>("vocab", 'v', "vocabulary file");
  argopt.add<string>("ngram", 'n', "ngram file");
  argopt.add<string>("vregex", '\0', "regex file for vocabulary");
  argopt.add<string>("nregex", '\0', "regex file for ngram");

  // Run parser.
  argopt.parse_check(argc, argv);

  string ngram_filepath = argopt.get<string>("ngram");
  string ngrex_filepath = argopt.get<string>("nregex");
  NgramList ngram_list = load_ngram(ngram_filepath, ngrex_filepath);
 
  for(NgramList::iterator ngram_map_itr = ngram_list.begin(); ngram_map_itr!= ngram_list.end(); ++ngram_map_itr){
    // itr->second
    // ngram_itr->second.second.begin();
    std::cout << "ID: " << ngram_map_itr->first << std::endl;
    NgramFreq ngram_freq = ngram_map_itr->second;
    Ngram ngram = std::get<0>(ngram_freq);
    int frequency = std::get<1>(ngram_freq);
    for(Ngram::iterator ngram_itr = ngram.begin(); ngram_itr != ngram.end(); ++ngram_itr){
      std::cout << *ngram_itr << ", " << std::endl;
    }
    std::cout << "freq: " << frequency << std::endl;
    std::cout << std::endl; 
  }

  string vocab_filepath = argopt.get<string>("vocab");
  string vregex_filepath = argopt.get<string>("vregex");
  Vocab vocab = load_vocab(vocab_filepath,vregex_filepath); 
  
  return 0;
}
