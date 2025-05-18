class Solution {
public:
    // Heapify for 0-based indexing
    void heapify(vector<int> &a, int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;

        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }

    void heapsort(vector<int> &a) {
        int n = a.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(a, n, i);
        }

        // Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);
            heapify(a, i, 0);
        }
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;

        // Sort the array using custom heap sort
        heapsort(sorted);

        // Map each value to its rank (1-based)
        unordered_map<int, int> valueToRank;
        int rank = 1;
        for (int i = 0; i < sorted.size(); i++) {
            if (valueToRank.count(sorted[i]) == 0) {
                valueToRank[sorted[i]] = rank++;
            }
        }

        // Build the result using the rank map
        vector<int> result;
        for (int val : arr) {
            result.push_back(valueToRank[val]);
        }

        return result;
    }
};
