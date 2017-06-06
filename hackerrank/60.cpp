/*

Copyright 2017 <Deng Haijun>

Tutorials > Cracking the Coding Interview > Hash Tables: Ransom Note 

Sample Input

6 4
give me one grand today night
give one grand today

Sample Output

Yes

Sample Input
15 17
o l x imjaw bee khmla v o v o imjaw l khmla imjaw x
imjaw l khmla x imjaw o l l o khmla v bee o o imjaw imjaw o

Sample Output
No
*/

/* you only have to complete the function given below.  
Node is defined as  
*/

#include "./common.h"

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    map<string, int> hash;
	for (vector<string>::iterator it = magazine.begin(); it != magazine.end(); it++) {
		if (hash.find(*it) == hash.end()) {
			hash[*it]=1;
		} else {
			hash[*it]++;
		}
	}
	bool ret = true;
	for (vector<string>::iterator it = ransom.begin(); it != ransom.end(); it++) {
		if (hash.find(*it) == hash.end()) {
			ret = false;
			break;
		} else if (hash[*it]>0) {
			hash[*it]--;
		} else {
			ret = false;
			break;
		}
	}
	return ret;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
