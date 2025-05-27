package Block3.Aufgabe2_Bruchzahlen;

public class Bruchzahl {
    private long zaehler;
    private long nenner;

    public Bruchzahl(long z, long n) {
        this.zaehler = z;
        this.nenner = n;
    }

    public String zeigeAn() {
        return String.format("(%d, %d)", this.zaehler, this.nenner);
    }

    // 1/2 + 7/9
    // 1/2 * 9/9 + 7/9 * 2/2
    // 9/18 + 14/18
    // 23/18
    public Bruchzahl addiere(Bruchzahl q) {
        long resultZaehler = this.zaehler * q.nenner + q.zaehler * this.nenner;
        long resultNenner = this.nenner * q.nenner;
        return new Bruchzahl(resultZaehler, resultNenner);
    }

    public Bruchzahl multipliziere(Bruchzahl q) {
        long resultZaehler = this.zaehler * q.zaehler;
        long resultNenner = this.nenner * q.nenner;
        return new Bruchzahl(resultZaehler, resultNenner);
    }
}
