#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    string s;
    set<int> q;
    int numbers;
    cin>>N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(N--){
        getline(cin,s);
        vector<int> queries;
        stringstream stream(s);
        while(stream >> numbers){
            queries.push_back(numbers);
        }
        int c=queries[0];
        switch(c){
        
        case 3:
            
            cout << *q.begin() <<endl;
            break;
         
        case 1:
            q.insert(queries[1]);
            break;
          
        case 2:
           q.erase(q.find(queries[1]));
           break;           
          
        }
    
    } 
      
    return 0;
}
