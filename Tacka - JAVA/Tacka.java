package danilo;

public class Tacka<T extends Number> implements IMera {

	private T x, y;

	public Tacka(T x, T y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public double getMera() {
		double px = x.doubleValue();
		double py = y.doubleValue();
		return Math.sqrt(px * px + py * py);
	}

	@Override
	public int hashCode() {
		Double p = getMera();
		return p.hashCode();
	}

	@Override
	public String toString() {
		return "Tacka [x=" + x + ", y=" + y + "]";
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		@SuppressWarnings("rawtypes")
		Tacka other = (Tacka) obj;
		if (x == null) {
			if (other.x != null)
				return false;
		}

		if (y == null) {
			if (other.y != null)
				return false;
		}
		if (getMera() != other.getMera()) {
			return false;
		}
		return true;
	}

	public T getX() {
		return x;
	}

	public void setX(T x) {
		this.x = x;
	}

	public T getY() {
		return y;
	}

	public void setY(T y) {
		this.y = y;
	}

}
