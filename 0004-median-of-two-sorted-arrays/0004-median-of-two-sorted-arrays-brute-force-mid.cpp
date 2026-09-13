class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        int count = 0;

        int i = 0;
        int j = 0;

        int mid1 = -1;
        int mid2 = -1;

        while(i < n1 && j < n2) {

            int value;

            if(nums1[i] < nums2[j]) {
                value = nums1[i];
                i++;
            }
            else {
                value = nums2[j];
                j++;
            }

            if(count == n/2 - 1) {
                mid1 = value;
            }

            if(count == n/2) {
                mid2 = value;
            }

            count++;
        }

        while(i < n1) {

            int value = nums1[i];
            i++;

            if(count == n/2 - 1) {
                mid1 = value;
            }

            if(count == n/2) {
                mid2 = value;
            }

            count++;
        }

        while(j < n2) {

            int value = nums2[j];
            j++;

            if(count == n/2 - 1) {
                mid1 = value;
            }

            if(count == n/2) {
                mid2 = value;
            }

            count++;
        }

        if(n % 2 == 1) {
            return mid2;
        }

        return (mid1 + mid2) / 2.0;
    }
};