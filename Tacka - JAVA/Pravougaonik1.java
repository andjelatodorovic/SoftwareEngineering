package danilo;

public class Pravougaonik1<T extends Number> {

	private T x, y;

	public Pravougaonik1(T x, T y) {
		this.x = x;
		this.y = y;
	}

	public T getX() {
		return x;
	}

	public void setX(T x) {
		this.x = x;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		final int prime2 = 7;
		Integer p = prime2 + prime * x.hashCode() + prime * y.hashCode();
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
		if ((x.equals(other.getX()) && y.equals(other.getY())) || (y.equals(other.getX()) && x.equals(other.getY()))) {
			return true;
		}
		return false;
	}

	@Override
	public String toString() {
		return "Pravougaonik [x=" + x + ", y=" + y + "]";
	}

	public T getY() {
		return y;
	}

	public void setY(T y) {
		this.y = y;
	}

}
