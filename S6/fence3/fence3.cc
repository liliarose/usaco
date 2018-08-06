/*
ID: wenxzha1 
TASK: fence3
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <float.h>
#define MAX 150
#define EPSILON 0.000001

using namespace std;
struct pt{
    double x, y;
    pt(double tx = 0, double ty = 0){
        x = tx;
        y = ty;
    }
    friend ostream &operator << (ostream &out, const pt &p){
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
    bool operator < (const pt &p) const{
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
};

//lineSeg segment
struct lineSeg{
   pt a, b;
   lineSeg(double ax = 0, double ay = 0, double bx = 0 , double by = 0){
        if(ax < bx){
            a.x = ax, a.y = ay;
            b.x = bx, b.y = by;
        } else {
            a.x = by, a.y = by;
            b.x = ax, b.y = ay;
        }
   }
   lineSeg(pt i, pt j){
        lineSeg(i.x, i.y, j.x, j.y);
   }
   friend ostream &operator << (ostream &out, const lineSeg &l){
        out << l.a << " - " << l.b;
        return out;
   }
   bool operator < (const lineSeg &l) const {
        return a < l.a;
   }

};

int N;
lineSeg fences[MAX];
int fX[] = {1, 1, 1, 0, 0, -1, -1, -1};
int fY[] = {1, 0, -1, 1, -1, 1, 0, -1};

double dist(const pt &a, const pt &b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double dot_product(const lineSeg &l, const lineSeg &l2){
    return (l.a.x - l.b.x)*(l2.a.x - l2.b.x) + (l.a.y - l.b.y)*(l2.a.y - l2.b.y);
}

double pt_line(pt l1, pt l2, pt a){
    return abs(((l1.y - l2.y)*a.x - (l1.x - l2.x)*a.y + (l1.x*l2.y - l2.x*l1.y))/dist(l1, l2));
}

double pt_lineSeg_dist(const lineSeg &l, const pt &p){ 
//    double dpd = dot_product(l, lineSeg(l.a, p));
//    if(dot_product(l, lineSeg(l.a, p)) < 0) return dist(l.a, p);
//    if(dot_product(l, lineSeg(l.b, p)) < 0) return dist(l.b, p);
    return pt_line(l.a, l.b, p);
    //return abs(((l.a.y - l.b.y)*p.x - (l.a.x - l.b.x)*p.y + (l.a.x*l.b.y - l.a.y*l.b.x))/dist(l.a, l.b));
    //pt line distance --> return abs(((l1.y - l2.y)*a.x - (l1.x - l2.x)*a.y + (l1.x*l2.y - l2.x*l1.y))/dist(l1, l2));
}

double totDist(pt M){
    double totD = 0;
    for(int i = 0; i < N; i++){
        double t = pt_lineSeg_dist(fences[i], M);
        totD += t;
        cout << fences[i] << ": " << t << endl; 
    }
    cout << M << ": " << totD << endl;
    return totD;
}

bool isValid(pt p){
    return p.x >= 0 && p.y >= 0 /*&& p.x <= 100 && p.y <= 100*/;
}

//can optimize to calculate less?
//if not shortest, return -1, else return a +# && change curr 
bool shortest(pt &curr, double &min, const double increment){
    double tMin = min + 1, tmp;
    pt nxt, spMidpt;
    for(int i = 0; i < 8; i++){
        nxt.x = curr.x + fX[i]*increment;
        nxt.y = curr.y + fY[i]*increment;
        if(isValid(nxt)){
            tmp = totDist(nxt);
            if((tMin - tmp) > EPSILON){
                tMin = tmp;
                spMidpt.x = nxt.x, spMidpt.y = nxt.y;
            }
        }
    }
    if (min > tMin){
        curr.x = spMidpt.x;
        curr.y = spMidpt.y;
        min = tMin;
        return true;
    }   
    return false;
}

int main() {
    ifstream fin ("fence3.in");
    ofstream fout("fence3.out");
    
    fin >> N;

    for(int i = 0; i < N; i++){
        fin >> fences[i].a.x >> fences[i].a.y >> fences[i].b.x >> fences[i].b.y;
        cout << fences[i] << endl;
    }

    double min = DBL_MAX, increment = 10, tmp = 0;

    pt curr(0, 0); //optimize later
    do{
        if(!shortest(curr, min, increment)){
            increment /= 10;
        }
        //cout << curr << " " << min << endl;
    }while(increment >= 0.001);
    cout << "ANSWER: " << curr << " " << min << endl;
    return 0;
}


















