//
//
//                    import java.util.*;
//                    import utils.TreeNode;
//                    import utils.ListNode;
//                    import utils.JavaUtils;
//
//                        class Solution_271_EncodeandDecodeStrings_1{
//
//class Codec {
//  // Encodes a list of strings to a single string.
//  public String encode(List<String> strs) {
//    if (strs.size() == 0) return Character.toString((char)258);
//
//    String d = Character.toString((char)257);
//    StringBuilder sb = new StringBuilder();
//    for(String s: strs) {
//      sb.append(s);
//      sb.append(d);
//    }
//    sb.deleteCharAt(sb.length() - 1);
//    return sb.toString();
//  }
//
//  // Decodes a single string to a list of strings.
//  public List<String> decode(String s) {
//    String d = Character.toString((char)258);
//    if (s.equals(d)) return new ArrayList();
//
//    d = Character.toString((char)257);
//    return Arrays.asList(s.split(d, -1));
//  }
//}
//
//                        }
//                        public class _271_EncodeandDecodeStrings_1 {
//                            public static void main(String[] args) {
//                                Solution_271_EncodeandDecodeStrings_1 so = new Solution_271_EncodeandDecodeStrings_1();
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