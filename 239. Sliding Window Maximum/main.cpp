#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

// Function to find maximum values in a sliding window of size 'windowSize'
// This function works in O(nw) where n is the size of array and w is the 
// size of window.
std::vector<int> findMaxInWindow1(int *n, int size, int windowSize) {
    std::vector<int> retVector(size - windowSize + 1, 0);

    for (int i = 0; i < (size - windowSize + 1); i++) {
        int highest = -101; // Assuming -100 to be the least possible number here
        for (int j = 0; j < windowSize; j++) {
            if (highest < n[i + j]) {
                highest = n[i + j];
            }
            retVector[i] = highest;
        }
    }
    return retVector;
}

// Function to reset the sliding window based on input and output buffers
std::vector<int> resetWindow(std::vector<int>& window, std::vector<int>& inputBuffer, std::vector<int>& outputBuffer) {
    std::vector<int> retVec;
    int i = 0;
    int j = 0;

    while (true) {
        if (i >= window.size() && j < outputBuffer.size()) {
            for (int p = j; p < outputBuffer.size(); p++) {
                retVec.push_back(outputBuffer[p]);
            }
            break;
        } else if (i < window.size() && j >= outputBuffer.size()) {
            for (int p = i; p < window.size(); p++) {
                retVec.push_back(window[p]);
            }
            break;
        } else if (i >= window.size() && j >= outputBuffer.size()) {
            break;
        } else if (window[i] == outputBuffer[j]) {
            window[i] = inputBuffer.back();
            inputBuffer.pop_back();
            j++;
        }
        retVec.push_back(window[i]);
        i++;
    }
    return retVec;
}

// Function to find maximum values in a sliding window of size 'windowSize'
std::vector<int> maxSlidingWindow2(std::vector<int>& nums, int windowSize) {
    std::vector<int> retVec;
    std::vector<int> sortedWindow;
    std::vector<int> inputBuffer;
    std::vector<int> outputBuffer;

    sortedWindow.assign(nums.begin(), nums.begin() + windowSize);
    std::sort(sortedWindow.begin(), sortedWindow.end());
    retVec.push_back(sortedWindow.back());

    for (int i = windowSize; i < nums.size(); i++) {
        inputBuffer.push_back(nums[i]);
        outputBuffer.push_back(nums[i - windowSize]);

        if (nums[i] > sortedWindow.back() || nums[i - windowSize] >= sortedWindow.back()) {
            std::sort(outputBuffer.begin(), outputBuffer.end());
            sortedWindow = resetWindow(sortedWindow, inputBuffer, outputBuffer);
            std::sort(sortedWindow.begin(), sortedWindow.end());
            inputBuffer.clear();
            outputBuffer.clear();
        }
        retVec.push_back(sortedWindow.back());
    }

    return retVec;
}

// Function to find maximum values in a sliding window of size 'windowSize'
// Works in O(n) time 
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int windowSize) {
    std::vector<int> retVec(nums.size() - windowSize + 1, 0);
    std::deque<int> sortedWindowQ;

    sortedWindowQ.push_back(nums[0]);

    for (int i = 1; i < windowSize; i++) {
        if (nums[i] <= sortedWindowQ.back()) {
            sortedWindowQ.push_back(nums[i]);
        } else {
            while (true) {
                if (sortedWindowQ.empty()) {
                    sortedWindowQ.push_back(nums[i]);
                    break;
                } else {
                    if (nums[i] > sortedWindowQ.back()) {
                        sortedWindowQ.pop_back();
                    } else {
                        sortedWindowQ.push_back(nums[i]);
                        break;
                    }
                }
            }
        }
    }
    int p = 0;
    retVec[p] = sortedWindowQ.front();
    p++;

    for (int i = windowSize; i < nums.size(); i++) {
        while (true) {
            if (sortedWindowQ.empty()) {
                sortedWindowQ.push_back(nums[i]);
                break;
            } else {
                if (nums[i] > sortedWindowQ.back()) {
                    sortedWindowQ.pop_back();
                } else {
                    sortedWindowQ.push_back(nums[i]);
                    break;
                }
            }
        }
        if (nums[i - windowSize] == sortedWindowQ.front()) {
            sortedWindowQ.pop_front();
        }
        retVec[p] = sortedWindowQ.front();
        p++;
    }
    return retVec;
}

int main() {
    std::vector<int> arg = {-6,-10,-7,-1,-9,9,-8,-4,10,-5,2,9,0,-7,7,4,-2,-10,8,7};
    std::vector<int> max = maxSlidingWindow(arg, 7);

    std::cout << "{ ";
    for (int val: max) {
        std::cout << val << ", ";
    }
    std::cout << " }";
    return 0;
}
