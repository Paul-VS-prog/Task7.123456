#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int n = 5;
void t1() {
    int k = 1;
    int a[n];
    cout << "Vvedite elementa massiva(zadanie 1b): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            k++;
        }
    }
    cout << k;
}
void t2() {
    int k = 0, m = 0;
    int n;
    cout << "Vvedite dlinu massiva: ";
    cin >> n;
    int *a;
    a = (int*) malloc(n * sizeof(int));
    cout << "Vvedite elementa massiva: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0;
    while (i < n) {
        if (a[i] % 2 != 0) {
            int j = i;
            k = 0;
            while (a[j] % 2 != 0 && j < n) {
                k++;
                j++;
            }
            if (k > m) {
                m = k;
            }
            i = j + 1;
        }
    }
    cout << m;
}
void t3() {
    int n;
    cout << "Vvedite dlinu massiva: ";
    cin >> n;
    int f = n;
    int *a;
    a = (int*) malloc(n * sizeof(int));
    cout << "Vvedite elementa massiva: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
              for (int k = j; k < n ; k++) {
                 a[k] = a[k + 1];
              }
              a[n - 1] = 0;
              j--;
              n--;
            }
        }
    }
    for (int i = 0; i < f; i++) {
        cout << a[i] << " ";
    }
}
void t4() {
    int n;
    cout << "Vvedite dlinu massiva: ";
    cin >> n;
    int *a;
    a = (int*) malloc(n * sizeof(int));
    cout << "Vvedite elementa massiva: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k = 0, m = a[0], m2 = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > m) {
            m2 = m;
            m = a[i];
        }
        else {
            if (a[i] > m2) {
                m2 = a[i];
            }
        }
    }
    cout << m2;
}
int ind(int a[n], int k, int l, int r) {
    int m = (l + r) / 2;
    if (a[m] == k) {
        return m;
    }
    if (a[m] > k) {
        ind(a, k, l, m - 1);
    }
    else {
        ind(a, k, m + 1, r);
    }
    }
void t5() {
    int n;
    cout << "Vvedite dlinu massiva: ";
    cin >> n;
    int *a;
    a = (int*) malloc(n * sizeof(int));
    cout << "Vvedite elementa massiva: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cout << "Vvedite element, kotorai nuzno naiti: ";
    cin >> k;
    int l = 0, r = n - 1;
    cout << "Nomer elementa: " << ind(a, k, l, r) + 1; // элементы считаются с 1;
}
const int o = 7;
const int p = 7;
void end(int a[o], int b[p], int r[p + o]) {

        int i = 0, j = 0;
        int ind = 0;
        while (i < o && j < p) {
            if (a[i] < b[j]) {
                r[ind] = a[i];
                i++;
            }
            else {
                r[ind] = b[j];
                j++;
            }
            ind++;
        }
        while (i < o) {
            r[ind] = a[i];
            ind++;
            i++;
        }
        while (j < p) {
            r[ind] = b[j];
            ind++;
            j++;
        }

}
void t6() {
    int a[o];
    cout << "Vvedite elementa 1 massiva: ";
    for (int i = 0; i < o; i++) cin >> a[i];
    int b[p];
    cout << "Vvedite elementa 2 massiva: ";
    for (int i = 0; i < p; i++) cin >> b[i];
    int *r;
    r = (int*) malloc((p + o) * sizeof(int));
    // массивы а и b - упорядоченны по неубыванию, полученный массив r тоже
    end(a, b, r);
    for (int k = 0; k < o + p; k++) {
        cout << r[k] << ' ';
    }
}
int main() {
    int n = 1;
    while (n) {
        cout << endl << "Vvedite nomer zadachi: ";
        cin >> n;
        if (n == 1) t1();
        if (n == 2) t2();
        if (n == 3) t3();
        if (n == 4) t4();
        if (n == 5) t5();
        if (n == 6) t6();
    }
    return 0;
}
