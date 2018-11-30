#include <iostream>
using namespace std;


template <typename T>
    void sort (T a[], int size){
        for (int j=0; j<size-1; j++){
            for (int i=0; i< size-1; i++){
                if (a[i]>a[i+1]){
                    swap(a[i],a[i+1]);
            }
        }
    }
}

template <typename T>
    void print(T a[], int n){
        for (int i=0; i<n; i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }

template <typename T>
    T sum(T a[], int n){
        T s=0;
        for (int i=0; i<n; i++){
            s=s+a[i];
        }
        return s;
    }

int main() {
    int a[] = {5, 4, 3, 1, 7, 8, 9, 2, 1};
    sort(a, sizeof(a)/sizeof(int));
    print(a, sizeof(a)/sizeof(int));

    double b[] = {5.5, 4.5, 1.2, 2.9, 9.2, 5.2};
    sort(b, sizeof(b)/sizeof(double));
    print(b, sizeof(b)/sizeof(double));

    cout << sum(a, sizeof(a)/sizeof(int)) << '\n';
    cout << sum(b, sizeof(b)/sizeof(double)) << '\n';

    string c[] = {"yo", "ho", "test", "foo", "bar"};
    sort(c, sizeof(c)/sizeof(string));
    print(c, sizeof(c)/sizeof(string));
    //TODO?	cout << sum(c, sizeof(c)/sizeof(string)) << '\n';
}