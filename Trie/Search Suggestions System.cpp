// https://leetcode.com/problems/search-suggestions-system/

class Node {
public: 
    char ch;
    unordered_map<char, Node*> children;
    vector<string> words;
    Node(char c){
        ch=c;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root=new Node('\0');
    }
    void insert(string s){
        Node* temp;
        temp=root;
        for(char c:s){
            if(temp->children.count(c)==0)
                temp->children[c]=new Node(c);
            temp=temp->children[c];
            temp->words.push_back(s);
            sort(temp->words.begin(), temp->words.end());
            if(temp->words.size()==4)
                temp->words.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie=new Trie;
        for(string &p: products)
            trie->insert(p);
        vector<vector<string>> ans;
        Node* temp=trie->root;
        for(char c: searchWord){
            if(temp->children.count(c)){
                temp=temp->children[c];
                ans.push_back(temp->words);
            }
            else
                break;
        }
        int n=ans.size();
        while(n<searchWord.length())
            ans.push_back({}), n++;
        return ans;
    }
};

/*
Time: O(length of serachWord + size of products n) 
Space: O(n)
*/

/*
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
*/