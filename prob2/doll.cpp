/*
 * =====================================================================================
 *
 *       Filename:  doll.cpp
 *
 *    Description:  2018 Kakao Code Festival Prob 2 : Find smallest standard deviation among the doll list
 *
 *        Version:  1.0
 *        Created:  08/04/18 13:48:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long long LL;

LL sum[250000];
LL squareSum[250000];

int main() {
    int numDoll, minK;
    cin >> numDoll >> minK;

    LL dolls[numDoll];
    LL dolls2[numDoll];

    for(int i = 0; i < numDoll; i++) {
        cin >> dolls[i];
        dolls2[i] = dolls[i] * dolls[i];
    }

    double minVal = -1; 

    for(int i = 0; i <= numDoll - minK; i++) {
        sum[(minK-1) * 500 + i] = 0;
        squareSum[(minK-1) * 500 + i] = 0;
        for(int j = 0; j < minK; j++) {
            sum[(minK-1) * 500 + i] += dolls[i+j];
            squareSum[(minK-1) * 500 + i] += dolls2[i+j];
        }

        LL currVal = squareSum[(minK-1) * 500 + i] * minK;
        currVal -= sum[(minK-1) * 500 + i] * sum[(minK-1) * 500 + i];
        double var = (double) currVal / (double) (minK * minK);

        if(minVal < 0 || var < minVal) {
            minVal = var;
        }
    }

    for(int k = minK + 1; k <= numDoll; k++) {
        for(int i = 0; i <= numDoll - k; i++) {
            sum[(k-1) * 500 + i] = sum[(k-2) * 500 + i] + dolls[i+(k-1)];
            squareSum[(k-1) * 500 + i] = squareSum[(k-2) * 500 + i] + dolls2[i+(k-1)];

            LL currVal = squareSum[(k-1) * 500 + i] * k;
            currVal -= sum[(k-1) * 500 + i] * sum[(k-1) * 500 + i];
            double var = (double) currVal / (double) (k * k);

            if(var < minVal) {
                minVal = var;
            }
        }
    }

    cout << setprecision(11) << sqrt(minVal) << endl;

    return 0;
}
