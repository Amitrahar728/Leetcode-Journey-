class Solution {
public:
    string removeTrailingSpaces(const string& s) {
    auto start = find_if(s.begin(), s.end(), [](char c) {
        return !isspace(static_cast<unsigned char>(c));
    });
    auto end = find_if(s.rbegin(), s.rend(), [](char c) {
        return !isspace(static_cast<unsigned char>(c));
    }).base();

    // If the entire string is spaces, return an empty string
    if (start >= end) return "";

    // Extract trimmed part of the string
    string trimmed(start, end);

    // Reduce multiple spaces between words to a single space
    istringstream stream(trimmed);
    string word, result;
    while (stream >> word) {
        if (!result.empty()) {
            result += " ";
        }
        result += word;
    }

    return result;
}
    string reverseWords(string s) {
        string str;
        vector<string> arr;
        string s1 ="";
        string k = removeTrailingSpaces(s);
        stringstream ss(k);
        while (getline(ss, str, ' ')) {
            arr.push_back(str);
        }
         
        for(int i =arr.size()-1; i>=0; i--){
            s1+=arr[i];
            if(i!=0){
                s1+=" ";
            }
        }
        //  cout<<arr[i]<<endl;
        // }
    return s1;
    }
};