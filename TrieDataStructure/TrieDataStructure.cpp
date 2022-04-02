#include <iostream>
#include <string>
#include <fstream>
#include "Trie.h"
#include <sstream>

std::ifstream& operator>>(std::ifstream& ifs, Trie& trie) {
    while (!ifs.eof()) {
        std::string line;
        std::getline(ifs, line);
        trie.Insert(line);
    }

    return ifs;
}

std::ostream& operator<<(std::ostream& os, Trie& trie) {
    std::cout << "Write an english sentence" << std::endl;

    std::string mySentence = "";

    std::getline(std::cin,mySentence);

    const char space_char = ' ';
    std::vector<std::string> words;

    std::stringstream sstream(mySentence);
    std::string word;
    while (std::getline(sstream, word, space_char)) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }

    for (const auto& str : words) {
        os << str + " - " + trie.Search(str) << std::endl;
    }
    return os;
}

int main()
{
    Trie trie = Trie();

    std::ifstream inputFile("wordsEn.txt");

    inputFile >> trie;

    std::cout << trie;
}
