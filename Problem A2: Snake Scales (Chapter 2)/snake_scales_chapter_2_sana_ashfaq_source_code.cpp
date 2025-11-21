#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool can_reach_all(int n, vector<long long>& A, long long ladder_height) {
    vector<bool> visited_Platforms(n, false);
    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        if (A[i] <= ladder_height) {
            visited_Platforms[i] = true;
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (curr > 0 && !visited_Platforms[curr - 1]) {
            if (abs(A[curr] - A[curr - 1]) <= ladder_height) {
                visited_Platforms[curr - 1] = true;
                q.push(curr - 1);
            }
        }
        
        if (curr < n - 1 && !visited_Platforms[curr + 1]) {
            if (abs(A[curr] - A[curr + 1]) <= ladder_height) {
                visited_Platforms[curr + 1] = true;
                q.push(curr + 1);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited_Platforms[i]) {
            return false;
        }
    }
    return true;
}

long long find_min_ladder(int n, vector<long long>& A) {
    long long left = 0;
    long long right = *max_element(A.begin(), A.end());
    long long answer = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (can_reach_all(n, A, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}

// I was facing issues in input and ouput files so I added some error handling code for my ease and saving output in output file

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    
    if (!infile) {
        cout << "ERROR: Cannot open input.txt" << endl;
        return 1;
    }
    
    int t;
    infile >> t;
    
    for (int tc = 1; tc <= t; tc++) {
        int n;
        infile >> n;
        
        vector<long long> A(n);
        for (int i = 0; i < n; i++) {
            infile >> A[i];
        }
        
        long long answer = find_min_ladder(n, A);
        
        outfile << "Case #" << tc << ": " << answer << "\n";
        cout << "Case #" << tc << ": " << answer << endl;
    }
    
    infile.close();
    outfile.close();
    
    cout << "\nSolution has been completed! Check my output.txt" << endl;
    
    return 0;
}
