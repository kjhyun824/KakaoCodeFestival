/*
 * =====================================================================================
 *
 *       Filename:  prize.cpp
 *
 *    Description:  2018 Kakao Code Festival Prob 1 : How much the prize is?
 *
 *        Version:  1.0
 *        Created:  08/04/18 13:22:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int main() {
    int numCase;
    cin >> numCase;

    for(int i = 0; i < numCase; i++) {
        int answer = 0;
        int rank1, rank2;
        cin >> rank1 >> rank2;

        if (rank1 == 0) answer += 0;
        else if (rank1 <= 1) answer += 500;
        else if (rank1 <= 3) answer += 300;
        else if (rank1 <= 6) answer += 200;
        else if (rank1 <= 10) answer += 50;
        else if (rank1 <= 15) answer += 30;
        else if (rank1 <= 21) answer += 10;

        if (rank2 == 0) answer += 0;
        else if (rank2 <= 1) answer += 512;
        else if (rank2 <= 3) answer += 256;
        else if (rank2 <= 7) answer += 128;
        else if (rank2 <= 15) answer += 64;
        else if (rank2 <= 31) answer += 32;

        cout << answer*10000 << endl;
    }
}
