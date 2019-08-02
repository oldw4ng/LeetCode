/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 *
 * https://leetcode.com/problems/stream-of-characters/description/
 *
 * algorithms
 * Hard (42.04%)
 * Likes:    101
 * Dislikes: 31
 * Total Accepted:    5.9K
 * Total Submissions: 14.1K
 * Testcase Example:  '["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query"]\n[[["cd","f","kl"]],["a"],["b"],["c"],["d"],["e"],["f"],["g"],["h"],["i"],["j"],["k"],["l"]]'
 *
 * Implement the StreamChecker class as follows:
 * 
 * 
 * StreamChecker(words): Constructor, init the data structure with the given
 * words.
 * query(letter): returns true if and only if for some k >= 1, the last k
 * characters queried (in order from oldest to newest, including this letter
 * just queried) spell one of the words in the given list.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init
 * the dictionary.
 * streamChecker.query('a');          // return false
 * streamChecker.query('b');          // return false
 * streamChecker.query('c');          // return false
 * streamChecker.query('d');          // return true, because 'cd' is in the
 * wordlist
 * streamChecker.query('e');          // return false
 * streamChecker.query('f');          // return true, because 'f' is in the
 * wordlist
 * streamChecker.query('g');          // return false
 * streamChecker.query('h');          // return false
 * streamChecker.query('i');          // return false
 * streamChecker.query('j');          // return false
 * streamChecker.query('k');          // return false
 * streamChecker.query('l');          // return true, because 'kl' is in the
 * wordlist
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 2000
 * Words will only consist of lowercase English letters.
 * Queries will only consist of lowercase English letters.
 * The number of queries is at most 40000.
 * 
 * 
 */
class Trie {
    unordered_map<char, Trie*> map;
    char letter;
    bool isWord;
public:
    Trie(char c) {
        letter = c;
        isWord = false;
    }
    
    void add(string word) {
        Trie* p = this;
        for (int i = 0; i < word.size(); ++i) {
            if (!p -> map.count(word[i])) {
                p -> map[word[i]] = new Trie(word[i]);
            }
            p = p -> map[word[i]];
        }
        p -> isWord = true;
    }
    
    bool find(string word) {
        Trie* p = this;
        for (int i = 0; i < word.size(); ++i) {
            if (!p -> map.count(word[i])) {
                return false;
            } else {
                p = p -> map[word[i]];
            }
            if (p -> isWord) {
                return true;
            }
        }
        return p -> isWord;
    }
};


class StreamChecker {
    Trie* root;
    size_t maxSize = 0;
    string buffer = "";
public:
    
    StreamChecker(vector<string>& words) {
        root = new Trie(' ');
        for (auto item : words) {
            reverse(item.begin(), item.end());
            root -> add(item);
            maxSize = max(maxSize, item.size());
        }
    }
    
    bool query(char letter) {
        buffer = letter + buffer;
        if (buffer.size() > maxSize) {
            buffer.pop_back();
        }
        return root -> find(buffer);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

