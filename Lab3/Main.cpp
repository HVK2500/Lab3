#include "SortingFunction.h"
#include "DataGenerator.h"

using namespace std;
int main(int argc, char* argv[])
{
    sort_all();
    /*if (argc > 4) {
        string mode = argv[1];
        if (mode == "-a") {
            if (argc == 5) {
                if (isalpha(argv[3][0])) command1(argv[2], argv[3], argv[4]);
                else command3(argv[2], argv[3], argv[4]);
            }
            else if (argc == 6) command2(argv[2], argv[3], argv[4], argv[5]);
            else cout << "Cannot run!!\n";
        }
        else if (mode == "-c") {
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
            else cout << "Cannot run!!\n";
        }
        else cout << "Cannot run!!\n";
    }*/
    
    
    return 0;
}