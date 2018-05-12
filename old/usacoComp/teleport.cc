/*
ID: your_id_here
TASK: teleport 
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("teleport.out");
    ifstream fin ("teleport.in");
    int a, b, x, y;
    fin >> a >> b >> x >> y;
    int min = ((a-b) > 0) ? (a - b):(b - a);
	//cout << "min: " << min << endl;
	int tmp = ((a-x) > 0) ? (a - x):(x - a);
	tmp += (b - y > 0) ? (b - y):(y - b);
	if (tmp < min) { min = tmp; }
	//cout << "x to y: " << tmp << endl;
	tmp = ((a - y) > 0) ? (a - y):(y - a);
	tmp += (b - x  > 0) ? (b - x):(x - b);
	if (tmp < min) { min = tmp; }
	//cout << "y to x: " << tmp << endl;
	fout << min << endl;
	return 0;
}
