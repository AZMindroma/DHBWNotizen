package Block4_KlassenStrings.Aufgabe1_Warenbestellungen;

public class Kundenrabatt {
    private static double rabattsatz = 0.05;

    public static double getRabattsatz() {
        return rabattsatz;
    }

    public static void setRabattsatz(double rabattsatz) {
        Kundenrabatt.rabattsatz = rabattsatz;
    }

    public static double berechneRabattpreis(double vollerPreis) {
        return vollerPreis - (vollerPreis * rabattsatz);
    }
}
