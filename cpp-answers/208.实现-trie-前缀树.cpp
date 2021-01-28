/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class TrieNode {
public:
    TrieNode* next[26];
    bool isword;
    TrieNode() {
        memset(next, NULL, sizeof(next));
        isword = false;
    }
    ~TrieNode(){
        for(int i = 0; i < 26; i++)
        {
            if(next[i])
                delete next[i];
        }
    }
};
class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(p -> next[word[i] - 'a'] == NULL)
                p -> next[word[i] - 'a'] = new TrieNode();
            p = p -> next[word[i] - 'a'];
        }
        p -> isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size() && p; i++)
        {
            p = p -> next[word[i] - 'a'];
        }
        return p && p -> isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i = 0; i < prefix.size() && p; i++)
        {
            p = p -> next[prefix[i] - 'a'];
        }
        return p;
    }
    ~Trie() {
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

