#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int maxWater_bf(vector<int> &height){
    int maxwater=0;
    int area;
    for(int i=0; i<height.size(); i++){
        for(int j=i+1; j<height.size(); j++){
            int w = j-i;
            int h = min(height[i], height[j]);
            area = w*h;
            maxwater=max(maxwater,area);
        }
    }
    return maxwater;
}

int maxWater_o(vector<int> &height){
    int lp=0, rp=height.size()-1;
    int maxwater=0, area;
    while(lp<rp){
        int w=rp-lp;
        int h=min(height[lp],height[rp]);
        area=w*h;
        maxwater=max(area, maxwater);
        height[lp]<height[rp]?lp++:rp--;
   }
   return maxwater;
}

int main(){
   vector<int>height = {1,8,6,2,5,4,8,3,7};
   int ans = maxWater_bf(height);
   cout << "The answer using the brute force approach is: " << ans <<endl;

   int ans2 = maxWater_o(height);
   cout << "The answer using the optimised approach is: " << ans2 << endl;
   return 0;
}
