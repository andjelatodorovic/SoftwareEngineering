package danilo;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map.Entry;
import java.util.Random;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		// zad8();
		zad9();

	}

	public static void zad8() {

		ArrayList<Tacka<Integer>> lista = new ArrayList<>();
		Random random = new Random();

		System.out.println("ArrayList: ");
		for (int i = 0; i < 10; ++i) {
			int x = random.nextInt(5);
			int y = random.nextInt(5);
			lista.add(new Tacka<Integer>(x, y));
			System.out.print("\t(" + x + "," + y + "); ");
		}
		System.out.println();

		HashMap<Double, Tacka<Integer>> mapa = new HashMap<>();

		Iterator<Tacka<Integer>> it1 = lista.iterator();
		while (it1.hasNext()) {
			Tacka<Integer> t = it1.next();
			mapa.put(t.getMera(), t);
		}

		System.out.println("HashMap: ");
		Iterator<Entry<Double, Tacka<Integer>>> it2 = mapa.entrySet().iterator();
		while (it2.hasNext()) {
			Entry<Double, Tacka<Integer>> entry = it2.next();

			DecimalFormat df = new DecimalFormat();
			df.setMaximumFractionDigits(2);
			df.setMinimumFractionDigits(2);

			Tacka<Integer> t = entry.getValue();
			double mera = entry.getKey();

			System.out.println("\t(" + df.format(mera) + ", Tacka(" + t.getX() + "," + t.getY() + "));");
		}
		System.out.println();

	}

	public static void zad9() {

		try (Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("in.txt")))) {

			HashSet<Pravougaonik<Integer>> set = new HashSet<>();
			boolean ok = true;

			while (ok && scanner.hasNext()) {
				for (int i = 0; i < 10; ++i) {
					int x1 = scanner.nextInt();
					int y1 = scanner.nextInt();
					int x2 = scanner.nextInt();
					int y2 = scanner.nextInt();

					Tacka<Integer> t1 = new Tacka<Integer>(x1, y1);
					Tacka<Integer> t2 = new Tacka<Integer>(x2, y2);

					Pravougaonik<Integer> p = new Pravougaonik<>(t1, t2);
					System.out.println(p);

					if (set.contains(p)) {
						ok = false;
					} else {
						set.add(p);
					}
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

	public static void zad10() {
		try (Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("in.txt")))) {

			HashSet<Pravougaonik1<Integer>> set = new HashSet<>();
			boolean ok = true;

			int n = scanner.nextInt();

			for (int i = 0; i < n; ++i) {
				int x1 = scanner.nextInt();
				int x2 = scanner.nextInt();

				Integer t1 = new Integer(x1);
				Integer t2 = new Integer(x2);

				Pravougaonik1<Integer> p = new Pravougaonik1<>(t1, t2);
				System.out.println(p);

				if (set.contains(p)) {
					break;
				} else {
					set.add(p);
				}
			}

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
