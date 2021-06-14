class Solution {
public:
    struct comparator{
        bool operator()(vector<int>& box1, vector<int>& box2){
            return box1[1] > box2[1];
        }    
    };
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comparator());
        int sum = 0;
        for(auto& box : boxTypes){
            if(truckSize > box[0]){
                truckSize -= box[0];
                sum += box[0]*box[1];
            }
            else{
                sum += truckSize*box[1];
                break;
            }
        }
        return sum;
    }
};
