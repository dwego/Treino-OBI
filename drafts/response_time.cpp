#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string texto, char separador) {
    vector<string> partes;
    string item;
    stringstream ss(texto);

    while (getline(ss, item, separador)) {
        partes.push_back(item);
    }

    return partes;
}

int time_to_response(int x, vector<string> msgs) {
    int time_added = 0;
    
    for (string msg : msgs) {

    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    vector<string> msgs;

    for (int i = 0; i <= N; i++) {
        string x;
        cin >> x;
        msgs.push_back(x);
    }



    return 0;
}