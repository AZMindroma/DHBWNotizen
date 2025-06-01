package Block4_KlassenStrings.Aufgabe4_BruchzahlenModded;

public class Algorithmen {
    public static long ggT(long a, long b) {
        if (a < 0) {
            a *= -1;
        }
        if (b < 0) {
            b *= -1;
        }

        if (a % b == 0) {
            return b;
        } else {
            long rest = a % b;
            a = b;
            b = rest;
            return ggT(a, b);
        }
    }
}
