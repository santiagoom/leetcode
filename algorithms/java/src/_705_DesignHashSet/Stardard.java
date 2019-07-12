package _705_DesignHashSet;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Stardard {
    public static void main(String[] args) {


        int[] add = {30, 8, 79, 78, 81, 73, 99, 64, 77, 64, 57, 55, 27, 68, 70, 45, 54, 1, 84, 39, 19, 59, 38, 16, 51, 7,
                10, 46, 33, 89, 18, 89, 68, 25, 12, 48, 61, 93, 41, 57, 34, 29, 63, 65, 98, 73, 88, 24, 74, 38};

        int[] rv = {9, 53, 5, 81, 84, 33, 24, 62, 55, 23, 10, 63, 98, 15, 36, 69, 30, 35, 26, 53, 81, 42, 98, 45, 43, 78,
                19, 42, 74, 77};

        int[] contain = {87, 71, 85, 60, 72, 78, 1, 29, 83, 95, 57, 70, 70, 71, 43, 76, 47, 75, 77, 93, 79, 42, 16, 71, 48,
                3, 61, 71, 76, 49};

        Set<Integer> set = new HashSet<Integer>();
        System.out.println(set);
        System.out.println(set.size());

        for (int i = 0; i < add.length; i++) {
            set.add(add[i]);
        }
        System.out.println(set);
        System.out.println(set.size());

        for (int i = 0; i < rv.length; i++) {
            set.remove(rv[i]);
        }
        for (int i = 0; i < contain.length; i++) {
            if(set.contains(contain[i]))
                System.out.println(contain[i]);
        }


//        System.out.println(set);
//        System.out.println(set.size());


    }
}
