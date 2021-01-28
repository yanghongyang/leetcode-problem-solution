#### 思路
- 前缀树
- 设计

#### 何为前缀树
[字典树](https://oi-wiki.org/string/trie/)

#### 思路
前缀树包括前缀树节点，因此要先设计出前缀树节点 `TrieNode` 。而根据题目，插入字符串只包含小写字母，因此树节点的 `next` 指针应该设置为 `TrieNode* next[26]` 。

整个 `Trie` 树的实现包括三个方法，`insert()` 方法表示在前缀树中插入一个字符串，`search()` 表示在已有前缀树中找到某个字符串， `startsWith()` 用来判断前缀树中是否存在以某个字符串为开头的字符串。

**代码**
```cpp []
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
```

#### 后记
这篇题解写的较为简略，如有看不懂的可以看：[一篇文章搞懂Trie树 | C++实现以及实战练习](https://zhuanlan.zhihu.com/p/34747612)
