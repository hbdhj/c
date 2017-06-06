/*
Copyright 2017 <Deng Haijun>

Data Structures > Heap > Jesse and Cookies

Sample Input

6 7
1 2 3 9 10 12

Sample Output

2

Result: not pass
*/

#include "./common.h"

// Map to maintain the index of values in the heap.
map<int, int> value_index;
int heap[500002], heap_size = 0;

void insert_val(int val) {
    if (heap_size == 0) {
        heap[++heap_size] = val;
        value_index[val] = heap_size;
        return;
    }
    heap[++heap_size] = val;
    value_index[val] = heap_size;
    int iter = heap_size;
    while (iter > 1) {
        if (heap[iter] < heap[iter/2]) {
            value_index[heap[iter]] = iter/2;
            value_index[heap[iter/2]] = iter;
            int temp = heap[iter];
            heap[iter] = heap[iter/2];
            heap[iter/2] = temp;
            iter /= 2;
        } else {
            break;
        }
    }
}

void delete_val(int val) {
    int index = value_index[val];
    value_index[val] = 0;
    value_index[heap[heap_size]] = index;
    heap[index] = heap[heap_size--];
    while (true) {
        int left_child = 2*index, right_child = 2*index + 1;;
        if (left_child <= heap_size) {
            if (right_child <= heap_size) {
                if (heap[index] > heap[left_child]
                 || heap[index] > heap[right_child]) {
                    int swap_index = (heap[left_child] < heap[right_child])?
                                      left_child:right_child;
                    value_index[heap[swap_index]] = index;;
                    value_index[heap[index]] = swap_index;;
                    int temp = heap[index];
                    heap[index] = heap[swap_index];
                    heap[swap_index] = temp;
                    index = swap_index;
                } else {
                    break;
                }
            } else {
                if (heap[index] > heap[left_child]) {
                    value_index[heap[left_child]] = index;
                    value_index[heap[index]] = left_child;
                    int temp = heap[index];
                    heap[index] = heap[left_child];
                    heap[left_child] = temp;
                    index = left_child;
                } else {
                    break;
                }
            }
        } else {
            break;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    while (n--) {
        int ai;
        cin >> ai;
        insert_val(ai);
    }
    int count = 0;
    while (heap[1] < k) {
        insert_val(heap[1]+heap[2]*2);
        delete_val(heap[1]);
        delete_val(heap[1]);
        count++;
    }
    cout << count << endl;
    return 0;
}
