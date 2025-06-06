package Block4_KlassenStrings.Aufgabe2_AnpassungAusgabe;

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
            System.out.printf("Bestellung von %s %s (KN %s) mit %.0f%% Kundenrabatt\n%15s %15s %15s %15s %15s\n",
                    this.kunde.getVorname(),
                    this.kunde.getNachname(),
                    this.kunde.getNummer(),
                    Kundenrabatt.getRabattsatz() * 100,
                    "Nummer", "Bezeichnung", "Listenpreis", "Kundenpreis", "Menge");

            for (Bestellposition bestellposition : this.positionen) {
                System.out.printf("%15s %15s %15.2f %15.2f %15d\n",
                        bestellposition.getWare().getNummer(), bestellposition.getWare().getBezeichnung(), bestellposition.getWare().getPreis(), Kundenrabatt.berechneRabattpreis(bestellposition.getWare().getPreis()), bestellposition.getMenge()
                );
            }
        } else {
            System.out.printf("Bestellung von %s %s (KN %s)\n%15s %15s %15s %15s\n",
                    this.kunde.getVorname(),
                    this.kunde.getNachname(),
                    this.kunde.getNummer(),
                    "Nummer", "Bezeichnung", "Listenpreis", "Menge");

            for (Bestellposition bestellposition : this.positionen) {
                System.out.printf("%15s %15s %15.2f %15d\n",
                        bestellposition.getWare().getNummer(), bestellposition.getWare().getBezeichnung(), bestellposition.getWare().getPreis(), bestellposition.getMenge()
                );
            }
        }

        System.out.println();
    }
}
