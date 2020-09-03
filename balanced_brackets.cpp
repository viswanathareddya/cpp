#include <bits/stdc++.h>

using namespace std;



string isBalanced(string s) {
    string Y="YES";
    string N="NO";
    map<char,char> br;
    br['{']='}';
    br['[']=']';
    br['(']=')';
    int n=s.size();
    if(n%2!=0){
        return N ;
    }
    stack<char> braceso;
    for(int i=0;i<n;i++){
    char c=s[i];
    switch(c){
        case '{': braceso.push(c);
                    break;
        case '(': braceso.push(c);
                    break;
        case '[': braceso.push(c);
                    break;
        case '}':if (braceso.empty()){
                    return N;
                    }
                 if (br[braceso.top()]!=c){
                    return N;
                    
                    }
                 else {
                    braceso.pop();
                    }
                 break;
        case ']':if (braceso.empty()){
                    return N;
                    }
                 if (br[braceso.top()]!=c){
                    return N;
                    }
                 else {
                    braceso.pop();
                    }
                    break;
        case ')':if (braceso.empty()){
                    return N;
                    }
                 if (br[braceso.top()]!=c){
                    return N;
                    }
                 else {
                    braceso.pop();
                    }
                    break;
        }
    }
    if(!braceso.empty()){
        return N;
    }
    
    
    return Y;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";

     //isBalanced(s);  
    }

    fout.close();

    return 0;
}
