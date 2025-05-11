class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxi(nums) - sumSubarrayMins(nums);
    }

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int> pse = findpsee(arr);
        long long total = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total += 1LL * left * right * arr[i];
        }
        return total;
    }

    long long sumSubarrayMaxi(vector<int>& arr) {
        vector<int> nle = findnle(arr);
        vector<int> ple = findplee(arr);
        long long total = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int left = i - ple[i];
            int right = nle[i] - i;
            total += 1LL * left * right * arr[i];
        }
        return total;
    }

    vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findpsee(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findnle(vector<int>& arr) {
        int n = arr.size();
        vector<int> nle(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nle;
    }

    vector<int> findplee(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ple;
    }
};
