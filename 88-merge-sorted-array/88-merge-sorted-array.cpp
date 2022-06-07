class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // check null cases
    if (m == 0) {
      nums1 = nums2;
      return;
    }
    if (n == 0) {
      return;
    }
    // it : i_total
    int it = m + n - 1;
    int i1 = m - 1, i2 = n - 1;
    while (!(i1 == -1 || i2 == -1)) {
      // find the max number, renew nums1 from tail to head
      if (nums1[i1] > nums2[i2]) {
        nums1[it] = nums1[i1];
        i1--;
      } else {
        nums1[it] = nums2[i2];
        i2--;
      }
      it--;
    }
    // if nums2 not complete
    if (i1 == -1) {
      for (int i = 0; i < i2 + 1; i++) {
        nums1[i] = nums2[i];
      }
    }
  }
};