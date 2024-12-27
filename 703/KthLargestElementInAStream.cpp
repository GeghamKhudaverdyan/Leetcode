#include <iostream>
#include <vector>
#include <queue>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : m_k(k) {
        for(int i : nums) {
            add(i);
        }
    }

    int add(int val) {
        m_minHeap.push(val);
        if(m_minHeap.size() > m_k) {
            m_minHeap.pop();
        }
        return m_minHeap.top();
    }

    private:
        int m_k;
        std::priority_queue<int, std::vector<int>, std::greater<int>> m_minHeap;
};

int main() {

    int k = 3;
    std::vector<int> nums{4, 5, 8, 2};
    KthLargest* obj = new KthLargest(k, nums);
    int param_1 = obj->add(3); 
    std::cout << "3rd largest after adding 3: " << param_1 << std::endl;
    param_1 = obj->add(5);
    std::cout << "3rd largest after adding 5: " << param_1 << std::endl;
    param_1 = obj->add(10);
    std::cout << "3rd largest after adding 10: " << param_1 << std::endl;
    param_1 = obj->add(9);
    std::cout << "3rd largest after adding 9: " << param_1 << std::endl;

    delete obj;

    return 0;
}