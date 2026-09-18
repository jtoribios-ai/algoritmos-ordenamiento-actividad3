#include <iostream>
#include <vector>

using namespace std;

struct Metric {
    int comparaciones = 0;
    int intercambios = 0;
};

Metric bubbleSortBase(vector<int> arr) {
    Metric m;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            m.comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.intercambios++;
            }
        }
    }
    return m;
}

Metric bubbleSortMejorado(vector<int> arr) {
    Metric m;
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            m.comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.intercambios++;
                swapped = true;
            }
        }
        if (!swapped) break; 
    return m;
}

Metric selectionSort(vector<int> arr) {
    Metric m;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            m.comparaciones++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            m.intercambios++;
        }
    }
    return m;
}

void probarCaso(const string& nombreCaso, const vector<int>& arr) {
    Metric mBase = bubbleSortBase(arr);
    Metric mMejorado = bubbleSortMejorado(arr);
    Metric mSelection = selectionSort(arr);

    cout << "--- " << nombreCaso << " ---" << endl;
    cout << "Bubble Base     -> Comp: " << mBase.comparaciones << " | Inter: " << mBase.intercambios << endl;
    cout << "Bubble Mejorado -> Comp: " << mMejorado.comparaciones << " | Inter: " << mMejorado.intercambios << endl;
    cout << "Selection Sort  -> Comp: " << mSelection.comparaciones << " | Inter: " << mSelection.intercambios << endl << endl;
}

int main() {
    probarCaso("Caso 1: [5, 3, 8, 2]", {5, 3, 8, 2});
    probarCaso("Caso 2: [1, 2, 3, 4, 5]", {1, 2, 3, 4, 5});
    probarCaso("Caso 3: [5, 4, 3, 2, 1]", {5, 4, 3, 2, 1});
    return 0;
}
