#ifndef MANUSIA_H
#define MANUSIA_H

class Manusia {
public:
    string name;
    Jantung varJantung;

    Manusia(string pName) : name(pName) {
        cout << name << "Hidup\n";
    }
    ~Manusia() {
        cout << name << "Mati\n";
    }
};
#endif