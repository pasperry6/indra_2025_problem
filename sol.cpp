#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

class solver {
public:
    string filename;
    unordered_map<string, int> map;

    void main_solver(void) {
        ifstream file(filename);
        char ch;
        string fourg;

        while (file.get(ch)) { // iterate through file, char by char
            fourg = fourg + ch; // add new char to create four gram

            if (fourg.length() > 4) fourg.erase(0,1); // keep fourg to <= 4 chars

            add_to_map(fourg); // mapping each one, two, three, four grams in the four gram
        }
        write_output(); // write to output file
    }

    void add_to_map(string gram) {
        int size = gram.length();
        for (int i = 0; i < size; i++) {
            map[gram]++;
            gram.erase(0,1);
        }
    }

    void write_output(void) {
        ofstream file("output.txt");
        for (auto it = map.begin(); it != map.end(); it++) { // iterate through map, without order
            file << it->first << " : " << it->second << endl;
        }
        file.close();
    }
};

int main(int args, char** kwargs) {
    solver sol;
    sol.filename = kwargs[1];
    sol.main_solver();
    return 0;
}