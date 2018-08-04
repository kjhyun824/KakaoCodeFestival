#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <assert.h>

using namespace std;

unsigned int Answer;

int main(unsigned int argc, char** argv)
{
	unsigned int N, i;
	cin >> N;
	
	vector<unsigned int> xs;
	vector<pair<unsigned int, unsigned int>> ys;

	unsigned int x0 = 0;
	unsigned int y0 = 0;

	unsigned int max_area = 0;
	xs.push_back(0);
	for(unsigned int i = 0; i  < N; i++)
	{
		unsigned int x, y;
		cin >> x;
		cin >> y;
		
		if(x != x0)
			xs.push_back(x);
		if(y != y0)
			ys.push_back({y0, y});
		x0 = x;
		y0 = y;
	}
	
	unsigned int x_max = xs[xs.size()-1];
	for(unsigned int i=0; i<xs.size() - 1;i++){
		unsigned int tmp = ~0;
		for(int j=xs.size()-1;j>=i+1;j--){
		//for(int j=i+1;j<xs.size();j++){
		//	cout << " " << j << "\n";
			unsigned int x0 = xs[i];
			unsigned int x1 = xs[j];
			
			unsigned int yi_min = ys[i].first < ys[i].second && ys[i].first !=0 ? ys[i].first : ys[i].second;
			unsigned int yj_min = ys[j].first < ys[j].second && ys[j].second !=0 ? ys[j].first : ys[j].second;
			unsigned int y_min = yi_min < yj_min ? yi_min : yj_min;
			
			if( y_min){
		//		cout << yi_min << " " << yj_min << "\n";

				if(y_min!=0 && y_min * x1 < max_area && y_min * (x_max-x0) < max_area){
		//			cout << x0 << "-" <<x1 << ":"<<max_area<< "\n";
					break;
				}
			}
				
			unsigned int min_height = ~0;
			for(unsigned int k=i; k < j+1;k++){
				if(min_height > ys[k].first && ys[k].first !=0 && k!=i)
					min_height = ys[k].first;
				if(min_height > ys[k].second && ys[k].second != 0 && k!=j)
					min_height = ys[k].second; 
			}
			if(tmp == min_height)
				continue;
			tmp = min_height;

			unsigned int area0 = min_height * (x1-x0);
			unsigned int bak = min_height;
			//cout <<x0 << "-" << x1 << ": " << min_height << ", " << area0 << "\n";
			if(area0 > max_area)
				max_area = area0;

			min_height = bak;
			
			if(x0 * min_height + area0 > max_area){

				for(int k=i-1; k >= 0; k--){
					unsigned int x2 = xs[k];

					if(min_height > ys[k].second && ys[k].second != 0)
						min_height = ys[k].second;
				
					unsigned int area1 = min_height * (x0 - x2);
					//cout << " < " <<x2 << "-" << x0 << ": " << min_height << ", " << area1 << "\n";
					if(area0+area1 > max_area)
						max_area = area0+area1;
				}
			}

			min_height = bak;

			if((x_max-x1)*min_height + area0 > max_area){
				for(unsigned int k=j+1; k <xs.size();k++){
					unsigned int x2 = xs[k];
	
					if(min_height > ys[k].first && ys[k].first !=0)
						min_height = ys[k].first;

					unsigned int area1 = min_height * (x2 - x1);
					//cout << " > " <<x1 << "-" << x2 << ": " << min_height << ", " << area1 << "\n";
					if(area0+area1 > max_area)
						max_area = area0+area1;
				}
			}
		}
	}

	Answer = max_area;
	cout << Answer << endl;

	return 0;
}

