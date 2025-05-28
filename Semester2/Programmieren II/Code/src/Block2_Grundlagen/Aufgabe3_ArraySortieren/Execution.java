package Block2_Grundlagen.Aufgabe3_ArraySortieren;

import java.util.Arrays;

public class Execution {
    public static void main(String[] args) {
        ArraySortieren array = new ArraySortieren(new int[]{4, 8, 19, 2, 1, 45});

        System.out.println(Arrays.toString(array.getSortedArray()));
    }
}
