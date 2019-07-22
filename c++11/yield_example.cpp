// this_thread::yield example
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::yield
#include <atomic>         // std::atomic

using namespace std;

atomic<bool> ready (false);

void count1m(int id) {
    while (!ready) {             // wait until main() sets ready...
        this_thread::yield();
    }
    for (volatile int i=0; i<1000000; ++i) {}
    cout << id <<endl;
}

int main ()
{
    thread threads[10];
    cout << "race of 10 threads that count to 1 million:\n";
    for (int i=0; i<10; ++i) 
        threads[i] = thread(count1m, i);
    ready = true;               // go!
    for (auto& th : threads)
        th.join();
    cout << '\n';

    return 0;
}