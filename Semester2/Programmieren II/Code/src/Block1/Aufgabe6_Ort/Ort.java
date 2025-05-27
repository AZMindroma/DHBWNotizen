package Block1.Aufgabe6_Ort;

public class Ort {
    private String name;
    private String kategorie;
    private int einwohnerzahl;

    public Ort(String n, String k, int e) {
        name = n;
        kategorie = k;
        einwohnerzahl = e;
    }

    public String getName() {
        return name;
    }

    public String getKategorie() {
        return kategorie;
    }

    public int getEinwohnerzahl() {
        return einwohnerzahl;
    }

    public void setName(String setName) {
        name = setName;
    }

    public void setKategorie(String setKategorie) {
        kategorie = setKategorie;
    }

    public void setEinwohnerzahl(int einwohner) {
        einwohnerzahl = einwohner;
    }
}
