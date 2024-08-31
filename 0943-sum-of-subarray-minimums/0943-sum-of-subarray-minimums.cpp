#define ll long long int
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = nextSmallerElement(arr);
        vector<int> pse = preSmallOrEqualElement(arr);

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll left = i - pse[i];
            ll right = nse[i] - i;
            sum = (sum + (left * right % mod) * arr[i] % mod) % mod;
        }

        return sum;
    }

private:
    int mod = 1e9 + 7;

    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        return res;
    }

    vector<int> preSmallOrEqualElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            }
            st.push(i);
        }

        return res;
    }
};