/* brute force but getting runtym error for time limit exceeding*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int cases(int a, int b){
    if(a>=b){
        return 1;
    }
    return 0;
}

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    long area=0;
    int n=h.size();
    for(int i=0;i<n;i++){
        long area_t=0;
        
        for(int j=0;j<n;j++){
            int c=cases(h[j],h[i]);
            switch (c) {
                case 1:area_t+=h[i];
                        cout << h[i] <<" " <<h[j] << " " << area_t <<endl;
                        break;
                case 0:if(j>i){
                            cout << h[i] <<" " <<h[j] << " " << area_t <<endl;
                            goto brake;
                            }
                        if(j<i){
                             cout << h[i] <<" " <<h[j] << " " << area_t <<endl;
                            area_t=0;
                            continue;
                            }
                        break;

                    }
        }
        brake:
        if(area_t>area){
            area=area_t;
        }
        
    }
    return area;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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

/* optimized soltion O(n)*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
/*
long area_c(stack<int> indexes_of_height,int topindex,vector<int> h,int i ){
    topindex=indexes_of_height.top();
    indexes_of_height.pop();
    long area=h[topindex]*(indexes_of_height.empty()? i:i-indexes_of_height.top()-1);

    return area;
}*/
// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    stack<int> indexes_of_height;
    int topindex;
    int max_area=0;
    int i=0;
    int n=h.size();
    while(i<n){  //passng trought hte heights
        if(indexes_of_height.empty() || h[indexes_of_height.top()]<=h[i]){
            //checking if the current bar is greater or equal height than the height of the bar at top index, 
            //if so insert te index into stack of indexes
            indexes_of_height.push(i);
            i++;
        }
        else{
            //if height is less than the height of the topindexes elment height
            // take the top index height and calulate the area of that height                       //considering the current index as the right most edge and previous index as the left most edge for the considered height.
        topindex=indexes_of_height.top();
        indexes_of_height.pop();
        long area=h[topindex]*(indexes_of_height.empty()? i:i-indexes_of_height.top()-1);
        if(max_area<area){
            max_area=area;
            }
        }
    }
    while(!indexes_of_height.empty()){
        // Now calculate the areas for the remaining indexes from top of stack untill stack is empty . i.e., by end of stack we would have calculates areas possible for all different heights.
        topindex=indexes_of_height.top();
        indexes_of_height.pop();
        long area=h[topindex]*(indexes_of_height.empty()? i:i-indexes_of_height.top()-1);
        if(max_area<area){
            max_area=area;
        }
    }
    return max_area;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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

