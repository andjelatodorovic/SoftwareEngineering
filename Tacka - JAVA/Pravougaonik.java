package danilo;

public class Pravougaonik<T extends Number> {

	private Tacka<T> x, y;

	public Pravougaonik(Tacka<T> x, Tacka<T> y) {
		this.x = x;
		this.y = y;
	}

	public Tacka<T> getX() {
		return x;
	}

	public void setX(Tacka<T> x) {
		this.x = x;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		Double p = x.getMera() + y.getMera();
		return p.hashCode();
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Pravougaonik other = (Pravougaonik) obj;
		if((x.equals(other.getX()) && y.equals(other.getY())) || (y.equals(other.getX()) && x.equals(other.getY()))){
			return true;
		}
		return false;
	}

	@Override
	public String toString() {
		return "Pravougaonik [x=" + x + ", y=" + y + "]";
	}

	public Tacka<T> getY() {
		return y;
	}

	public void setY(Tacka<T> y) {
		this.y = y;
	}
	
	
	
}
