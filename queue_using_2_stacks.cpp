/* solution using 2 stacks*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    stack<int> deque;

    stack<int> que;
    while(N--){
        int type, x;
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            deque.push(x);
        }    
        else 
        {
           if(que.empty())
           { // move all the elements from "deque" stack to "que" stack
               while(!deque.empty())
               {
                   que.push(deque.top());
                   deque.pop();
               }   
            }    
           if(!que.empty())
           {
               if(type == 2) que.pop();
               if(type == 3) cout << que.top() << endl;
           }  
        }   
    } 
    return 0;
}





/* solution but not using 2 stacks */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    queue<int> que;
    while(N--){
        string s;
        int numbers;
        getline(cin,s);
        vector<int> query;
        stringstream stream(s);
        while(stream>>numbers){
            query.push_back(numbers);
        }
        switch(query[0]){
            case 1: que.push(query[1]);
                    break;
            case 2:que.pop();
                    break;
            case 3: cout << que.front() << endl;
                    break;
        }
    } 
    return 0;
}
