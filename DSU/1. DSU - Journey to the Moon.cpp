// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
 
class DSU{
    vector<int> par, rank;
public:
    DSU(int &n){
        par.resize(n, 0);
        rank.resize(n, 1);
        for(int i=0;i<n;i++)
            par[i]=i;
    }
    int Find(int a){
        if(a==par[a])
            return a;
        // path compression
        return par[a]=Find(par[a]);
    }
    void Union(int &a, int &b){
        int par_a=Find(a);
        int par_b=Find(b);
        if(par_a==par_b)
            return;
        if(rank[par_a]>=rank[par_b]){
            // a has larger group
            rank[par_a]+=rank[par_b];
            par[par_b]=par_a;
        }
        else{
            // b has larger group
            rank[par_b]+=rank[par_a];
            par[par_a]=par_b;
        }
    }
};

long long int journeyToMoon(int &n, vector<vector<int>> &astronaut) {
    DSU dsu(n);
    for(auto &a: astronaut){
        dsu.Union(a[0], a[1]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int a=dsu.Find(i);
            int b=dsu.Find(j);
            if(a!=b){
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


/*
Gives TLE on Testcase 11
Time Complexity: O(n^2)
Space Complexity: O(n)
*/