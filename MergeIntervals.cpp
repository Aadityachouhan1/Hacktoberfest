#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // If there are no intervals, return an empty result
    if (intervals.empty()) return {};

    // Sort intervals by the start value
    sort(intervals.begin(), intervals.end());

    // Create a result vector to hold merged intervals
    vector<vector<int>> merged;

    // Initialize the first interval as the first merged interval
    merged.push_back(intervals[0]);

    // Traverse the intervals and merge as necessary
    for (int i = 1; i < intervals.size(); i++) {
        // Get the last merged interval
        vector<int>& lastMerged = merged.back();

        // If the current interval overlaps with the last merged interval
        if (intervals[i][0] <= lastMerged[1]) {
            // Merge the intervals by updating the end of the last merged interval
            lastMerged[1] = max(lastMerged[1], intervals[i][1]);
        } else {
            // Otherwise, add the current interval as a new interval
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main() {
    // Example case
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Get the result
    vector<vector<int>> result = mergeIntervals(intervals);

    // Print the result
    cout << "Merged Intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}
