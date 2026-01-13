class Solution {
public:
    double lowerArea(double mid_y,vector<vector<int>>& squares){
        double areaDown=0;
        for(auto &it:squares){
            double x=it[0];
            double y=it[1];
            double l=it[2];
            if(mid_y<=y) continue;
            else if(mid_y>=y+l){
                areaDown+=(l*l);
            }else{
                areaDown+=(l*(mid_y-y));
            }
        }
        return areaDown;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low=0;
        double high=0;
        double totalArea=0;
        double mid=0;
        for(auto &it:squares){
            double x=it[0];
            double y=it[1];
            double l=it[2];
            totalArea+=(l*l);
            high=max(high,y+l);  
        }
        double ans=0;
        double eps = 1e-6;
        while(high-low>eps){
            mid=(low+high)/2.0;
            if(lowerArea(mid,squares)>=totalArea/2.0){
                ans=mid;
                high=mid;
            }else{
                low=mid;
            }
        }
        return ans;
    }
};