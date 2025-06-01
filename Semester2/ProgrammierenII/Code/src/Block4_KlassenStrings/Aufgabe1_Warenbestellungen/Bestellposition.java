package Block4_KlassenStrings.Aufgabe1_Warenbestellungen;

public class Bestellposition {
    private Ware ware;
    private int menge;

    public Bestellposition(Ware ware, int menge) {
        this.ware = ware;
        this.menge = menge;
    }

    public Ware getWare() {
        return ware;
    }

    public int getMenge() {
        return menge;
    }
}
