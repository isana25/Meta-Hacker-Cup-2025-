# Problem A1: Snake Scales (Chapter 1)

Problem

Solid Snake needs to inspect N platforms, numbered 1 to N. The i-th platform is a horizontal line segment from points (i, A_i) to (i+1, A_i), inclusive. Solid Snake starts on platform 1. He can travel between two platforms with a ladder of height h or greater if there exists a vertical line segment of length h that intersects both platforms.

Write a program, "Scale AI", to find the length of the shortest ladder that Solid Snake needs to visit each platform at least once, starting from platform 1.

Constraints
- 1 ≤ T ≤ 65
- 1 ≤ N ≤ 100
- 1 ≤ A_i ≤ 100

Input Format
Input begins with a single integer T, the number of test cases. The first line of each case contains a single integer N. The second line of each case contains N space-separated integers A_1, ..., A_N.

Output Format
For the i-th test case, print "Case #i: " followed by the length of the shortest ladder that Solid Snake needs to visit each platform at least once.

Sample

Input
```
1
5
2 4 5 1 4
```

Output
```
Case #1: 4
```

Explanation

Platforms are at heights [2, 4, 5, 1, 4]. A ladder of length 4 is required because the largest absolute difference between consecutive platform heights is |5 - 1| = 4. A vertical ladder placed at the shared x between adjacent platforms can connect them if and only if the ladder height is at least the absolute difference of their heights.

Solution Outline

Observation:
- A vertical ladder can only intersect two adjacent platforms at the integer x-coordinate shared by their segments (e.g., x = i+1 connects platform i and i+1).
- For adjacent platforms i and i+1, a ladder of height h can connect them iff |A_i - A_{i+1}| ≤ h.
- Therefore, to be able to reach every platform starting from platform 1, the ladder must be able to cross every adjacent gap along the chain. The minimum required ladder length is the maximum absolute difference between consecutive heights.

Algorithm:
1. For each test case, read N and the array A of length N.
2. Compute max_diff = max_{i=1..N-1} |A_i - A_{i+1}|.
3. Output "Case #t: " followed by max_diff.

Complexity
- Time: O(N) per test case (single pass to compute consecutive differences).
- Space: O(N) to store the heights (or O(1) extra if streaming).

Example C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int N; cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        int ans = 0;
        for (int i = 1; i < N; ++i) ans = max(ans, abs(A[i] - A[i-1]));
        cout << "Case #" << tc << ": " << ans << '\n';
    }
    return 0;
}
```

Notes
- This is the Chapter 1 version where the ground cannot be used; ladder movements are only via vertical lines that intersect platforms.
- The solution is intentionally simple due to the platforms being arranged sequentially.