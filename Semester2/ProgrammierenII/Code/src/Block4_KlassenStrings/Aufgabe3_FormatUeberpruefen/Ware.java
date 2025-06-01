package Block4_KlassenStrings.Aufgabe3_FormatUeberpruefen;
import java.util.regex.*;

public class Ware {
    private String warennummer;
    private String bezeichnung;
    private double preis;

    public Ware(String warennummer, String bezeichnung, double preis) {
        this.warennummer = warennummer;
        this.bezeichnung = bezeichnung;
        this.preis = preis;
    }

    public String getWarennummer() {
        return warennummer;
    }

    public String getNormalisierteWarennummer() {
        if (warennummer.matches("DE-[0-9]{4}-[0-9]{4}")) {
            return warennummer;
        } else {
            Pattern format = Pattern.compile("([0-9]{4})([0-9]{4})");
            Matcher m = format.matcher(warennummer);

            if (m.matches()) {
                String firstPart = m.group(1);
                String secondPart = m.group(2);

                return "DE-" + firstPart + "-" + secondPart;
            } else {
                return "INVALID NUMBER";
            }
        }
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
