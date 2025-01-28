#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class solver {
public:
    string filename;

    void main_solver(void) {
        ifstream file(filename);
        char ch;
        string fourg;

        while (file.get(ch)) {
            fourg = fourg + ch; //add new char to create four gram

            // to handle the beginning of files
            if (fourg.length() < 4) {
                continue;
            }

            // to handle end of files
            char one_ahead = file.peek();
            if (one_ahead == EOF) {
                // handle the threeg, twog, and oneg
                cout<<fourg<<endl;
                fourg.erase(0, 1);
                cout<<fourg<<endl;
                fourg.erase(0, 1);
                cout<<fourg<<endl;
                fourg.erase(0, 1);
                cout<<fourg<<endl;
                break; //done with file
            }

            cout << fourg << endl;
            fourg.erase(0, 1);
        }
    }

};

int main(int args, char** kwargs) {
    solver sol;
    sol.filename = kwargs[1];
    sol.main_solver();
    return 0;
}
