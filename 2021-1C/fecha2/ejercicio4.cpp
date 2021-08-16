#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>

int main(){

  std::queue<int> produced_nums;
  std::mutex m;
  std::condition_variable cond_var;
  bool done = false;
  bool notified = false;

    std::thread producer([&]() {
        for (int i = 1; i <= 100; ++i) {
            std::unique_lock<std::mutex> lock(m);
            produced_nums.push(i);
            notified = true;
            cond_var.notify_one();
        }

        done = true;
        cond_var.notify_one();
    });

    std::thread consumer([&]() {
        std::unique_lock<std::mutex> lock(m);
        while (!done) {
            while (!notified) {
                cond_var.wait(lock);
            }
            while (!produced_nums.empty()) {
                std::cout << produced_nums.front() << ' ';
                produced_nums.pop();
            }
            notified = false;
        }
    });

    producer.join();
    consumer.join();
}
