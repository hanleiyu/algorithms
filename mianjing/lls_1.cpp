

 long long minimum(vector<int>& a) {
        // write code here
        long  sum = 0;
        for (auto i : a)
            sum += i;
        long avg = sum / 2;
        vector<int>temp = a;
        int n = temp.size();
        for (int i = 0; i < n; i++)
            a.push_back(temp[i]);
        int i = 0, j = 0;
        long  ans = INT_MAX;
        long tt = 0;
        while (j < a.size())
        {
            while (j - i < n && j < a.size() && tt < avg)
            {
                tt += a[j];
                j++;
                ans = min(ans, abs(sum - tt - tt));
            }
            tt -= a[i];
            i++;
            ans = min(ans, abs(sum - tt - tt));
        }
        return ans;


    }
};