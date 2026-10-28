#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 使用 pair 儲存 <數值, 原始索引位置>
    // 為了避免兩數相加超出整數範圍，數值型態使用 long long
    vector<pair<long long, int>> num(n);

    for (int i = 0; i < n; i++) {
        cin >> num[i].first;
        num[i].second = i;
    }

    // 針對數值由大到小進行排序 (greater 會先比 first，再比 second)
    sort(num.begin(), num.end(), greater<pair<long long, int>>());

    long long ans = LLONG_MIN;
    
    // 只取排名前 8 大的數字來互相配對
    int limit = min(n, 8);
    for (int i = 0; i < limit; i++) {
        for (int j = i + 1; j < limit; j++) {
            // 檢查兩數在原陣列中的索引距離是否大於 1（不相鄰）
            if (abs(num[i].second - num[j].second) > 1) {
                ans = max(ans, num[i].first + num[j].first);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
