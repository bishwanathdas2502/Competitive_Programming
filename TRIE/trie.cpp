struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        for(int i = 0;i<26;i++){
            child[i] = NULL;
        }
        isEnd = false;
    }
};


//initialise trie
TrieNode *root = new TrieNode();


//insert
void insert(string word) {
    TrieNode *node = root;

    for(int i = 0;i<word.length();i++){
        char c = word[i];
        if(node->child[c-'a'] == NULL){
            node->child[c-'a'] = new TrieNode();
        }
        node = node->child[c-'a'];
    }
    node->isEnd = true;
}


//search
bool search(string word) {
    TrieNode *node = root;

    for(int i = 0;i<word.size();i++){
        char c = word[i];
        if(node->child[c-'a'] == NULL){
            return false;
        }
        node = node->child[c-'a'];
    }

    return node->isEnd;
}

//prefix Search
bool startsWith(string prefix) {
    TrieNode *node = root;

    for(int i = 0;i<prefix.size();i++){
        char c = prefix[i];
        if(node->child[c-'a'] == NULL){
            return false;
        }
        node = node->child[c-'a'];
    }

    return true;
}
