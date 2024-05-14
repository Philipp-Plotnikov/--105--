#include <iostream>

using namespace std;

int* eratosthen(int n) {
    int* sieve = new int[n+1]{0};
    for (int x = 2; x <= n; x++) {
        if (sieve[x]) continue;
        for (int u = 2*x; u <= n; u+=x) {
            sieve[u] = 1;
        }
    }
    return sieve;
}

int main() {
    int n = 0;
    cin >> n;
    int* sieve = eratosthen(n);
    for (int i = 2; i < n + 1; i++) {
        if (!sieve[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}