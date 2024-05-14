#include <iostream>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

int fact (int a) {
    if (a <= 1) {
        return 1;
    }
    return a * fact(a - 1);
}
//->
void taskA () {
    int result, n;
    cin >> n;
    result = fact(n);
    cout << result;
}
//<-
//->

void taskB () {
    int n, k, result;
    cin >> n >> k;
    result = fact(n) / fact (n - k) / fact(k);
    cout << result;
}
//<-
//->
void taskC () {
    int n, k, result;
    cin >> n >> k;
    result = fact(k + n - 1) / fact (n - 1) / fact(k);
    cout << result;
}
//<-
//->
void taskA2 () {
    int n, l, r, cntr = 1;//,
        //maxint = std::numeric_limits<int>::max();
    std::cin >> n;
    std::map<int, int> segments;
    for (int i = 0; i < n; ++ i) {
        std::cin >> l >> r;
        if (segments.find(l) == segments.end()) {
            segments[l] = r;
        } else {
            segments[l] = std::min(segments[l], r);
        }
    }
    auto it = segments.begin();
    r = it->second;
    for (const auto &elem : segments) {
        if (elem.first > r) {
            ++ cntr;
            r = elem.second;
        }
    }
    std::cout << cntr;
}
//<-
//->

//<-
//->

//<-
//->

//<-
//->

//<-
//->

//<-
int main () {
    taskA2();
    return 0;
}
