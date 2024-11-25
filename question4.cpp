//Name: Kelly Huang
//Student ID: 1123526
//Date of submission: 2024/11/26

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a task
struct Task {
    int profit;   // The profit for completing this task
    int deadline; // The latest time this task can be completed
};

// Comparator function to sort tasks by profit in descending order
bool compareTasks(const Task& a, const Task& b) {
    return a.profit > b.profit;
}

int main() {
    int N; // Number of tasks
    cin >> N;

    vector<Task> tasks(N);
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].profit >> tasks[i].deadline;
    }

    // Sort tasks by profit in descending order
    sort(tasks.begin(), tasks.end(), compareTasks);

    // Find the maximum deadline among all tasks
    // This determines the number of available time slots
    int maxDeadline = 0;
    for (const auto& task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    // Create a schedule array where each index represents a time slot
    // Initialize all slots as -1, indicating they are initially free
    vector<int> schedule(maxDeadline + 1, -1);
    int maxProfit = 0;          // Total profit accumulated by scheduled tasks
    vector<int> scheduledTasks; // Keeps track of profits of scheduled tasks

    // Schedule tasks to maximize profit
    for (const auto& task : tasks) {
        // Try to schedule this task in the latest available slot
        // starting from its deadline and moving backward
        for (int slot = task.deadline; slot > 0; --slot) {
            if (schedule[slot] == -1) { // If the slot is free
                schedule[slot] = task.profit; // Schedule this task
                maxProfit += task.profit;     // Add its profit to total
                scheduledTasks.push_back(task.profit); // Record the profit
                break; // Task is scheduled, move to the next task
            }
        }
    }

    // Output the total profit
    cout << "Maximum Profit: " << maxProfit << endl;

    // Output the scheduled tasks in the order they were added
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < scheduledTasks.size(); ++i) {
        cout << scheduledTasks[i];
        if (i != scheduledTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
