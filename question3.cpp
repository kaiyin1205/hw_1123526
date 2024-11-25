//Name: Kelly Huang
//Student ID: 1123526
//Date of submission: 2024/11/26

#include <iostream>
#include <vector>
#include <queue>
#include <sstream> // For string stream to handle line input
using namespace std;

// Define a structure to hold array elements along with their array and index positions
struct Element {
    int value;   // The value of the element
    int arrIdx;  // The index of the array it belongs to
    int elemIdx; // The index of the element within the array

    // Comparator to ensure min-heap behavior
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

int main() {
    int K; // Number of sorted arrays
    cin >> K;
    cin.ignore(); // To handle the newline after K

    vector<vector<int>> arrays(K);
    string line;

    // Read K lines of sorted arrays
    for (int i = 0; i < K; ++i) {
        getline(cin, line); // Read a full line
        stringstream ss(line); // Use stringstream to parse the line
        int num;
        while (ss >> num) {
            arrays[i].push_back(num);
        }
    }

    // Min priority queue (min-heap)
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Insert the first element of each array into the heap
    for (int i = 0; i < K; ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    vector<int> mergedArray; // The result array

    // Process the min-heap until all elements are merged
    while (!minHeap.empty()) {
        // Extract the smallest element
        Element current = minHeap.top();
        minHeap.pop();

        // Add the smallest element to the result array
        mergedArray.push_back(current.value);

        // If the extracted element has a next element in its array, push it into the heap
        if (current.elemIdx + 1 < arrays[current.arrIdx].size()) {
            minHeap.push({arrays[current.arrIdx][current.elemIdx + 1], current.arrIdx, current.elemIdx + 1});
        }
    }

    // Output the merged sorted array
    cout << "Merged Array: [";
    for (size_t i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i];
        if (i != mergedArray.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
