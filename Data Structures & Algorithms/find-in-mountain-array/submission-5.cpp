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
    int findPeak(MountainArray &mountainArr, int len){
        if(len==1) return 0;

        if(len==2){
            if(mountainArr.get(0)>mountainArr.get(1)) return 0;
            else return 1;
        }

        int l=0, r=len-1;
        int mid = l+(r-l)/2;
        while(l<=r){

            int nextVal, prevVal;
            int midVal = mountainArr.get(mid);
            if(mid<len-1) nextVal=mountainArr.get(mid+1); 
            if(mid>0) prevVal=mountainArr.get(mid-1);
            
            if(mid==0){
                if(mountainArr.get(mid)>mountainArr.get(mid+1)) return mid;
                else l=mid+1; 
            }

            else if(mid==len-1){
                if(mountainArr.get(mid)>mountainArr.get(mid-1)) return mid;
                else r=mid-1;
            }

            else if(midVal>nextVal && midVal>prevVal) return mid;

            else if(midVal<nextVal && midVal>prevVal){
                l=mid+1;
            }

            else r=mid-1;

            mid= l+(r-l)/2;   
        }

        return 0;
    }

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
        int len = mountainArr.length();
        int l=0, r=len-1;
        int peak = findPeak(mountainArr, len);
        int temp = binarySearch(mountainArr,l,peak,target);
        if(temp!=-1) return temp;
        else return binarySearch2(mountainArr,peak,r,target);
    }
};