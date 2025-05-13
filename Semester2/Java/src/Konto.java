public class Konto {
	private String nummer;
	private double zinssatz;
	private int stand;

	public Konto(String n, double z, int s) {
		nummer = n;
		zinssatz = z;
		stand = s;
	}

	public String getNummer() {
		return nummer;
	}

	public int getStand() {
		return stand;
	}
}
