// TRIE

class Node {
public:
    string data;
    unordered_map <string, Node *>children;
    bool isTerminal;

    Node(string &val) {
        data=val;
        isTerminal=false;
    }
};

class Trie {
    Node* root;

public: 
    Trie() {
        root=new Node("\0");
    }

    void insert(string &word) {
        Node* temp=root;

        for (char &ch: word) {
            if (temp - > children.count(s)==0) {
                Node * n=new Node(s);
                temp ->children[s]=n;
            }

            temp=temp ->children[s];
        }

        temp ->isTerminal=true;
    }

    bool search(string &word) {
        Node* temp=root;

        for (char &ch: word) {
            if (temp - > children.count(s)==0) {
                return false;
            }

            temp=temp ->children[s];
        }

        temp ->isTerminal=true;
    }
};