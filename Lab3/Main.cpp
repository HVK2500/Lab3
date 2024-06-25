#include "SortingFunction.h"
#include "DataGenerator.h"

using namespace std;
int main(int argc, char* argv[])
{
    if (argc == 5) {
        string algo1 = argv[2];
        string algo2 = argv[3];
        string filename = argv[4];
        command4(algo1, algo2, filename);
    }
    else if (argc == 6) {
        string algo1 = argv[2];
        string algo2 = argv[3];
        string size = argv[4];
        int input_size = atoi(size.c_str());
        string input_order = argv[5];
        command5(algo1, algo2, input_size, input_order);
    }
    
    /*char filename[] = "input.txt";
    fstream fin(filename, ios::in);
    int n;
    fin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int num{};
        fin >> num;
        v[i] = num;
    }
    fin.close();
    string sort_algo = "insertion-sort";
    int sort_type = choose_sort(sort_algo);
    auto duration = sort_count(v, sort_type);
    cout << duration.count() << "ms, " << count_compare << endl;*/
    ////Generate ones list
    //cout << "Please input size: ";
    //int n; cin >> n;
    //vector<int> v(n);
    //int datatype;
    //cout << "0.Generate a random data.\n";
    //cout << "1.Generate a sorted data.\n";
    //cout << "2.Generate a reverse data.\n";
    //cout << "3.Generate a nearly sorted data.\n";
    //cout << "Input choice: "; cin >> datatype;
    //GenerateData(v, n, datatype);
    ////PrintList(v);

    ////Check if sorting is true

    //vector<int> temp1(v.begin(), v.end());
    //vector<int> temp2(v.begin(), v.end());
    //sort(temp1.begin(), temp1.end());
    ////selection_sort(temp2);
    ////exchange_sort(temp2);
    ////buble_sort(temp2);
    //insertion_sort(temp2, n);
    ////merge_sort(temp2, 0, n - 1);
    ////heap_sort(temp2);
    ////quick_sort(temp2, 0, n - 1);
    ////temp2 = counting_sort(v, get_max(v));
    ////radix_sort(temp2);
    ////bucket_sort(temp2);
    ////shaker_sort(temp2);
    ////shell_sort(temp2);
    ////flash_sort(temp2);
    ////binary_insertion_sort(temp2);
    //bool check = true;
    //for (int i = 0; i < n; i++) {
    //    if (temp1[i] != temp2[i]) check = false;
    //}
    //if (check) cout << "True" << endl;
    //else cout << "False" << endl;

    /////////////////////////////////////////////////////////////////////////////////
    //// Count time
    //auto start = std::chrono::high_resolution_clock::now();

    ////selection_sort(v);
    ////exchange_sort(v);
    ////buble_sort(v);
    //insertion_sort(v, n);
    ////merge_sort(v, 0, n - 1);
    ////heap_sort(v);
    ////quick_sort(v, 0, n - 1);
    ////v = counting_sort(v, get_max(v));
    ////radix_sort(v);
    ////bucket_sort(v);
    ////shaker_sort(v);
    ////shell_sort(v);
    ////flash_sort(v);
    ////binary_insertion_sort(v);
    ////PrintList(v);
    //auto stop = std::chrono::high_resolution_clock::now();
    //auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    //cout << "Time taken by funciton: " << duration.count() << " milliseconds" << endl;

    return 0;
}