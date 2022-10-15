//
//
//                    import java.util.*;
//                    import utils.TreeNode;
//                    import utils.ListNode;
//                    import utils.JavaUtils;
//
//                        class Solution_014_LongestCommonPrefix_5{
//
//public String longestCommonPrefix(String q, String[] strs) {
//    if (strs == null || strs.length == 0)
//         return "";
//    if (strs.length == 1)
//         return strs[0];
//    Trie trie = new Trie();
//    for (int i = 1; i < strs.length ; i++) {
//        trie.insert(strs[i]);
//    }
//    return trie.searchLongestPrefix(q);
//}
//
//class TrieNode {
//
//    // R links to node children
//    private TrieNode[] links;
//
//    private final int R = 26;
//
//    private boolean isEnd;
//
//    // number of children non null links
//    private int size;
//    public void put(char ch, TrieNode node) {
//        links[ch -'a'] = node;
//        size++;
//    }
//
//    public int getLinks() {
//        return size;
//    }
//    //assume methods containsKey, isEnd, get, put are implemented as it is described
//   //in  https://leetcode.com/articles/implement-trie-prefix-tree/)
//}
//
//class Trie {
//
//    private TrieNode root;
//
//    public Trie() {
//        root = new TrieNode();
//    }
//
////assume methods insert, search, searchPrefix are implemented as it is described
////in  https://leetcode.com/articles/implement-trie-prefix-tree/)
//    private String searchLongestPrefix(String word) {
//        TrieNode node = root;
//        StringBuilder prefix = new StringBuilder();
//        for (int i = 0; i < word.length(); i++) {
//            char curLetter = word.charAt(i);
//            if (node.containsKey(curLetter) && (node.getLinks() == 1) && (!node.isEnd())) {
//                prefix.append(curLetter);
//                node = node.get(curLetter);
//            }
//            else
//                return prefix.toString();
//
//         }
//         return prefix.toString();
//    }
//}
//
//                        }
//                        public class _014_LongestCommonPrefix_5 {
//                            public static void main(String[] args) {
//                                Solution_014_LongestCommonPrefix_5 so = new Solution_014_LongestCommonPrefix_5();
//                                 int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//                                                        JavaUtils.print_1d_array(nums);
//                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
//                                                        JavaUtils.print_2d_array(arrays);
//
//                                                        int target = 26;
//                                                        String s = "aa";
//                            }
//                        }
//