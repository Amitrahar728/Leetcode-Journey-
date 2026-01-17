class Solution {

public:
    //  pehle hi maxwidth or maxheight apne ko calculate krni padegi isme srif kuch hi fences h khet m or unme se kitni bhi hatta shkte h 
    // iski vajah se maxwidth jo harr round m collect hoti h or maxheight jo calculate hoti h agar khi bhi same ayye to side ko increase krna h kisike bhi remove krne se 

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        // sort(hFences.begin() , hFences.end());
        // sort(vFences.begin() , vFences.end());

        unordered_set<int> st;
        for(int i = 0; i<hFences.size()-1; i++){
            for(int j =i+1; j<hFences.size();j++){
                int diff = abs(hFences[i]-hFences[j]);
                st.insert(diff);
            }
        }
        int maxside =-1;
        for(int i =0;i<vFences.size()-1; i++){
            for(int j =i+1; j<vFences.size(); j++){
                int gap = abs(vFences[i] - vFences[j]);
                if (st.count(gap)) {
                    maxside = max(maxside, gap);
                }
            }
        }
        if(maxside == -1)
            return -1;

        
            long long area = (long long)maxside*maxside;
            return ( area )%MOD;
        




    }   
};