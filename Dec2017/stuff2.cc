/*
ID: wenxzha1 
TASK: measurement
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list> 
#include <map> 
#define SVAL 0 
using namespace std;

// if the biggest value --> 
bool testing = true, testing2 = true;

struct cow{
    int day, id, milk;
    bool operator < (const cow b) const{
        return milk < b.milk;
    }
};

bool compCow(cow a, cow b){
    /*if(a.day == b.day){
        return a.id <  b.id;
    }*/
    return a.day < b.day;
}


void print(cow arr[], int N);

int main() {
    ifstream fin ("measurement.in");
    ofstream fout("measurement2.out"); 
    
    int N, G, daysChanged = 0, maxMilk = SVAL;
    fin >> N >> G;
   
    map<int, int, greater<int> > cc; // # of cows w/ this or change_counter
    map<int, int> cowlink_log; // cow list
    cow log[N];

    for(int i = 0; i < N; i++){
        fin >> log[i].day  >> log[i].id >> log[i].milk;
        cowlink_log[log[i].id] = SVAL;
    }

    sort(log, log+N, compCow);
    //print(log, N);
    //for(int i = 0)    
    cc[SVAL] = N; //starts with this #
    
    for(int i = 0; i < N; i++){
        cow tmp = log[i];
        //if (testing) fout << "Before processing day " << tmp.day << ", top cows have milk of " << cc.begin()-> first << endl;
       
        /*
            change = 0 --> nothing changes
            change = 1 --> removed a top cow || added a top cow
            change = 2 --> removed a top cow && changed the top cow Max # 
            change = 3 --> removed a top cow && changed the top cow Max # && added a top cow (the same one) --> need to check if it's the only one
            --> if == 1 || == 2 --> add
        */
        int change = 0; 
        //if(testing2 && (tmp.day == 420960 || tmp.day == 629734)) cout << "Changed #: " << change << "\tcc.begin() -> first: " << cc.begin() -> first << "\tcc.begin() -> second: " << cc.begin() -> second << endl;
        cc[cowlink_log[tmp.id]]--;
        if(cowlink_log[tmp.id] == cc.begin() -> first){
            cc.begin() -> second--;
            if(!cc.begin() -> second){
                cc.erase(cc.begin());
                change++;
                if(testing2 && (tmp.day == 420960 || tmp.day == 629734)) cout << "changed the top cow Max #\n";  
            }
            change++;
            if(testing2 && (tmp.day == 420960 || tmp.day == 629734)) cout << "removed a top cow\n";
            //if (testing) fout << "@ Day #" << tmp.day << ", top cow #" << tmp.id << " was taken down\n";
        }

        cowlink_log[tmp.id] += tmp.milk;
        cc[cowlink_log[tmp.id]]++;

        if(cowlink_log[tmp.id] == cc.begin() -> first){
            change++;
            if(testing2 && (tmp.day == 420960 || tmp.day == 629734)) cout << "added a top cow\n"; 
            //if (testing) fout << "@ Day #" << tmp.day << ", top cow #" << tmp.id << " was added\n";
        }
        if(change == 1 || change == 2 || (change == 3 && cc.begin() -> second > 1) ){
            if (testing) fout << "Before processing day " << tmp.day << ", top cows have milk of " << (cc.begin()-> first) - tmp.milk << " (possibly)" << endl;
            daysChanged++; 
            if (testing) fout << "After processing day " << tmp.day << ", top cows have milk of " << cc.begin()-> first << endl << endl;
        }
        if(testing2 && (tmp.day == 420960 || tmp.day == 629734)) cout << "Changed #: " << change << "\tcc.begin() -> first: " << cc.begin() -> first << "\tcc.begin() -> secon    d: " << cc.begin() -> second << endl;
        
    }
    fout << daysChanged << endl;
    if (testing) cout << daysChanged << endl;
    return 0;
}

void print(cow arr[], int N){
    for(int i = 0; i < N; i++){
        cout << arr[i].day << " " << arr[i].id << " " << arr[i].milk << endl;
    }
}




