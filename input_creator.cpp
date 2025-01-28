#include <iostream>
#include <string>
#include <fstream>
#include <random>

using namespace std;

class creator {
public:
    string filename;
    int num;

    void create(void) {
        // Create a random device and generator
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> dist('a', 'z'); 

        // write to file
        ofstream file(filename);
        for (int i = 0; i < num; i++) {
            char randomLetter = static_cast<char>(dist(gen));
            file << randomLetter;
        }
        file.close();
    }
};

int main(int args, char** kwargs) {
    creator crea;
    crea.filename = kwargs[1];
    crea.num = stoi(kwargs[2]);
    crea.create();
    return 0;
}