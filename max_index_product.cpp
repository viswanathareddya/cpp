/*brute-force*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int solve(vector<int> arr) {
    int temp=0;
    
    int n=arr.size();
    for(int i=1;i<n-1;i++){
        int l_max,r_max,t_max;
        
        for(int j=i-1; j>=0; j--){
           
            if(arr[j]>arr[i]){
               l_max=j+1;
               break;
            }
            else{
                l_max=0;
            }
                        
        }
        if (l_max==0){
            goto max;        }
        for(int k=i+1;k<n;k++){
            if(arr[k]>arr[i]){
                r_max=k+1;
              
                break;
            }
            else{
                r_max=0;
            }
        }
        max:
        t_max=l_max*r_max;
       
        if (t_max>temp){
            temp=t_max;
        }

    }
    
    return temp;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    int result = solve(arr);

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
/*optimized*/

