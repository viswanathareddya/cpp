#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the equalStacks function below.
*/
stack<int> reversev(vector<int> h){
    int temp;
    stack<int> temps={};
    int length=h.size();
    for(int i=length-1;i>=0;i--){
        temps.push(h[i]);
    }
    return temps;
}
vector<int> heights(vector<int> h1, vector<int> h2, vector<int> h3){
    
    int height1=0;
    int height2=0;
    int height3=0;
    for(int i=0;i<h1.size();i++){
            height1=height1+h1[i];
    }
    
    for(int i=0;i<h2.size();i++){
            height2+=h2[i];
    }

    for(int i=0;i<h3.size();i++){
            height3+=h3[i];
    }
    return {height1, height2, height3};
}


int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    /*
     * Write your code here.
     */
    vector<int> height=heights(h1,h2,h3);
     int sum1=height[0];
     int sum2=height[1];
     int sum3=height[2];
    stack<int> h1r=reversev(h1);
    stack<int> h2r=reversev(h2);
    stack<int> h3r=reversev(h3);
    while(1){
        if(h1r.size()==0 || h2r.size()==0 || h3r.size()==0){
            return 0;
        }
        if(sum1==sum2 && sum1==sum3){
            return sum1;
        }
        else if(sum1>=sum2 && sum1>=sum3){
            sum1-=h1r.top();
            h1r.pop();
        }
        else if(sum2>=sum1 && sum2>=sum3){
            sum2-=h2r.top();
            h2r.pop();
        }
        else if(sum3>=sum1 && sum3>=sum2){
            sum3-=h3r.top();
            h3r.pop();
        }
    }
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n1N2N3_temp;
    getline(cin, n1N2N3_temp);

    vector<string> n1N2N3 = split_string(n1N2N3_temp);

    int n1 = stoi(n1N2N3[0]);

    int n2 = stoi(n1N2N3[1]);

    int n3 = stoi(n1N2N3[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split_string(h1_temp_temp);

    vector<int> h1(n1);

    for (int h1_itr = 0; h1_itr < n1; h1_itr++) {
        int h1_item = stoi(h1_temp[h1_itr]);

        h1[h1_itr] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split_string(h2_temp_temp);

    vector<int> h2(n2);

    for (int h2_itr = 0; h2_itr < n2; h2_itr++) {
        int h2_item = stoi(h2_temp[h2_itr]);

        h2[h2_itr] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split_string(h3_temp_temp);

    vector<int> h3(n3);

    for (int h3_itr = 0; h3_itr < n3; h3_itr++) {
        int h3_item = stoi(h3_temp[h3_itr]);

        h3[h3_itr] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

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
