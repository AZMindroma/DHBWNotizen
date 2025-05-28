package Block2_Grundlagen.Aufgabe5_Temperatur;

public class Execution {
    public static void printTemperature(Temperatur temp1) {
        System.out.printf("Temperatur: \nIn Kelvin: %f \nIn Celsius: %f \nIn Fahrenheit: %f \nIn Reaumur: %f\n\n", temp1.getTemperatureInKelvin(), temp1.getTemperatureInCelsius(), temp1.getTemperatureInFahrenheit(), temp1.getTemperatureInReaumur());
    }

    public static void main(String[] args) {
        Temperatur temp1 = new Temperatur(300);
        printTemperature(temp1);

        temp1.setTemperatureInCelsius(25);
        printTemperature(temp1);

        temp1.setTemperatureInFahrenheit(100);
        printTemperature(temp1);

        temp1.setTemperatureInReaumur(40);
        printTemperature(temp1);
    }
}
