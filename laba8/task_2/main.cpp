#include <iostream>
#include <queue>
#include <algorithm>
#include <chrono>
#include <random>
#include "heapSort.h"
#include <random>


int main() {
// Additional task
    std::cout << "[Log] Comparing sorting algorithms...\n";
    std::cout << "Additional task:" << std::endl;
    std::vector<int> vec(1000000);
    std::cout << "Created a vector of size " << vec.size() << std::endl;
    std::generate(vec.begin(), vec.end(), []() -> int
    {
        return rand() % 123;
    });

    std::random_device d;
    std::mt19937 g(d());

    auto start = std::chrono::steady_clock::now();
    std::sort(vec.begin(), vec.end());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsed = end - start;
//    std::cout << "[Timer] std::sort() time elapsed: " << elapsed << "\n";

    std::shuffle(vec.begin(), vec.end(), g);

    start = std::chrono::steady_clock::now();
    HeapSortInplace(vec.begin(), vec.end());
    end = std::chrono::steady_clock::now();
    elapsed = end - start;
//    std::cout << "[Timer] HeapSortInplace() time elapsed: " << elapsed << "\n";
    std::cout << "[Log] Comparing sorting algorithms - done\n";

    std::vector<int> heap(1000);
    std::generate(heap.begin(), heap.end(), []() -> int
    {
        return rand() % 123;
    });
    std::cout << "[Log] Before MakeHeap(): " << (std::is_heap(heap.begin(), heap.end()) ? "Is a heap\n" : "Not a heap\n");
    std::cout << "[Log] Making a heap...\n";
    MakeHeap(heap.begin(), heap.end());
    std::cout << "[Log] Making a heap - done\n";
    std::cout << "[Log] After MakeHeap(): " << (std::is_heap(heap.begin(), heap.end()) ? "Is heap\n" : "Not a heap\n");
}
