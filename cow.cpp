#include<iostream>
#include<algorithm>
using namespace std;
void quickSOrt(int a[], int low, int high);
int partition(int a[], int low, int high);
bool check(int a[], int mid, int n, int k) {
    int counter = 1;
    int pos = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i]-pos >= mid) {
            counter++;
            pos = a[i];

            if(counter == k){
                // cout << mid << endl;
                return true;
            }
        }
    }
    return false;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low-1;
    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[high];
        a[high] = a[i+1];
        a[i+1] = temp;

    return (i+1);
}

int main() {
    int a[100001];
    int n, k;
    int t;
    int res;
    cin >> t;
    while(t--) {
        res = -1;

        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> a[i];

        // quickSort(a, 0, n-1);
        sort(a, a+n);
        // for(int i = 0; i < n; i++)
        //     cout << a[i] << " ";

        int left = a[0], right = a[n-1];
        while(left < right) {
            int mid = (left+right)/2;

            if(check(a, mid, n, k)) {
                if(mid > res)
                    res = mid;
                left = mid+1;
            }
            else 
                right = mid;
        }

        cout << res << endl;
    }

    return 0;
}