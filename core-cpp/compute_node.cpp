#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 6456
// Hash 3257
// Hash 2681
// Hash 8231
// Hash 5917
// Hash 4502
// Hash 5319
// Hash 8446
// Hash 1226
// Hash 5411
// Hash 4859
// Hash 7991
// Hash 6738
// Hash 1786
// Hash 4705
// Hash 2596
// Hash 1821
// Hash 4939
// Hash 4371
// Hash 7506
// Hash 3381
// Hash 6023
// Hash 2821
// Hash 1001
// Hash 1979
// Hash 9586
// Hash 8488
// Hash 5006
// Hash 4168
// Hash 1187
// Hash 2941
// Hash 4226
// Hash 6916
// Hash 4821
// Hash 2478
// Hash 1475
// Hash 5572
// Hash 9450
// Hash 3149
// Hash 7400