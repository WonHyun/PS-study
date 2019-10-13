#if 0

// ip addr 정규표현식

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main() {
    regex ip_addr("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-5][0-5]).){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-5][0-5])");
    vector<string> addr = {"0.0.0.0", "127.0.0.1", "255.255.225.256" , "123", "1.01.10.4", "255.255.255.255", "이것은 주소인가"};
    vector<string> valid;
    vector<string> invalid;

    for (int i = 0; i < addr.size(); i++) {
        if (regex_match(addr[i], ip_addr)) {
            valid.push_back(addr[i]);
        }
        else {
            invalid.push_back(addr[i]);
        }
    }

    cout << "valid addr : ";
    for (int i = 0; i < valid.size(); i++) {
        cout << valid[i] << " ";
    }
    cout << endl;

    cout << "invalid addr : ";
    for (int i = 0; i < invalid.size(); i++) {
        cout << invalid[i] << " ";
    }
    cout << endl;

    return 0;
}

#endif
