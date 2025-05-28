package Block4_KlassenStrings.Aufgabe1_Warenbestellungen;

import java.util.Arrays;

public class Bestellung {
    private Kunde kunde;
    private Bestellposition[] positionen;

    public Bestellung(Kunde kunde) {
        this.kunde = kunde;
        this.positionen = new Bestellposition[0];
    }

    public void nimmAuf(Bestellposition position) {
        Bestellposition[] newArray = Arrays.copyOf(this.positionen, this.positionen.length + 1);
        newArray[newArray.length - 1] = position;
        this.positionen = newArray;
    }

    public void zeigeAn() {

        if (kunde.getBekommtRabatt()) {
            System.out.printf("Bestellung von %s %s (KN %s) mit %.0f%% Kundenrabatt\n",
                    this.kunde.getVorname(),
                    this.kunde.getNachname(),
                    this.kunde.getNummer(),
                    Kundenrabatt.getRabattsatz() * 100);

            for (Bestellposition bestellposition : this.positionen) {
                System.out.printf("%s %s, " +
                                "Listenpreis: %.1f EUR, " +
                                "Kundenpreis: %.1f EUR, " +
                                "Menge: %d\n",
                        bestellposition.getWare().getNummer(), bestellposition.getWare().getBezeichnung(),
                        bestellposition.getWare().getPreis(),
                        Kundenrabatt.berechneRabattpreis(bestellposition.getWare().getPreis()),
                        bestellposition.getMenge());
            }
        } else {
            System.out.printf("Bestellung von %s %s (KN %s)\n",
                    this.kunde.getVorname(),
                    this.kunde.getNachname(),
                    this.kunde.getNummer());

            for (Bestellposition bestellposition : this.positionen) {
                System.out.printf("%s %s, " +
                                "Listenpreis: %.1f EUR, " +
                                "Menge: %d\n",
                        bestellposition.getWare().getNummer(), bestellposition.getWare().getBezeichnung(),
                        bestellposition.getWare().getPreis(),
                        bestellposition.getMenge());
            }
        }

        System.out.println();
    }
}
