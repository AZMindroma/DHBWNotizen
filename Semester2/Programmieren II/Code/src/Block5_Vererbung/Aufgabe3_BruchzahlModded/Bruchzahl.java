package Block5_Vererbung.Aufgabe3_BruchzahlModded;

public class Bruchzahl {
    private long zaehler;
    private long nenner;

    public Bruchzahl(long z, long n) {
        this.zaehler = z;
        this.nenner = n;
        normiere();
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

    private Bruchzahl bildeGegenwert() {
        return new Bruchzahl(this.zaehler*-1, this.nenner);
    }

    private Bruchzahl bildeKehrwert() {
        return new Bruchzahl(this.nenner, this.zaehler);
    }

    public Bruchzahl subtrahiere(Bruchzahl q) {
        Bruchzahl result = q.bildeGegenwert().addiere(this);
        return new Bruchzahl(result.zaehler, result.nenner);
    }

    public Bruchzahl dividiere(Bruchzahl q) {
        Bruchzahl result = q.bildeKehrwert().multipliziere(this);
        return new Bruchzahl(result.zaehler, result.nenner);
    }

    private Bruchzahl normiere() {
        if (this.nenner < 0) {
            this.zaehler *= -1;
            this.nenner *= -1;
        }
        if (!(this.zaehler == 0 && this.nenner == 0)) {
            if (this.zaehler == 0) {
                this.nenner = 0;
            }
            if (this.nenner == 0) {
                this.zaehler = 0;
            }
        }
        kuerze();
        return Bruchzahl.this;
    }

    private void kuerze() {
        long ggt = Algorithmen.ggT(this.zaehler, this.nenner);
        this.zaehler /= ggt;
        this.nenner /= ggt;
    }
}
