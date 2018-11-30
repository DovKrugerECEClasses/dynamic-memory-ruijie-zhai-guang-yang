#include <iostream>
using namespace std;

template <typename T>
void sort(T x[], const int& n){
    for (int j =0; j < n-1; j++) {
        for (int i = 0; i < n-1; i++) {
            if (x[i] > x[i + 1]) {
                //swap make the last one was biggest one
                // traditional way
                //T temp = x[i];
                //x[i] = x[i + 1];
                //x[i + 1] = temp;
                // swap function:
                swap(x[i],x[i+1]);
            }
        }
    }
}

template <typename T>
T sum(T x[], const int& n){
    T sum = x[0];
    for (int i =1; i < n; i++){
        sum += x[i];
    }
    return sum;
}

template <typename T>
void print(T x[], const int& n){
    for(int i=0; i < n; i++){
        cout << x[i] << " ";
    }
    cout << '\n';
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
	cout << sum(c, sizeof(c)/sizeof(string)) << '\n';
}