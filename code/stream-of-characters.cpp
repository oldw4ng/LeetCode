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