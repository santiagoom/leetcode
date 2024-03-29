

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            
                        class Solution_232_ImplementQueueusingStacks_1{
                        
class MyQueue {

    public MyQueue() {
        
    }
    
private int front;
private Stack<Integer> s1 = new Stack<>();
private Stack<Integer> s2 = new Stack<>();
public void push(int x) {
    if (s1.empty())
        front = x;
    while (!s1.isEmpty())
        s2.push(s1.pop());
    s2.push(x);
    while (!s2.isEmpty())
        s1.push(s2.pop());
}
    
public int pop() {
    int res = s1.pop();
    if (!s1.empty())
        front = s1.peek();
    return res;
}
    
// Get the front element.
public int peek() {
  return front;
}
    
// Return whether the queue is empty.
public boolean empty() {
    return s1.isEmpty();
}
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */

                        }
                        public class _232_ImplementQueueusingStacks_1 {
                            public static void main(String[] args) {
                                Solution_232_ImplementQueueusingStacks_1 so = new Solution_232_ImplementQueueusingStacks_1();
                                 int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                            }
                        }
                        