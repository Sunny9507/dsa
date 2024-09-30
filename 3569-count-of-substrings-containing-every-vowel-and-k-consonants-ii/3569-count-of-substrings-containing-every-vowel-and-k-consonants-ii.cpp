class Solution {
    public:
string vw = "aeiou";
long long countOfSubstrings(string w, int k) {
    int left = 0, mid = 0, vowels = 0, cnt[6] = {}, cnt1[6] = {};
    long long res = 0;
    for (int i = 0; i < w.size(); ++i) {
        int p = vw.find(w[i]) + 1;
        ++cnt[p];
        vowels += cnt[p] == 1 && p;
        while (cnt[0] > k) {
            auto p = vw.find(w[left++]) + 1;
            --cnt[p];
            vowels -= cnt[p] == 0 && p;
        }
        if (vowels == 5 && cnt[0] == k) {
            if (mid < left) {
                mid = left;
                memset(cnt1, 0, sizeof(cnt1));
            }
            for (int p = vw.find(w[mid]) + 1; p && cnt[p] - cnt1[p] > 1; p = vw.find(w[++mid]) + 1)
                ++cnt1[p];
            res += mid - left + 1;                
        }
    }
    return res;
}
};