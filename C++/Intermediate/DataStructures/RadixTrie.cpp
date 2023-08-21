#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    bool isEndOfWord;
    unordered_map<string, TrieNode*> children;

    TrieNode() {
        isEndOfWord = false;
    }
};

class RadixTrie {
public:
    TrieNode* root;
    RadixTrie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;

        for (int i = 0; i < word.length(); i++) {
            string prefix = "";
            for (int j = i; j < word.length(); j++) {
                prefix += word[j];
                if (current->children.count(prefix) == 0) {
                    current->children[prefix] = new TrieNode();
                }
                current = current->children[prefix];
            }
            i += prefix.length() - 1;
        }

        current->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* current = root;

        for (int i = 0; i < word.length(); i++) {
            string prefix = "";
            for (int j = i; j < word.length(); j++) {
                prefix += word[j];
                if (current->children.count(prefix) == 0) {
                    return false;
                }
                current = current->children[prefix];
            }
            if (current->isEndOfWord) {
                return true;
            }
        }

        return current->isEndOfWord;
    }
};

void print(TrieNode* node, string prefix) {
    if (node->isEndOfWord) {
        cout << prefix << endl;
    }
    for (auto it = node->children.begin(); it != node->children.end(); it++) {
        print(it->second, prefix + it->first);
    }
}


int main() {
    RadixTrie trie;

    trie.insert("apple");
    trie.insert("application");
    trie.insert("banana");
    trie.insert("band");
    trie.insert("can");
    trie.insert("cat");

    print(trie.root, "");
    //cout << "Search for 'apple': " << (trie.search("apple") ? "Found" : "Not found") << endl;
    //cout << "Search for 'app': " << (trie.search("app") ? "Found" : "Not found") << endl;
    //cout << "Search for 'banana': " << (trie.search("banana") ? "Found" : "Not found") << endl;
    //cout << "Search for 'band': " << (trie.search("band") ? "Found" : "Not found") << endl;
    //cout << "Search for 'can': " << (trie.search("can") ? "Found" : "Not found") << endl;
    //cout << "Search for 'cat': " << (trie.search("cat") ? "Found" : "Not found") << endl;
    //cout << "Search for 'dog': " << (trie.search("dog") ? "Found" : "Not found") << endl;

    return 0;
}

