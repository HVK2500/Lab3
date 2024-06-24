#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <cmath>
#include <string>
#include <random>
using namespace std;
void selection_sort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int min_num = v[i];
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < min_num) {
                min_num = v[j];
                idx = j;
            }
        }
        swap(v[i], v[idx]);
    }
}
void exchange_sort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[i]) {
                swap(v[i], v[j]);
            }
        }
    }
}
void buble_sort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (v[j] < v[j - 1]) swap(v[j], v[j - 1]);
        }
    }
}
void shaker_sort(vector<int>& v) {
    int n = v.size();
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }
    }
}
void insertion_sort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void merge(vector<int>& arr, int p, int q, int r) {
    int nL = q - p + 1;
    int nR = r - q;
    int* L = new int[nL];
    int* R = new int[nR];
    for (int i = 0; i < nL; i++) {
        L[i] = arr[p + i];
    }
    for (int i = 0; i < nR; i++) {
        R[i] = arr[q + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = p;
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < nL) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < nR) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}
void merge_sort(vector<int>& arr, int p, int r) {
    if (p >= r) return;
    int q = (p + r) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q + 1, r);
    merge(arr, p, q, r);
}
void max_heapify(vector<int>& v, int i, int heap_size) {
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int largest;
    if (l < heap_size && v[l] > v[i]) {
        largest = l;
    }
    else largest = i;
    if (r < heap_size && v[r] > v[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(v[i], v[largest]);
        max_heapify(v, largest, heap_size);
    }
}
// Heap sort and priority queue 
void iterative_max_heapify(vector<int>& v, int i, int heap_size) {
    while (i < heap_size) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int largest;
        if (l < heap_size && v[l] > v[i]) {
            largest = l;
        }
        else largest = i;
        if (r < heap_size && v[r] > v[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(v[i], v[largest]);
            i = largest;
        }
        else break;
    }
}
void heap_sort(vector<int>& v) {
    int heap_size = v.size();
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        iterative_max_heapify(v, i, heap_size);
    }
    for (int i = heap_size - 1; i > 0; i--) {
        swap(v[0], v[i]);
        heap_size--;
        iterative_max_heapify(v, 0, heap_size);
    }
}
// Quick sort
int partition(vector<int>& v, int p, int r) {
    /*default_random_engine engine;
    uniform_int_distribution<int> distribution(p, r);
    swap(v[r], v[distribution(engine)]);*/
    int mid = p + (r - p) / 2;
    if (v[mid] < v[p]) swap(v[mid], v[p]);
    if (v[mid] > v[r]) swap(v[mid], v[r]);
    swap(v[mid], v[r]);
    int key = v[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (v[j] < key) {
            i++;
            swap(v[j], v[i]);
        }
    }
    swap(v[r], v[i + 1]);
    return i + 1;
}
void quick_sort(vector<int>& v, int p, int r) {
    if (p < r) {
        int q = partition(v, p, r);
        quick_sort(v, p, q - 1);
        quick_sort(v, q + 1, r);
    }
}
int get_max(vector<int> v) {
    int m = INT_MIN;
    for (auto i : v) {
        m = max(i, m);
    }
    return m;
}
vector<int> counting_sort(vector<int> v, int k) {
    int n = v.size();
    vector<int> ans(n);
    vector<int> c(k + 1, 0);
    for (int i = 0; i < n; i++) {
        c[v[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        c[i] += c[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        ans[c[v[i]] - 1] = v[i];
        c[v[i]]--;
    }
    return ans;
}
void radix_sort(vector<int>& v) {
    int max_num = *max_element(v.begin(), v.end());

    int n = v.size();
    for (int i = 1; max_num / i > 0; i *= 10) {
        //Counting sort
        vector<int> a(n, 0);
        vector<int> c(10, 0);
        for (int j = 0; j < n; j++) {
            c[(v[j] / i) % 10]++;
        }
        for (int j = 1; j < 10; j++) {
            c[j] += c[j - 1];
        }
        for (int j = n - 1; j >= 0; j--) {
            a[c[(v[j] / i) % 10] - 1] = v[j];
            c[(v[j] / i) % 10]--;
        }
        for (int j = 0; j < n; j++) {
            v[j] = a[j];
        }
    }
}
void shell_sort(vector<int>& v) {
    int n = v.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = v[i];
            int j = i - gap;
            while (j >= 0 && v[j] > key) {
                v[j + gap] = v[j];
                j -= gap;
            }
            v[j + gap] = key;
        }
    }
}

void bucket_sort(vector<int>& v) {
    int n = v.size();
    vector<vector<int>> b(n);
    double max_num = (double)(*max_element(v.begin(), v.end())) + 1.0;
    // Cast to [0, 1)
    for (int i = 0; i < n; i++) {
        b[(int)((double)v[i] / max_num * n)].push_back(v[i]);
    }
    for (int i = 0; i < n; i++) {
        int m = b[i].size();
        // Insertion sort
        for (int j = 1; j < m; j++) {
            int key = b[i][j];
            int k = j - 1;
            while (k >= 0 && b[i][k] > key) {
                b[i][k + 1] = b[i][k];
                k--;
            }
            b[i][k + 1] = key;
        }
    }
    int idx = 0;
    for (int i = 0; i < n; i++) {
        int m = b[i].size();
        for (int j = 0; j < m; j++) {
            v[idx] = b[i][j];
            idx++;
        }
    }
}
int main()
{
    cout << "Please input size: ";
    int n; cin >> n;

    // Random vector
    vector<int> v(n);
    /*srand(time(NULL));
    auto f = []() -> int { return rand() % 10000; };*/
    random_device rnd_device;
    mt19937 mersenne_engine{ rnd_device() };
    uniform_int_distribution<int> distribution(0, n);
    auto f = [&distribution, &mersenne_engine]() {return distribution(mersenne_engine); };
    generate(v.begin(), v.end(), f);




    //Check if sorting is true

    vector<int> temp1(v.begin(), v.end());
    vector<int> temp2(v.begin(), v.end());
    sort(temp1.begin(), temp1.end());
    //selection_sort(temp2);
    //exchange_sort(temp2);
    //buble_sort(temp2);
    //insertion_sort(temp2, n);
    //merge_sort(temp2, 0, n - 1);
    //heap_sort(temp2);
    //quick_sort(temp2, 0, n - 1);
    //temp2 = counting_sort(v, get_max(v));
    //radix_sort(temp2);
    //bucket_sort(temp2);
    //shaker_sort(temp2);
    shell_sort(temp2);
    bool check = true;
    for (int i = 0; i < n; i++) {
        if (temp1[i] != temp2[i]) check = false;
    }
    if (check) cout << "True" << endl;
    else cout << "False" << endl;

    ///////////////////////////////////////////////////////////////////////////////
    // Count time
    auto start = std::chrono::high_resolution_clock::now();

    //selection_sort(v);
    //exchange_sort(v);
    //buble_sort(v);
    //insertion_sort(v, n);
    //merge_sort(v, 0, n - 1);
    //heap_sort(v);
    //quick_sort(v, 0, n - 1);
    //v = counting_sort(v, get_max(v));
    //radix_sort(v);
    //bucket_sort(v);
    //shaker_sort(v);
    shell_sort(v);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "Time taken by funciton: " << duration.count() << " milliseconds" << endl;

    return 0;
}

