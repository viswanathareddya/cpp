#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the waiter function below.
 */
bool isprime(int n){
    if(n<=1){
        return false;
    }
    if(n<=3){
        return true;
    }
    if(n%2==0 || n% 3==0){
        return false;
    }
    for(int i=5;i*i<=n;i=i+6){
        if(n%i==0 || n%(i+2)==0){
            return false;
        }
    }
    return true;
}
  
vector<int> prime(int q){
    vector<int> pa;
    if (q==1){
        pa.push_back(2);
    }
    if (q==2){
        pa.push_back(2);
        pa.push_back(3);
    }
    if(q>=3){
        pa.push_back(2);
        pa.push_back(3);
        for(int i=4;i<INT_MAX;i++){
            if(isprime(i)){
                pa.push_back(i);
            }
            if(pa.size()==q){
                break;
            }
        }
    }
    return pa;
}


vector<int> waiter(vector<int> number, int q) {
    /*
     * Write your code here.
     */
     stack<int> a0;
     for(int i=0;i<number.size();i++){
         a0.push(number[i]);
     }
     vector<int> finalv;
     vector<int> primenum=prime(q);
     stack<int> b1;
     stack<int> a1;
     stack<stack<int>> bi;
     for(int i=0;i<q;i++){
         while(!a0.empty()){
         if(a0.top()%primenum[i]==0){
             b1.push(a0.top());
             a0.pop();
            }
         else{
             a1.push(a0.top());
             a0.pop();
            }
        }
        a0=a1;
        bi.push(b1);
        while(!b1.empty()){
            b1.pop();
        }
        while(!a1.empty()){
            a1.pop();
        }
        if(i==q-1 && !a0.empty()){
            bi.push(a0);
        }

     }
     stack<stack<int>> bf;
     while(!bi.empty()){
        bf.push(bi.top());
        bi.pop();
     }
     while(!bf.empty()){
         while(!(bf.top()).empty()){
            finalv.push_back((bf.top()).top());
            (bf.top()).pop();
         }
         bf.pop();
     }
    return finalv;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split_string(number_temp_temp);

    vector<int> number(n);

    for (int number_itr = 0; number_itr < n; number_itr++) {
        int number_item = stoi(number_temp[number_itr]);

        number[number_itr] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
