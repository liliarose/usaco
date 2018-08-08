/*
ID: wenxzha1 
TASK: hayfeast
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
//#define MAX_SPICINESS 10000000000 

using namespace std;

int main() {

    bool debug = false;

    ifstream fin ("hayfeast.in");
    ofstream fout("hayfeast.out");
    
    unsigned int N, min_spicy = UINT_MAX; 
    long M, totF = 0;

    fin >> N >> M;

    unsigned int flavor[N];
    unsigned int spicy[N];

    for(int i = 0; i < N; i++){
        fin >> flavor[i] >> spicy[i];
    }
    
    //MS = max spice lvl
    for(unsigned int currMS = 0, prevMS_hay = 0, curr_hay = 0; curr_hay < N; curr_hay++){ 
        totF += flavor[curr_hay];
        if(spicy[curr_hay] > currMS) {
            currMS = spicy[curr_hay]; prevMS_hay = curr_hay;
        }
        if(totF >= M) { 
            if(currMS < min_spicy){ 
                min_spicy = currMS; 
            }
            totF = 0;   currMS = 0;
            curr_hay = prevMS_hay;
        }
    } 

    if(debug) {
        cout << min_spicy << endl;
    }
    fout << min_spicy << endl;

    return 0;
}
