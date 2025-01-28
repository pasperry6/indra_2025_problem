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

        // iterate through file
        while (file.get(ch)) {
            fourg = fourg + ch; //add new char to create four gram

            // to handle the beginning of files
            if (fourg.length() < 4) {
                continue;
            }

            mapping(fourg); // going through each one, two, three, four grams in the four gram

            // to handle end of files
            if (file.peek() == EOF) {
                // handle the threeg, twog, and oneg
                fourg.erase(0,1);
                mapping(fourg);
                fourg.erase(0,1);
                mapping(fourg);
                fourg.erase(0,1);
                mapping(fourg);
                break; //done with file
            }

            fourg.erase(0, 1); //delete first char (to make room for new char)
        }

        // write to output file
        write_output();
    }

    void write_output(void) {
        ofstream file("output.txt");

        // Write map content to the file
        for (std::unordered_map<std::string, int>::iterator it = map.begin(); it != map.end(); ++it) {
            file << it->first << " : " << it->second << std::endl;
        }

        file.close();
    }

    void mapping(string gram) {
        int size = gram.length();
        for (int i = 0; i < size; i++) {
            if (map.find(gram) == map.end()) {
                map[gram] = 1;
            }
            else {
                map[gram] = map[gram] + 1;
            }
            gram.pop_back();
        }
    }

};

int main(int args, char** kwargs) {
    solver sol;
    sol.filename = kwargs[1];
    sol.main_solver();
    return 0;
}
