#include<bits/stdc++.h>
using namespace std;

void add(int &subset, int n) {
    if(subset & (1 << (n - 1))) return;
    subset = subset ^ (1 << (n - 1));
}

void rem(int &subset, int n) {
    subset = subset ^ (1 << (n - 1));
}

void display(int subset) {
    for(int bit_no = 0;bit_no <= 9;bit_no++) {
        if(subset & (1 << bit_no)) {
            cout<<bit_no + 1<<" ";
        }
    }
    cout<<endl;
}

int main() {
    int set = 15;
    rem(set, 2);
    rem(set, 4);
    display(set);
    add(set, 4);
    display(set);
    
    return 0;
}