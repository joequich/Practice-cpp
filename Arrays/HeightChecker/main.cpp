#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    // int heightChecker(vector<int>& heights) {
    //     int countDontMatch = 0;

    //     for (int i = 0; i < heights.size(); i++) {
    //         /* code */
    //         int tempValue = heights[i];
    //         for (int j = heights.size() - 1; j > i; j--) {
    //             /* code */
    //             if (heights[j] < heights[j - 1]) {
    //                 int currentValue = heights[j - 1];
    //                 heights[j - 1] = heights[j];
    //                 heights[j] = currentValue;
    //             }
    //         }

    //         if (heights[i] != tempValue) {
    //             countDontMatch++;
    //         }
    //     }

    //     for (int i = 0; i < heights.size(); i++) {
    //         std::cout << heights[i];
    //         if (i != heights.size()-1) {
    //             std::cout << ",";
    //         }
    //     }
    //     std::cout << "\n";

    //     return countDontMatch;
    // }

    // nyx's solution
    int heightChecker1(vector<int>& heights) {
        
        int countMismatches = 0;
        vector<int> expectedHeights = heights;

        std::sort(expectedHeights.begin(), expectedHeights.end());

        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expectedHeights[i]) {
                countMismatches++;
            }
        }

        return countMismatches;
    };

    // nyx's solution
    int heightChecker2(vector<int>& heights) {
        int countMismatches = 0;
        int maxHeight = 0;
        int sortedPosition = 0;
        vector<int> sortedHeights(heights.size());

        // finds the maximun number int he array
        for (int height : heights) {
            if (height > maxHeight) {
                maxHeight = height;
            }
        }
        
        /* make a new array and set the size equal to the max number plus 1 (saves some space)
            and fill it with zeros */
        vector<int> countOfHeights(maxHeight + 1, 0);

        // counts the freq of heights that show up
        for (int height: heights) {
            countOfHeights[height]++;
        }

        // creates the sorted array from the count of heights
        for (int i = 0; i < countOfHeights.size(); i++) {
            if (countOfHeights[i] > 0) {
                sortedHeights[sortedPosition] = i;
                sortedPosition++;
                countOfHeights[i]--;
                if (countOfHeights[i] > 0) {
                    i--;
                }
            }
        }
        
        // compares the sorted array with the original to find discrepencies
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sortedHeights[i]) {
                countMismatches++;
            }
        }

        return countMismatches;
    };
};

int main() {
    vector<int> v = {1,1,3,4,2,1,4};
    // 2,2,3,4,1,4,2    1,2,2,2,3,4,4   5
    // 4,1,2,3,4,1,1    1,1,1,2,3,4,4   6
    // 1,1,3,4,2,1,4    1,1,1,2,3,4,4   4
    int res;

    Solution sol;

    res = sol.heightChecker2(v);

    std::cout << res;

    return 0;
}

/**
    Input: heights = [1,1,4,2,1,3]
    Output: 3
    Explanation: 
    heights:  [1,1,4,2,1,3]
    expected: [1,1,1,2,3,4]
    Indices 2, 4, and 5 do not match.

    Input: heights = [2,2,4,5,1,3]
    Output: 6
    Explanation: 
    heights:  [2,2,4,5,1,3]
    expected: [1,1,2,3,4,5]
    All Indices do not match.
*/