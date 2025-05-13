public class KontoTest {
	public static void main(String[] args) {
		Konto k1 = new Konto("0815-2204", 0.01, 50000);

		System.out.print("Das Konto mit der Nummer ");
		System.out.print(k1.getNummer());
		System.out.print(" hat den Stand ");
		System.out.print(k1.getStand());
		System.out.println(" Cent");

		Konto k2 = new Konto("3456-1101", 0.005, 9873518);
		
		System.out.print("Das Konto mit der Nummer ");
		System.out.print(k2.getNummer());
		System.out.print(" hat den Stand ");
		System.out.print(k2.getStand());
		System.out.println(" Cent");
	}
}
