package _170_TwoSumIII_DataStructureDesign;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class _170_TwoSumIII_DataStructureDesign {
    public static void main(String[] args) {
//        TwoSum so = new TwoSum();
        TwoSum_1 so = new TwoSum_1();

        int[] add = {15, 19, 14, 18, 16, 16, 14, 13, 16, 11, 17, 10, 17, 14, 18, 17, 11, 12, 11, 14,};
        int[] find = {17, 41, 40, 25, 41, 17, 19, 38, 45, 44, 23, 13, 44, 29, 47, 45, 18, 38, 11, 34,};

        for (int a : add)
            so.add(a);

        for (int f : find)
            System.out.println(so.find(f));


    }
}


class TwoSum {
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();

    public void add(int number) {
        if (map.containsKey(number)) {
            map.put(number, map.get(number) + 1);
        } else {
            map.put(number, 1);
        }
    }

    public boolean find(int value) {
        for (int key : map.keySet()) {
            int another = value - key;
            if (another == key && map.get(key) > 1) {
                return true;
            } else if (another != key && map.containsKey(another)) {
                return true;
            }
        }
        return false;
    }
}

class TwoSum_1 {
    /*
    self
     */
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();

    public void add(int number) {
        if (map.containsKey(number)) {
            map.put(number, map.get(number) + 1);
        } else {
            map.put(number, 1);
        }
    }

    public boolean find(int value) {
        for (int number : map.keySet()) {
            if ((value / number == 2) && (map.get(number) > 1)) {
                return true;
            } else if (map.containsKey(value - number)) {
                return true;
            }
        }
        return false;
    }
}

class TwoSum_2 {
    private List<Integer> ls;
    private Map<Integer, Integer> hm = null;
    private int count = 0;

    public TwoSum_2() {
        ls = new ArrayList<Integer>();
        hm = new HashMap<Integer, Integer>();
    }

    // Add the number to an internal data structure.
    public void add(int number) {
        // Write your code here
        ls.add(number);
        hm.put(number, count++);
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    public boolean find(int value) {
        // Write your code here
        for (int i = 0; i < ls.size(); i++) {
            Integer val = value - ls.get(i);
            if (hm.containsKey(val) && hm.get(val) != i) {
                return true;
            }
        }
        return false;
    }
}