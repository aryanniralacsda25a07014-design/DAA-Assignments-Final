#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

// Sort activities according to finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(Activity activities[], int n) {

    // Sort by finish time
    sort(activities, activities + n, compare);

    cout << "Selected Activities:\n";

    // Select the first activity
    int lastFinish = activities[0].finish;
    cout << "(" << activities[0].start << ", "
         << activities[0].finish << ")\n";

    // Select remaining activities
    for (int i = 1; i < n; i++) {

        // Activity can be selected if it starts
        // after or exactly when previous activity finishes
        if (activities[i].start >= lastFinish) {
            cout << "(" << activities[i].start << ", "
                 << activities[i].finish << ")\n";

            lastFinish = activities[i].finish;
        }
    }
}

int main() {

    Activity activities[] = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}