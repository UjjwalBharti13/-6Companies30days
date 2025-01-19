/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
     // Approach first we find peak element anf then apply binary search from asssending part and then descemding part after thatwe will get answer
class Solution {
public:
    int findPeak(MountainArray &arr) {
        int lo = 0;
        int hi = arr.length() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int midVal = arr.get(mid);
            int midNextVal = arr.get(mid + 1);

            if (midVal < midNextVal) {
                lo = mid + 1; // Peak is on the right
            } else {
                hi = mid; // Peak is on the left or at mid
            }
        }
        return lo; // Peak index
    }

    int binarySearch(MountainArray &arr, int target, int lo, int hi, bool ascending) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int midVal = arr.get(mid);

            if (midVal == target) return mid;
            if (ascending) {
                if (midVal < target) lo = mid + 1;
                else hi = mid - 1;
            } else {
                if (midVal > target) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &arr) {
        int peakIdx = findPeak(arr);

        // Binary search in ascending part
        int res = binarySearch(arr, target, 0, peakIdx, true);
        if (res != -1) return res;

        // Binary search in descending part
        return binarySearch(arr, target, peakIdx + 1, arr.length() - 1, false);
    }
};
