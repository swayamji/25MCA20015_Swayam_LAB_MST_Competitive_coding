/*845. Longest Mountain in Array*/
/*25MCA20015 Swayam*/

class Solution {
public:
    int longestMountain(vector<int>& arr){
        int n=arr.size();
        vector<int> fore(n,0),back(n,0);

        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1])
                fore[i+1]=fore[i]+1;
        }

           for(int i=n-1;i>0;i--){
            if(arr[i]<arr[i-1])
                back[i-1]=back[i]+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(fore[i]>0 && back[i]>0){
                ans=max(ans,fore[i]+back[i]+1);
            }
        }
        return ans;
}
};
