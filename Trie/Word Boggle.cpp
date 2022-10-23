// https://practice.geeksforgeeks.org/problems/word-boggle4143/1

class Solution {
    class Node {
    public:
        char val;
        unordered_map<char, Node*> ch;
        bool eow;
        Node(char val){
            this->val=val;
            eow=false;
        }
    };
    class Trie {
    public: 
        Node* root;
        Trie(){
            root=new Node('\0');
        }
        void insert(string &s){
            Node* temp=root;
            for(auto &c: s){
                if(temp->ch.count(c)==0)
                    temp->ch[c]=new Node(c);
                temp=temp->ch[c];
            }
            temp->eow=true;
        }
    };
set<string> words;
int dx[8]={0, 0, -1, -1, -1, 1, 1, 1}, dy[8]={1, -1, 0, -1, 1, 0, -1, 1};
    void dfs(int i, int j, string s, Node *root, vector<vector<char> >& board, int &m, int &n) {
        char c=board[i][j];
        board[i][j]='#';
        
        if(root->eow){
            root->eow=false;
            words.insert(s);
        }
        
        for(int k=0;k<8;k++){
            int nx=dx[k]+i, ny=dy[k]+j;
            if(nx>=0 && ny>=0 && nx<n && ny<m && root->ch.count(board[nx][ny])){
                dfs(nx, ny, s+board[nx][ny], root->ch[board[nx][ny]], board, m, n);
            }
        }
        
        board[i][j]=c;
    }
public:
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    Trie *trie=new Trie();
	    vector<string> ans;
	    int n=board.size(), m=board[0].size();
	    for(auto &s: dictionary){
	        trie->insert(s);
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(trie->root->ch.count(board[i][j])){
	                string s;
	                s+=board[i][j];
	                dfs(i, j, s, trie->root->ch[board[i][j]], board, m, n);
	            }
	        }
	    }
	    for(auto &w: words)
	        ans.push_back(w);
	    return ans;
	}
};

/*
Time: O(n*m*(8^k))
Space: O(l*k), where i is the no. of words i dict and k is the max length of a word in the dict
*/