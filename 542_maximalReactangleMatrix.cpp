#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Function to calculate the largest rectangle area in a histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    heights.push_back(0); // Add a sentinel value to handle remaining elements in the stack

    for (int i = 0; i < heights.size(); ++i) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    return maxArea;
}

// Function to calculate the maximal rectangle in a binary matrix
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << "Maximal Rectangle Area: " << maximalRectangle(matrix) << endl;

    return 0;
}