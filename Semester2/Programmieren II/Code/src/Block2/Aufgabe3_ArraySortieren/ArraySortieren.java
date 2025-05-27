package Block2.Aufgabe3_ArraySortieren;
import java.util.Arrays;

public class ArraySortieren {
    private final int[] array;

    public ArraySortieren(int[] array) {
        this.array = array;
    }

    public int[] getArray() {
        return array;
    }

    public int[] getSortedArray() {
        Arrays.sort(array);
        return array;
    }
}
