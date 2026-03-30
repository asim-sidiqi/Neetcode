/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int binarySearch(MountainArray &mountainArr, int l, int r, int target){
        int mid = l + (r-l)/2;
        while(l<=r){
            if(mountainArr.get(mid)==target) return mid;

            else if(mountainArr.get(mid)<target) l=mid+1;

            else r=mid-1;

            mid = l + (r-l)/2;
        }

        return -1;
    }

    int binarySearch2(MountainArray &mountainArr, int l, int r, int target){
        int mid = l + (r-l)/2;
        while(l<=r){
            if(mountainArr.get(mid)==target) return mid;

            else if(mountainArr.get(mid)<target) r=mid-1;

            else l=mid+1;

            mid = l + (r-l)/2;
        }

        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l=0, r=n-1;
        int mid = l+(r-l)/2;
        while(l<=r){
            if(mountainArr.get(mid)==target) return mid;

            if(mid>0 && mid<n-1 && mountainArr.get(mid)<mountainArr.get(mid+1) && mountainArr.get(mid)>mountainArr.get(mid-1)){
                if(target<mountainArr.get(mid)){
                    r=mid-1;
                }
                else l=mid+1;
            }

            else if(mid>0 && mid<n-1 && mountainArr.get(mid)>mountainArr.get(mid+1) && mountainArr.get(mid)>mountainArr.get(mid-1)){
                
                int temp = binarySearch(mountainArr,l,mid,target);
                if(temp!=-1) return temp;
                else{
                    return binarySearch2(mountainArr,mid,r,target);
                }
            }

            else{
                if(target<mountainArr.get(mid)){
                    l=mid+1;
                }
                else r=mid-1;
            }

            mid = l+(r-l)/2;
        }

        return -1;
    }
};