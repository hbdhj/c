#include <deque>
#include "common.h"

class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        cout<<"try to get value for key"<<endl;
        int ret = -1;
        for (deque<pair<int, int> >::iterator it = cache.begin(); it!=cache.end(); ++it) {
            if (key==(*it).first) {
                ret = (*it).second;
                cache.erase(it);
                break;
            }
        }
        if (ret!=-1) {
            pair<int, int> n(key, ret);
            cache.push_back(n);
        }
        cout<<"get("<<key<<") = "<<ret<<endl;
        return ret;
    }

    void set(int key, int value) {
        cout<<"set key "<<key<<" to "<<value<<endl;
        for (deque<pair<int, int> >::iterator it = cache.begin(); it!=cache.end(); ++it) {
            if (key==(*it).first) {
                cache.erase(it);
                break;
            }
        }
        if (cache.size()>=cap) {
            cache.pop_front();
        }
        cache.push_back(pair<int, int>(key, value));
        cout<<"done"<<endl;
    }

private:
    deque<pair<int, int> > cache;
    int cap;
};

int UnitTest1() {
    LRUCache l(2);
    l.set(2,1);
    l.set(2,2);
    l.get(2);
    l.set(1,1);
    l.set(4,1);
    l.get(2);
    return 0;
}

int UnitTest2() {
    LRUCache l(1);
    l.set(2,1);
    l.get(2);
    return 0;
}

int main() {
    UnitTest1();
    UnitTest2();
    return 0;
}
