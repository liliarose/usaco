/*
ID: wenxzha1 
TASK: billboard
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct pt{
    int x;
    int y;
};

int fvisible(pt tru, pt tll, pt br, pt bll);
int fvisible2(pt tru, pt tll, pt br, pt bll);
int main() {
    ifstream fin ("billboard.in");
    ofstream fout("billboard.out");
    pt data[6];

    // 0 = ll first, 1 = ru first .... 4 = truck ll, 5 = truck ru
    for(int i = 0, t1, t2; i < 6; i++){
        fin >> t1 >> t2;
        data[i].x = t1;
        data[i].y = t2;
        //cout <<"(" <<  data[i].x << ", " <<  data[i].y << ")\t";
    }
    //cout << endl;

    fout << fvisible(data[0], data[1], data[4], data[5]) + fvisible(data[2], data[3], data[4], data[5]) << endl;
    //fout << fvisible2(data[0], data[1], data[4], data[5]) + fvisible2(data[2], data[3], data[4], data[5]) << endl;
    return 0;
}

int fvisible( pt bll, pt bru, pt tll, pt tru){
    int width = max(0, min(bru.x, tru.x) - max(bll.x, tll.x));
    int height = max(0, min(bru.y, tru.y) - max(bll.y, tll.y));
    return (bru.x - bll.x)*(bru.y - bll.y) - width*height;
}
/*
int fvisible2( pt bll, pt bru, pt tll, pt tru){
    int width = 0, height = 0;
    if(tru.x > bru.x && tll.x < bll.x){ width = abs(bru.x - bll.x); }
    else if(tru.x < bru.x && tll.x > bll.x) { width = abs(tru.x - tll.x); }
    else if(bll.x < tru.x && bll.x > tll.x){ width = abs(tru.x - bll.x); }
    else if(bru.x < tru.x && bru.x > tll.x){ width = abs(bru.x - tll.x); }
    //cout << width << "\t";

    if(tru.y > bru.y && tll.y < bll.y){ height = abs(bru.y - bll.y); }
    else if(tru.y < bru.y && tll.y > bll.y) { height = abs(tru.y - tll.y); }
    else if(bll.y < tru.y && bll.y > tll.y){ height = abs(tru.y - bll.y); }
    else if(bru.y < tru.y && bru.y > tll.y){ height = abs(bru.y - tll.y); }
    //cout << height << endl;

    return (bru.x - bll.x)*(bru.y - bll.y) - width*height;
}*/









