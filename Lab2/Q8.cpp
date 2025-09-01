#include <iostream>
using namespace std;

int main() {
    int n, m;
    
    cout << "Enter number of days to track: ";
    cin >> n;
    cout << "Enter no of readings per day: ";
    cin >> m;
    
    if (n <= 0 || m <= 0) {
        cout << "Invalid input." << endl;
        return 1;
    }
    double** temperatures = new double*[n];
    for (int i = 0; i < n; i++) {
        temperatures[i] = new double[m];
    }
    cout << "\nEnter temperature readings:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nDay " << (i + 1) << ":\n";
        for (int j = 0; j < m; j++) {
            cout << "Reading " << (j + 1) << ": ";
            cin >> temperatures[i][j];
        }
    }
    double* dailyAverages = new double[n];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum += temperatures[i][j];
        }
        dailyAverages[i] = sum / m;
    }
    cout << "Daily average temperatures\n";
    cout << string(50, '=') << "\n";
    for (int i = 0; i < n; i++) {
        cout << "Day " << (i + 1) << ": " << dailyAverages[i] << "°C" << endl;
    }
    int hottestDay = 0;
    int coldestDay = 0;
    double maxTemp = dailyAverages[0];
    double minTemp = dailyAverages[0];
    
    for (int i = 1; i < n; i++) {
        if (dailyAverages[i] > maxTemp) {
            maxTemp = dailyAverages[i];
            hottestDay = i;
        }
        if (dailyAverages[i] < minTemp) {
            minTemp = dailyAverages[i];
            coldestDay = i;
        }
    }
    cout << "Hottest day: Day " << (hottestDay + 1) << " (" << maxTemp << " C)" << endl;
    cout << "Coldest day: Day " << (coldestDay + 1) << " (" << minTemp << " C)" << endl;

    for (int i = 0; i < n; i++) {
        delete[] temperatures[i];
    }
    delete[] temperatures;
    delete[] dailyAverages;
    
    return 0;
}
