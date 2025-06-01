package Block3_KlassenObjekte.Aufgabe1_Warenbestellungen;

public class Execution {
    public static void main(String[] args) {
        Bestellung best = new Bestellung();
        Bestellposition pos;
        Ware w;

        w = new Ware("01019010", "Hammer", 19.00);
        pos = new Bestellposition(w, 30);
        best.nimmAuf(pos);

        w = new Ware("01019020", "Zange", 17.00);
        pos = new Bestellposition(w, 20);
        best.nimmAuf(pos);

        w = new Ware("01019030", "Schraubendreher", 12.00);
        pos = new Bestellposition(w, 25);
        best.nimmAuf(pos);

        w = new Ware("03073073", "Reifen", 33.00);
        pos = new Bestellposition(w, 15);
        best.nimmAuf(pos);

        w = new Ware("03073074", "Schlauch", 8.00);
        pos = new Bestellposition(w, 16);
        best.nimmAuf(pos);

        w = new Ware("03073103", "Luftpumpe", 13.00);
        pos = new Bestellposition(w, 5);
        best.nimmAuf(pos);

        best.zeigeAn();
    }
}
