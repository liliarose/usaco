/*
ID: wenxzha1 
TASK: billboard
LANG: C++                 
*/
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
    
    for(int i = 0, t1, t2; i < 6; i++){
        fin >> data[i].x >> data[i].y;
    }

    fout << fvisible(data[0], data[1], data[4], data[5]) + fvisible(data[2], data[3], data[4], data[5]) << endl;
    return 0;
}

int fvisible( pt bll, pt bru, pt tll, pt tru){
    int width = max(0, min(bru.x, tru.x) - max(bll.x, tll.x));
    int height = max(0, min(bru.y, tru.y) - max(bll.y, tll.y));
    return (bru.x - bll.x)*(bru.y - bll.y) - width*height;
}









