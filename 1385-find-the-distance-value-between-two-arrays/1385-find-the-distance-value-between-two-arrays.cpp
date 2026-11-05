class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        int s1 = arr1.size();
        int s2 = arr2.size();
        int i = 0;
        int j = 0;

        while(i<s1){
            bool c = true;
            j=0;
            while(j<s2){
                if(abs(arr1[i]-arr2[j])<=d){
                    c = false;
                    break;
                }
                j++;
            }
            if(c==true){
                count++;
            }
            i++;
        }
        return count;
    }
};