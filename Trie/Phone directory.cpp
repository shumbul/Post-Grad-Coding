// https://practice.geeksforgeeks.org/problems/phone-directory4628/1

class Node{
public:
    char c;
    int count=0;
    set<string> words;
    map<char, Node*> children;
    Node(char &c){
        this->c=c;
    }
};

class Trie{
public:  
    Node* root;
    Trie(char c){
        root=new Node(c);
    }
    void insert(string &s){
        Node* temp=root;
        for(char &c: s){
            if(temp->children.count(c)==0){
                temp->children[c]=new Node(c);
            }
            temp=temp->children[c];
            temp->count++;
            temp->words.insert(s);
        }
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int N, string contact[], string s)
    {
        // code here
        Trie* trie=new Trie('\0');
        for(int i=0;i<N;i++){
            trie->insert(contact[i]);
        }
        
        vector<vector<string>> ans;
        Node* temp=trie->root;
        int i=0, n=s.length();
        for(i=0;i<n;i++){
            if(temp->children.count(s[i])==0){
                break;
            }
            temp=temp->children[s[i]];
            vector<string> v;
            for(string word:temp->words)
                v.push_back(word);
            ans.push_back(v);
        }
        while(i++<n){
            ans.push_back({"0"});
        }
        
        return ans;
    }
};

/*
Time: O(n*l*N)
Space: O(l*N)
where l = max length of a word in contact
        N = no. of contacts 
*/