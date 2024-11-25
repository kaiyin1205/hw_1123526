//Name: Kelly Huang
//Student ID: 1123526
//Date of submission: 2024/11/26

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

// Custom comparator for max-heap
struct Task {
    string name;
    int priority;

    bool operator<(const Task& other) const {
        return priority < other.priority; // For max-heap, higher priority comes first
    }
};

int main() {
    int N;
    cin >> N;

    priority_queue<Task> taskQueue;
    vector<pair<string, int>> remainingTasks;

    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string taskName;
            int priority;
            cin >> taskName >> priority;
            taskQueue.push({taskName, priority});
        } else if (command == "GET") {
            if (!taskQueue.empty()) {
                Task topTask = taskQueue.top();
                cout << topTask.name << endl; // Print the task with the highest priority
                taskQueue.pop();
            } else {
                cout << "No tasks available" << endl;
            }
        }
    }

    // Collect remaining tasks
    while (!taskQueue.empty()) {
        Task topTask = taskQueue.top();
        remainingTasks.emplace_back(topTask.name, topTask.priority);
        taskQueue.pop();
    }

    // Print remaining tasks in descending order of priority
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].first << "', " << remainingTasks[i].second << ")";
        if (i != remainingTasks.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
