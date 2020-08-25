#include <cmath>
#include <cstdio>
#include <stack>
#include <sstream>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int max_element(stack<int> ol){
    stack<int> temp=ol;
    int max=0;
    while(!temp.empty()){
    if (temp.top()>max){
        max=temp.top();
    }
    temp.pop();
    }
    return max;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string query;
    int qno;
    int max;
    stack<int> listob;
    while(N--){
        getline(cin,query);
        stringstream s(query);
        list<int> qvec;
        while(s>>qno){
            qvec.push_back(qno);
        }
        int n= qvec.front();
        int ele=qvec.back();
        switch(n){
            case 1:
                if (listob.empty()){
                    listob.push(ele);
                    max=qvec.back();
                    //cout << '1' <<max << ele << endl;
                    break;
                }
                if(ele>max){
                    listob.push(ele);
                    max=ele;
                    //cout << '1'<< max << ele << endl;
                }
                else{
                    listob.push(ele);
                    //cout << '1'<< max << ele << endl;
                }
                break;
            case 2:
                if (listob.top()==max){
                    //cout <<'2'<<listob.top() <<endl;
                        listob.pop();
                        max=max_element(listob);
                      //  cout <<'2'<< max<<endl;
                        }
                else{
                    //cout <<'2'<<listob.top() <<endl;
                    listob.pop();
                    //cout <<'2'<<max <<endl;
                }
                break;
            case 3:
                cout << max << endl;              
                break;

        }
    }  
    return 0;
}
