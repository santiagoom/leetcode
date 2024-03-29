

import java.util.*;

import utils.TreeNode;
import utils.ListNode;
import utils.JavaUtils;


class Solution_135_Candy_1 {
    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        Arrays.fill(candies, 1);
        boolean hasChanged = true;
        while (hasChanged) {
            hasChanged = false;
            for (int i = 0; i < ratings.length; i++) {
                if (i != ratings.length - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    hasChanged = true;
                }
                if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    hasChanged = true;
                }
            }
        }
        int sum = 0;
        for (int candy : candies) {
            sum += candy;
        }
        return sum;
    }
}

public class _135_Candy_1 {
    public static void main(String[] args) {
        Solution_135_Candy_1 so = new Solution_135_Candy_1();


        int[] nums = {1, 0, 2};
        int sum = so.candy(nums);
        JavaUtils.print(sum);
    }
}
                                                