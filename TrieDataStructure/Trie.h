#pragma once
#include <vector>
#include <memory>
#include <string>

class Trie {
private:
	struct Node {
		bool isEndOfTheWord;
		std::vector<std::shared_ptr<Node>> Nodes = std::vector<std::shared_ptr<Node>>(26);
		Node() : isEndOfTheWord(false) {};
	};

	std::shared_ptr<Node> root;
public:
	Trie();

	void Insert(std::string& word);
	std::string Search(std::string& word) const;
};

