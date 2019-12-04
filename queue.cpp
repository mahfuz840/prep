#include<iostream>
using namespace std;

class Queue{
    public:
        int a[1000];
        int f, r;

        Queue() {
            f = r = -1;
        }

        bool push(int x) {
            if(isEmpty()){
                f = r = 0;
            }
            else 
                r = (r+1)%1000;

            a[r] = x;
        }

        int pop() {
            if(f == r)
            {
                f = r = -1;
                return a[f];
            }
            else {
                f = (f+1)%1000;
                return a[f-1];
            }
        }

        int front() {
            return a[f];
        }

        int size() {
            if(f == r) {
                if(f != -1)
                    return 1;
                else 
                    return 0;
            }
            if(r > f)
                return r-f+1;
            else 
                return 1000-f+r;
        }

        bool isEmpty(){
            if(f == -1)
                return true;
            else
                return false;
        }
};

int main() {
    Queue q;
    q.push(5);
    q.push(4);
    q.push(3);

    cout << q.pop() << endl;

    cout << q.front() << endl;

    if(q.isEmpty())
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;

    cout << q.size() << endl;
    q.pop();
    q.pop();
    cout << q.size() << endl;

    if(q.isEmpty())
        cout << "empty" << endl;
    else 
        cout << "not empty" << endl;
}