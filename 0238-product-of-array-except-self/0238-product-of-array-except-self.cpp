class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n);
        vector<int>post(n);

        pre[0] = nums[0];
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1] * nums[i];
        }

        post[n - 1] = nums[n - 1];
        for(int i = n-2; i>=0; i--){
            post[i] = post[i+1] * nums[i];
        }
        
        vector<int> ans(n);

        for(int i = 0; i<n; i++){
            if(i == 0){
                ans[i] = post[i+1];
            }else if(i == n-1){
                ans[i] = pre[i-1];
            }else{
                ans[i] = pre[i-1] * post[i+1];
            }
        }
        return ans;
    }
};