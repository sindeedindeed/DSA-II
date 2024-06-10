#include <iostream>
#include <vector>
#include <algorithm>

int longSub(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> lis;
    
    for (int i = 0; i < n; ++i) {
        auto it = std::lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) {
            lis.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
    }

    return lis.size();
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << longSub(arr) << std::endl;
    return 0;
}
