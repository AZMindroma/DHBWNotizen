package Block4_KlassenStrings.Aufgabe1_Warenbestellungen;

public class Ware {
    private String nummer;
    private String bezeichnung;
    private double preis;

    public Ware(String nummer, String bezeichnung, double preis) {
        this.nummer = nummer;
        this.bezeichnung = bezeichnung;
        this.preis = preis;
    }

    public String getNummer() {
        return nummer;
    }

    public String getBezeichnung() {
        return bezeichnung;
    }

    public double getPreis() {
        return preis;
    }

    public void setPreis(double preis) {
        this.preis = preis;
    }
}
