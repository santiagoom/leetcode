package _000_topics.merge._486_MergeKSortedArrays;

public class _486_MergeKSortedArrays_std {
    public static void main(String[] args) {
        _486_MergeKSortedArrays_std_ so = new _486_MergeKSortedArrays_std_();

    }
}

class _486_MergeKSortedArrays_std_ {

}

class Solution {
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    public int[] mergekSortedArrays(int[][] arrays) {
        // write your code here
        if (arrays == null || arrays.length == 0) {
            return new int[0];
        }
        return merge(arrays, 0, arrays.length - 1);
    }

    public int[] merge(int[][] arrays, int start, int end) {
        if (start >= end) {
            return arrays[start];
        }
        int mid = start + (end - start) / 2;

        int[] left = merge(arrays, start, mid);
        int[] right = merge(arrays, mid + 1, end);

        return mergeHelper(left, right);
    }

    public int[] mergeHelper(int[] left, int[] right) {
        int len1 = left.length;
        int len2 = right.length;

        int[] result = new int[len1 + len2];

        int i = 0;
        int j = 0;
        int index = 0;

        while (i < len1 && j < len2) {

            if (left[i] < right[j]) {
                result[index++] = left[i++];
            } else {
                result[index++] = right[j++];
            }
        }

        while (i < len1) {
            result[index++] = left[i++];
        }
        while (j < len2) {
            result[index++] = right[j++];
        }
        return result;
    }
}