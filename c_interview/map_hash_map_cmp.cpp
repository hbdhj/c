/*
g++ --std=c++11 map_hash_map_cmp.cpp
*/

#include <random>
#include <iostream>
#include <vector>
#include <time.h>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    time_t timer1, timer2;
    float time_diff;
    const int dice_size = 10000000;
    vector<int> dice_roll(dice_size, 0);
    time(&timer1);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, dice_size);
    for (int i = 0; i < dice_size; i++)
        dice_roll[i] = distribution(generator);
    time(&timer2);
    time_diff = difftime(timer2, timer1);
    printf("%.f second to generate %d random numbers\n", time_diff, dice_size);
    time(&timer1);
    map<int, int> dice_map;
    for (int i = 0; i < dice_size; i++) {
        if (dice_map.find(dice_roll[i])== dice_map.end())
            dice_map[dice_roll[i]] = 1;
        else
            dice_map[dice_roll[i]]++;
    }
    time(&timer2);
    time_diff = difftime(timer2, timer1);
    printf("%.f second to insert %d random numbers to a map\n", time_diff, dice_size);
    time(&timer1);
    unordered_map<int, int> dice_hash;
    for (int i = 0; i < dice_size; i++) {
        if (dice_hash.find(dice_roll[i]) == dice_hash.end())
            dice_hash[dice_roll[i]] = 1;
        else
            dice_hash[dice_roll[i]]++;
    }
    time(&timer2);
    time_diff = difftime(timer2, timer1);
    printf("%.f second to insert %d random numbers to a unordered_map and bucket_count() = %d\n", time_diff, dice_size, dice_hash.bucket_count());
    return 0;
}
