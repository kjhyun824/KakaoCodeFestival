/*
 * =====================================================================================
 *
 *       Filename:  booster.cpp
 *
 *    Description:  2018 Kakao Code Festival Prob 4 : Is possible to reach another checkpoint?
 *
 *        Version:  1.0
 *        Created:  08/04/18 15:56:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

int *X, *Y, *C;
int numCheck, numQuery;
deque<int> actives;
map<int, vector<int> > Xmap;
map<int, vector<int> > Ymap;
set<int> Xset, Yset;

int minDist(int start, int end) {
    if(abs(X[start] - X[end]) < abs(Y[start] - Y[end])) {
        return abs(X[start] - X[end]);
    } else {
        return abs(Y[start] - Y[end]);
    }
}

bool isPossible(int end, int hp) {
    while(!actives.empty()) {
        int start = actives.front();
        actives.pop_front();

        for(auto it = Xset.lower_bound(X[start] - hp); it != Xset.upper_bound(X[start] + hp); it++) {
            int x = *it;
            for(int i = 0; i < Xmap[x].size(); i++) {
                int id = Xmap[x][i];
                if(id == end) return true;
                if(C[id] == 0) {
                    if(!actives.empty() && (minDist(actives.front(), end) > minDist(id, end)))
                        actives.push_front(id);
                    else
                        actives.push_back(id);
                    C[id] = 1;
                }
            }
        }

        for(auto it = Yset.lower_bound(Y[start] - hp); it != Yset.upper_bound(Y[start] + hp); it++) {
            int y = *it;
            for(int i = 0; i < Ymap[y].size(); i++) {
                int id = Ymap[y][i];
                if(id == end) return true;
                if(C[id] == 0) {
                    if(!actives.empty() && (minDist(actives.front(), end) > minDist(id, end)))
                        actives.push_front(id);
                    else
                        actives.push_back(id);
                    C[id] = 1;
                }
            }
        }

        C[start] = 2;
    }

    return false;
}

int main() {
    cin >> numCheck >> numQuery;

    X = new int[numCheck+1];
    Y = new int[numCheck+1];
    C = new int[numCheck+1];

    for(int i = 1; i <= numCheck; i++) {
        cin >> X[i] >> Y[i];
        C[i] = 0;
        Xmap[X[i]].push_back(i);
        Ymap[Y[i]].push_back(i);
        Xset.insert(X[i]);
        Yset.insert(Y[i]);
    }

    for(int query = 0; query < numQuery; query++) {
        int start, end, hp;
        cin >> start >> end >> hp;

        deque<int> emptyQueue;
        actives.swap(emptyQueue);

        for(int i = 1; i <= numCheck; i++) {
            C[i] = 0;
        }

        actives.push_front(start);
        C[start] = 1;
        if(isPossible(end, hp)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    delete [] X;
    delete [] Y;
    delete [] C;

    return 0;
}
