#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    User(string nama, string email) {
        this->id = generateId();
        this->nama = nama;
        this->email = email;
    }

    virtual ~User() {}

    int generateId() {
        return ++globalId;
    }

    int getId() const { return id; }
    string getNama() const { return nama; }
};

int User::globalId = 0;

class Member : public User {
private:
    bool status;

public:
    Member(string nama, string email, bool status)
        : User(nama, email), status(status) {}

    void setStatus(bool newStatus) {
        this->status = newStatus;
    }

    bool getStatus() const {
        return status;
    }

    void showProfile() const {
        cout << "ID      : " << id << endl;
        cout << "Nama    : " << nama << endl;
        cout << "Email   : " << email << endl;
        cout << "Status  : " << (status ? "Aktif" : "Nonaktif") << endl;
        cout << "------------------------" << endl;
    }
};

class Admin : public User {
public:
    Admin(string nama, string email) : User(nama, email) {}

    void showAllMember(const vector<Member> &members) const {
        for (const auto &m : members) {
            m.showProfile();
        }
    }

    void toggleActivationMember(Member &member) {
        member.setStatus(!member.getStatus());
        cout << "[System] Status Member ID " << member.getId() << " berhasil diubah." << endl;
    }
};

int main() {
    vector<Member> members;
    members.emplace_back("Rayhan", "rayhan@gmail.com", true);
    members.emplace_back("Budi", "budi@gmail.com", false);

    Admin admin("SuperAdmin", "admin@web.com");

    cout << "=== DAFTAR MEMBER AWAL ===" << endl;
    admin.showAllMember(members);

    admin.toggleActivationMember(members[1]); // Mengaktifkan Budi

    cout << "\n=== DAFTAR MEMBER SETELAH UPDATE ===" << endl;
    admin.showAllMember(members);

    return 0;
}