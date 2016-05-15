#include <deque>
#include "common.h"

class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        int ret = -1;
        for (deque<pair<int, int> >::iterator it = cache.begin(); it!=cache.end(); ++it) {
            if (key==(*it).first) {
                pair<int, int> n = (*it);
                cache.erase(it);
                cache.push_back(n);
                ret = n.second;
            }
        }
        cout<<"get("<<key<<") = "<<ret<<endl;
        return ret;
    }

    void set(int key, int value) {
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
    }

private:
    deque<pair<int, int> > cache;
    int cap;
};

int main() {
    LRUCache l(2);
    l.set(2,1);
    l.set(2,2);
    l.get(2);
    l.set(1,1);
    l.set(4,1);
    l.get(2);
    return 0;
}
