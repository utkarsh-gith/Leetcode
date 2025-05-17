class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] == NULL)
        {
            return false;
        }

        child = root->children[index];
        return searchUtil(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }

    // bool startsWithUtil(TrieNode* root, const string& word, int index) {
    //     if (index == word.length()) return true;

    //     int childIndex = word[index] - 'a';
    //     if (root->children[childIndex] == NULL) return false;

    //     return startsWithUtil(root->children[childIndex], word, index + 1);
    // }

    // bool startsWith(string prefix) {
    //  return startsWithUtil(root, prefix, 0);
    // }
    bool startsWithUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] == NULL)
        {
            return false;
        }

        child = root->children[index];
        return startsWithUtil(child, word.substr(1));
    }
    bool startsWith(string prefix)
    {
        return startsWithUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// OR

class TrieNode
{
public:
    bool isTerminal;
    vector<TrieNode *> children;

    TrieNode()
    {
        isTerminal = false;
        children.resize(26, NULL);
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char x : word)
        {
            int index = x - 'a';
            if (node->children[index] == NULL)
            {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isTerminal = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char x : word)
        {
            int index = x - 'a';
            if (node->children[index] == NULL)
            {
                return false;
            }
            node = node->children[index];
        }
        return node->isTerminal;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char x : prefix)
        {
            int index = x - 'a';
            if (node->children[index] == NULL)
            {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */