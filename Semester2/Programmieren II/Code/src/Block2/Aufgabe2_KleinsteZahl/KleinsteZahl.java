package Block2.Aufgabe2_KleinsteZahl;

public class KleinsteZahl {
    public final int[] array;

    public KleinsteZahl(int[] array) {
        this.array = array;
    }

    public int[] getArray() {
        return array;
    }

    public int getSmallestNumber() {
        int smallestNumber = array[0];

        for (int i = 1; i < array.length-1; i++) {
            if (array[i] < smallestNumber) {
                smallestNumber = array[i];
            }
        }

        return smallestNumber;
    }
}
