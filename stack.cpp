#include<iostream>
using namespace std;

class Stack {
    public:
        int a[1000];
        int index;

        Stack() {
            index = -1;
        }

        bool push(int x) {
            if(index >= 1000)
                return false;
            else
            {
                a[++index] = x;
                return true;
            }
            
        }
        int pop() {
                return a[index--];
        }
        int size() {
            return index+1;
        }
        bool isEmpty() {
            if(index < 0)
                return true;
            else 
                return false;
        }

        int top() {
            return a[index];
        }
};

int main() {
    Stack st;
    st.push(5);
    st.push(4);
    st.push(3);

    int size = st.size();
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;

    return 0;
}





