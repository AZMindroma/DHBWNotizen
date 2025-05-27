package Block3.Aufgabe1_Warenbestellungen;
import java.util.Arrays;

public class Bestellung {
    private Bestellposition[] positionen;

    public Bestellung() {
        this.positionen = new Bestellposition[0];
    }

    public void nimmAuf(Bestellposition position) {
        Bestellposition[] newArray = Arrays.copyOf(this.positionen, this.positionen.length + 1);
        newArray[newArray.length - 1] = position;
        this.positionen = newArray;
    }

    public void zeigeAn() {
        for (int i = 0; i < this.positionen.length; i++) {
            System.out.printf("%s %s, Preis: %.1f EUR, Menge: %d\n", this.positionen[i].getWare().getNummer(), this.positionen[i].getWare().getBezeichnung(), this.positionen[i].getWare().getPreis(), this.positionen[i].getMenge());
        }
    }
}
