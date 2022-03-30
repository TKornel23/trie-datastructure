#include<vector>
#include<memory>
#include<string>

#include "Trie.h"

Trie::Trie()
{
	root = std::shared_ptr<Node>(new Node());
}

void Trie::Insert(std::string& word)
{
	auto p = root.get();

	for (size_t i = 0; i < word.length(); i++)
	{
		if (static_cast<uint8_t>(word[i]) > 96 && static_cast<uint8_t>(word[i]) < 123)
		{
			int asciiIndex = static_cast<uint8_t>(word[i]) - 97;
			if (!p->Nodes[asciiIndex]) {
				p->Nodes[asciiIndex] = std::shared_ptr<Node>(new Node());
			}

			p = p->Nodes[asciiIndex].get();
		}
	}
	p->isEndOfTheWord = true;
}

std::string Trie::Search(std::string& word) const
{
	auto p = root.get();
	for (size_t i = 0; i < word.length(); i++)
	{
		if (static_cast<uint8_t>(word[i]) > 96 && static_cast<uint8_t>(word[i]) < 123)
		{
			uint8_t asciiIndex = static_cast<uint8_t>(word[i]) - 97;
			if (!p->Nodes[asciiIndex]) {
				return "no";
			}
			p = p->Nodes[asciiIndex].get();
		}
	}
	if (!p->isEndOfTheWord) {
		return "no";
	}
	return "yes";
}
