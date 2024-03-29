package utils;

public class JavaUtils {
    public static void print_1d_array(int[] array) {
        for (int num : array) {
            System.out.print(num);
            System.out.print(", ");
        }
        System.out.println();
    }

    public static void print_2d_array(int[][] arrays) {
        for (int[] array : arrays) {
            print_1d_array(array);
        }
    }

    public static void print(int n) {
        System.out.println(n);
    }

    public static void print(boolean n) {
        System.out.println(n);
    }

    public static void print(String s) {
        System.out.println(s);
    }


//    int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//        JavaUtils.print_1d_array(nums);
//    int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
//        JavaUtils.print_2d_array(arrays);
//
//    int target = 26;
//    String s = "aa";
}
