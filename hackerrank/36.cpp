/*
The Coin Change Problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int coinChange(vector<int> coins, int amount) {
    int ret = 0;
    int o_amount = amount;
    if (amount<=0) {
        ret = 1;
    } else if (coins.size()==1) {
        ret = amount%coins[0]==0?1:0;
    } else {
        vector<int>::reverse_iterator rit;
        for (rit=coins.rbegin(); rit != coins.rend(); ++rit) {
            vector<int> lessCoins;
            for (int i = 0; i<coins.size()-1; i++) {
                lessCoins.push_back(coins[i]);
            }
            while (amount>=0) {
                ret+=coinChange(lessCoins, amount);
                amount-=(*rit);
            }
        }
    }
    return ret;
}

int main() {
    int amount, num, coin;
    cin>>amount>>num;
    vector<int> coins;
    for(int i=0; i<num; i++) {
        cin>>coin;
        coins.push_back(coin);
    }
    cout<<coinChange(coins, amount);
    return 0;
}
