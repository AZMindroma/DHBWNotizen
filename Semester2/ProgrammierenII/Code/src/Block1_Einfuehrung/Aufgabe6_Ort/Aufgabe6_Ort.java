package Block1_Einfuehrung.Aufgabe6_Ort;

public class Aufgabe6_Ort {
    public static void main(String[] args) {
        Ort ort1 = new Ort("Entenhausen", "Große Kreisstadt", 55000);
        Ort ort2 = new Ort("zum Erpel", "Weiler", 100);

        System.out.printf("%s %s mit %d Einwohnern", ort1.getKategorie(), ort1.getName(), ort1.getEinwohnerzahl());
        System.out.println(); // new line
        System.out.printf("%s %s mit %d Einwohnern", ort2.getKategorie(), ort2.getName(), ort2.getEinwohnerzahl());
    }
}

