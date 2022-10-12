
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_243_ShortestWordDistance_1 {
    public int shortestDistance(String[] words, String word1, String word2) {
        int minDistance = words.length;
        for (int i = 0; i < words.length; i++) {
            if (words[i].equals(word1)) {
                for (int j = 0; j < words.length; j++) {
                    if (words[j].equals(word2)) {
                        minDistance = Math.min(minDistance, Math.abs(i - j));
                    }
                }
            }
        }
        return minDistance;
    }
}

                                                public class _243_ShortestWordDistance_1 {
                                                    public static void main(String[] args) {
                                                        Solution_243_ShortestWordDistance_1 so = new Solution_243_ShortestWordDistance_1();
                                                    }
                                                }
                                                