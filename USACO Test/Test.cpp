#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap() {}

    MaxHeap(vector<int>& nums) {
        heap = nums;
        for (int i = (heap.size() - 1) / 2; i >= 0; i--) {
            heapify(i);
        }
    }

    void push(int num) {
        heap.push_back(num);
        int i = heap.size() - 1;
        int parent = (i - 1) / 2;
        while (i > 0 && heap[i] > heap[parent]) {
            swap(heap[i], heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    int pop() {
        int max_num = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return max_num;
    }

    int top() {
        return heap.front();
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};

int main() {
    vector<int> nums = {3, 5, 1, 2, 7, 6, 8, 4};
    MaxHeap max_heap(nums);

    while (!max_heap.empty()) {
        cout << max_heap.pop() << " ";
    }
    cout << endl;

    return 0;
}
