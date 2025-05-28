package Block4_KlassenStrings.Aufgabe1_Warenbestellungen;

public class Execution {
    public static void main(String[] args) {
        System.out.println("Zentral gesetzter Rabattsatz: " + Kundenrabatt.getRabattsatz() + "\n");

        Kunde dagobertDuck = new Kunde("Dagobert", "Duck", "000351");
        dagobertDuck.setBekommtRabatt(false);

        Bestellung bestDagobert = new Bestellung(dagobertDuck);
        Bestellposition posDagobert;
        Ware wDagobert;

        wDagobert = new Ware("01019010", "Hammer", 19.00);
        posDagobert = new Bestellposition(wDagobert, 30);
        bestDagobert.nimmAuf(posDagobert);

        wDagobert = new Ware("01019020", "Zange", 17.00);
        posDagobert = new Bestellposition(wDagobert, 20);
        bestDagobert.nimmAuf(posDagobert);

        wDagobert = new Ware("01019030", "Schraubendreher", 12.00);
        posDagobert = new Bestellposition(wDagobert, 25);
        bestDagobert.nimmAuf(posDagobert);

        bestDagobert.zeigeAn();

        Kunde emilErpel = new Kunde("Emil", "Erpel", "000462");
        emilErpel.setBekommtRabatt(true);

        Bestellung bestEmil = new Bestellung(emilErpel);
        Bestellposition posEmil;
        Ware wEmil;

        wEmil = new Ware("03073073", "Reifen", 33.00);
        posEmil = new Bestellposition(wEmil, 15);
        bestEmil.nimmAuf(posEmil);

        wEmil = new Ware("03073074", "Schlauch", 8.00);
        posEmil = new Bestellposition(wEmil, 16);
        bestEmil.nimmAuf(posEmil);

        wEmil = new Ware("03073103", "Luftpumpe", 13.00);
        posEmil = new Bestellposition(wEmil, 5);
        bestEmil.nimmAuf(posEmil);

        bestEmil.zeigeAn();

        System.out.println("Es wird ein neuer Rabattsatz gesetzt...");
        Kundenrabatt.setRabattsatz(0.07);
        System.out.println("Zentral gesetzter Rabattsatz: " + Kundenrabatt.getRabattsatz() + "\n");

        Kunde daisyDuck = new Kunde("Daisy", "Duck", "000573");
        daisyDuck.setBekommtRabatt(true);

        Bestellung bestDaisy = new Bestellung(daisyDuck);
        Bestellposition posDaisy;
        Ware wDaisy;

        wDaisy = new Ware("02042051", "Rock", 133.00);
        posDaisy = new Bestellposition(wDaisy, 5);
        bestDaisy.nimmAuf(posDaisy);

        wDaisy = new Ware("02042061", "Bluse", 83.00);
        posDaisy = new Bestellposition(wDaisy, 4);
        bestDaisy.nimmAuf(posDaisy);

        wDaisy = new Ware("02042071", "Bustier", 112.00);
        posDaisy = new Bestellposition(wDaisy, 3);
        bestDaisy.nimmAuf(posDaisy);

        bestDaisy.zeigeAn();
    }
}
