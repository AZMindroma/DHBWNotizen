package Block2_Grundlagen.Aufgabe5_Temperatur;

public class Temperatur {
    private final double CONVERSION = 273.15;
    private double temperatureInKelvin;

    public Temperatur(double temperatureInKelvin) {
        this.temperatureInKelvin = temperatureInKelvin;
    }

    public double getTemperatureInKelvin() {
        return temperatureInKelvin;
    }

    public void setTemperatureInKelvin(double temperatureInKelvin) {
        this.temperatureInKelvin = temperatureInKelvin;
    }

    public double getTemperatureInCelsius() {
        return this.temperatureInKelvin - CONVERSION;
    }

    public void setTemperatureInCelsius(double temperatureInCelsius) {
        setTemperatureInKelvin(temperatureInCelsius + CONVERSION);
    }

    public double getTemperatureInFahrenheit() {
        return ((double) 9/5) * (this.temperatureInKelvin - CONVERSION) + 32;
    }

    // F = 9/5 * (K - 273.15) + 32
    // F - 32 = 9/5 * (K - 273.15)
    // (F - 32) * 5/9 = K - 273.15
    // ((F - 32) * 5/9) + 273.15 = K
    public void setTemperatureInFahrenheit(double temperatureInFahrenheit) {
        setTemperatureInKelvin( ((temperatureInFahrenheit - 32) * ((double) 5/9)) + CONVERSION );
    }

    public double getTemperatureInReaumur() {
        return ((double) 4/5) * (this.temperatureInKelvin - CONVERSION);
    }

    // R = 4/5 * (K - 273.15)
    // R * 5/4 = K - 273.15
    // (R * 5/4) + 273.15 = K
    public void setTemperatureInReaumur(double temperatureInReaumur) {
        setTemperatureInKelvin( (temperatureInReaumur * ((double) 5/4) + CONVERSION) );
    }
}
