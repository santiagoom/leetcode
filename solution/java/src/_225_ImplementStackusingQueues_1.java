

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            
                        class Solution_225_ImplementStackusingQueues_1{
                        
class MyStack {
private LinkedList<Integer> q1 = new LinkedList<>();

// Push element x onto stack.
public void push(int x) {
    q1.add(x);
    int sz = q1.size();
    while (sz > 1) {
        q1.add(q1.remove());
        sz--;
    }
}
    public MyStack() {
        
    }
    

    // Removes the element on top of the stack.
    public int pop() {
        
        return q1.remove();
        
    }
    
// Get the top element.
public int top() {
    return q1.peek();
}
// Return whether the stack is empty.
public boolean empty() {
    return q1.isEmpty();
}
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */

                        }
                        public class _225_ImplementStackusingQueues_1 {
                            public static void main(String[] args) {
                                Solution_225_ImplementStackusingQueues_1 so = new Solution_225_ImplementStackusingQueues_1();
                                 int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                            }
                        }
                        