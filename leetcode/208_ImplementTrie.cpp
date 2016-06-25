class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *next[26];
    bool exist;

    TrieNode() {
        memset(next, 0, 26*sizeof(TrieNode*));
        exist = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        int len = word.size();
        int i =0;
        while(i < len)
        {
            if(p->next[word[i]-'a']==NULL)
            {
                p->next[word[i]-'a'] = new TrieNode;
            }
            p = p->next[word[i]-'a'];
            i++;
        }
        p->exist = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        int len = word.size();
        int i = 0;
        while(i < len)
        {
            p =  p->next[word[i]-'a'];
            if(p==NULL)
                return false;
            else
            {
                i++;
            }
        }
        if(p->exist==true)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        int len = prefix.length();
        int i = 0;
        while(i < len)
        {
            p =  p->next[prefix[i]-'a'];
            if(p==NULL)
                return false;
            else
            {
                i++;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
