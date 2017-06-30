/*
g++ --std=c++11 map_hash_map_cmp.cpp

output:
19.76 second to insert 10000000 random numbers to a map
6.14 second to insert 10000000 random numbers to a unordered_map and bucket_count() = 8844859
unordered_map is 3.22 faster than map and need 0.88 times space

-O1
9.14 second to insert 10000000 random numbers to a map
2.92 second to insert 10000000 random numbers to a unordered_map and bucket_count() = 8844859
unordered_map is 3.13 faster than map and need 0.88 times space

-O2
8.97 second to insert 10000000 random numbers to a map
3.00 second to insert 10000000 random numbers to a unordered_map and bucket_count() = 8844859
unordered_map is 2.99 faster than map and need 0.88 times space

-O3
8.93 second to insert 10000000 random numbers to a map
3.00 second to insert 10000000 random numbers to a unordered_map and bucket_count() = 8844859
unordered_map is 2.97 faster than map and need 0.88 times space
*/

#include <random>
#include <iostream>
#include <vector>
//#include <ctime>
#include <time.h>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    //long double timer1, timer2;
    clock_t timer1, timer2;
    const int dice_size = 10000000;
    vector<int> dice_roll(dice_size, 0);
    timer1 = clock();
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, dice_size);
    for (int i = 0; i < dice_size; i++)
        dice_roll[i] = distribution(generator);
    timer2 = clock();
    float time_diff1 = (timer2 - timer1)/CLOCKS_PER_SEC;
    // printf("%.2f second to generate %d random numbers\n", time_diff1, dice_size);
    timer1 = clock();
    map<int, int> dice_map;
    for (int i = 0; i < dice_size; i++) {
        if (dice_map.find(dice_roll[i])== dice_map.end())
            dice_map[dice_roll[i]] = 1;
        else
            dice_map[dice_roll[i]]++;
    }
    timer2 = clock();
    float time_diff2 = float(timer2 - timer1)/CLOCKS_PER_SEC;
    // printf("timer2 = %.2f, timer1 = %.2f, time_diff2 = %.2f, CLOCKS_PER_SEC = %d\n", timer2, timer1, time_diff2, CLOCKS_PER_SEC);
    printf("%.2f second to insert %d random numbers to a map\n", time_diff2, dice_size);
    timer1 = clock();
    unordered_map<int, int> dice_hash;
    for (int i = 0; i < dice_size; i++) {
        if (dice_hash.find(dice_roll[i]) == dice_hash.end())
            dice_hash[dice_roll[i]] = 1;
        else
            dice_hash[dice_roll[i]]++;
    }
    timer2 = clock();
    float time_diff3 = float(timer2 - timer1)/CLOCKS_PER_SEC;
    // printf("timer2 = %.2f, timer1 = %.2f, time_diff3 = %.2f, CLOCKS_PER_SEC = %d\n", timer2, timer1, time_diff3, CLOCKS_PER_SEC);
    printf("%.2f second to insert %d random numbers to a unordered_map and bucket_count() = %d\n", time_diff3, dice_size, dice_hash.bucket_count());
    printf("unordered_map is %.2f faster than map and need %.2f times space\n", time_diff2 / time_diff3, float(dice_hash.bucket_count()) / dice_size);
    return 0;
}
