#include <iostream>
#include <string>

using namespace std;;

int contaCaracteres(string str, int n, char c)
{
    if(n == 1) {

        if(str[n - 1] == c) { 
            return 1;
        }else { 
            return 0;
        }
    }else {
        if(str[n - 1] == c) {
            return contaCaracteres(str, n - 1, c) + 1;
        }else {
            return contaCaracteres(str, n - 1, c);
        }
    }
}

int main() 
{
    string str;
    char c;

    getline(cin, str);
    cin.get(c);

    cout << contaCaracteres(str, (int) str.length(), c);
}