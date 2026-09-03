class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int e =0;
        int o = 0;
        int se = INT_MAX;
        int so = INT_MAX;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                e++;
                if(nums1[i]<se){
                    se = nums1[i];
                }
            }
            if(nums1[i]%2==1){
                o++;
                if(nums1[i]<so){
                    so = nums1[i];
                }
            }
        }

        if(e==n || o==n){
            return true;
        }
        if(so<se){
            return true;
        }
        return false;
    }
};