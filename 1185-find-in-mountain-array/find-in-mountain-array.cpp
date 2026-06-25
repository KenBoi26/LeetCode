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
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length()-1;
        int pivot = 0;

        while(left < right){
            int mid = left+(right-left)/2;

            if(mountainArr.get(mid) >= mountainArr.get(mid+1)){
                right = mid;
            }else{
                left = mid+1;
            }
        }

        pivot = left;

        left = 0;
        right = pivot;

        while(left <= right){
            int mid = left+(right-left)/2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }


        left = pivot+1;
        right = mountainArr.length()-1;

        while(left <= right){
            int mid = left+(right-left)/2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        return -1;
    }
};