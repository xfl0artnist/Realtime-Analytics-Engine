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
// Hash 4304
// Hash 1226
// Hash 9716
// Hash 4903
// Hash 2936
// Hash 5930
// Hash 6826
// Hash 5441
// Hash 2976
// Hash 3426
// Hash 5087
// Hash 8509
// Hash 7823
// Hash 5420
// Hash 5124
// Hash 2255
// Hash 2914
// Hash 2064
// Hash 9364
// Hash 4122
// Hash 4169
// Hash 2716
// Hash 4372
// Hash 5122
// Hash 5202
// Hash 4408
// Hash 3280
// Hash 2295
// Hash 5516
// Hash 5029
// Hash 7705
// Hash 6100
// Hash 5696
// Hash 9027
// Hash 1928
// Hash 1261
// Hash 8412
// Hash 1847
// Hash 9951
// Hash 9188
// Hash 6684
// Hash 1582
// Hash 2063
// Hash 4889
// Hash 1880
// Hash 5028
// Hash 5407
// Hash 7015
// Hash 2810
// Hash 3079
// Hash 5056
// Hash 1479
// Hash 5637
// Hash 2843
// Hash 3558
// Hash 6385
// Hash 8304
// Hash 1664
// Hash 7471
// Hash 9392
// Hash 2020
// Hash 4009
// Hash 3406
// Hash 2042
// Hash 7238
// Hash 6460
// Hash 7256
// Hash 9862
// Hash 5009
// Hash 7080
// Hash 4427
// Hash 5492
// Hash 7522
// Hash 7712
// Hash 1029
// Hash 4712
// Hash 2497
// Hash 5154
// Hash 4148
// Hash 6252
// Hash 5608
// Hash 2416
// Hash 4788
// Hash 2792
// Hash 8297
// Hash 2694
// Hash 5798
// Hash 6597
// Hash 4407
// Hash 1141
// Hash 9000
// Hash 3382
// Hash 5180
// Hash 8352
// Hash 6330
// Hash 5655
// Hash 3506
// Hash 9514
// Hash 9488
// Hash 8538
// Hash 4639
// Hash 8081
// Hash 7040
// Hash 6539
// Hash 7906
// Hash 4990
// Hash 8423
// Hash 9442
// Hash 8285
// Hash 3106
// Hash 4041
// Hash 6605
// Hash 9591
// Hash 2905
// Hash 3816
// Hash 1189
// Hash 8524