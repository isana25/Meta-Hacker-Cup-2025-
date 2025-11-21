GitHub Copilot Chat Assistant

# Problem A2: Snake Scales (Chapter 2)

## Problem

Solid Snake needs to inspect N platforms, numbered 1 to N. The i-th platform is a horizontal line segment from (i, A_i) to (i+1, A_i), inclusive. He can travel between two platforms with a ladder of height h or greater if there exists a vertical line segment of length h that intersects both platforms.

Additionally, Solid Snake may travel between any platform and the ground if his ladder is long enough. The ground can be modeled as the segment from (0, 0) to (N+1, 0). Solid Snake starts on the ground.

Write a program, "Scale AI", to find the length of the shortest ladder that Solid Snake needs to visit each platform at least once, starting from the ground.

## Constraints

- 1 ≤ T ≤ 80  
- 1 ≤ N ≤ 500,000  
- 1 ≤ A_i ≤ 10^9

## Input Format

The input begins with a single integer T, the number of test cases. For each test case:
- A line with a single integer N.
- A line with N space-separated integers A_1, ..., A_N.

## Output Format

For the i-th test case, print:
Case #i: <answer>

where <answer> is the length of the shortest ladder needed.

## Sample Explanation

In the first sample case there are N = 5 platforms with heights A = [2, 4, 5, 1, 4]. Solid Snake starts on the ground. To access all platforms, he needs a ladder of at least height 3. One possible strategy is to scale the first 3 platforms, return to the ground, then scale the last 2 platforms.

## Sample Input
6
5
2 4 5 1 4
3
13 10 11
4
1 3 3 7
1
42
3
5 50 42
7
4 2 5 6 4 2 1

## Sample Output
Case #1: 3
Case #2: 10
Case #3: 4
Case #4: 42
Case #5: 42
Case #6: 2

If you want, I can also produce a short solution outline or sample implementations (C++/Python) to accompany this README.
