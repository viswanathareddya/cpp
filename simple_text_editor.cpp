#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

vector<string> splitstring(string s);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    string S;
    stack<string> undo;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    while(N--){
        string s;
        getline(cin,s);
        vector<string> query=splitstring(s);
        int q=stoi(query[0]);
        switch(q){
            case 1: undo.push(S);
                    S.append(query[1]);
                    break;
            case 2: undo.push(S);
                    S.erase(S.end()-stoi(query[1]),S.end());
                    break;
            case 3: cout << S[stoi(query[1])-1] << endl;
                    break;
            case 4: S=undo.top();
                    undo.pop();
                    break;
        }
    }
    
    return 0;
}

vector<string> splitstring(string s){
    string::iterator newend=unique(s.begin(),s.end(),[](const char &x,const char &y)            {return x == y && x==' ';});
    s.erase(newend,s.end());
    while(s[s.length()-1]==' '){
        s.pop_back();
    }
    vector<string> splits;
    char delimiter=' ';

    size_t i=0;
    size_t pos=s.find(delimiter);

    while(pos!= string::npos){
        splits.push_back(s.substr(i,pos-i));
        i=pos+1;
        pos=s.find(delimiter,i);
    }
    splits.push_back(s.substr(i,min(pos,s.length()-i+1)));
    return splits;
   }
