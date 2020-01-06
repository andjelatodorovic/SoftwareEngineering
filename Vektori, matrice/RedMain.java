package danilo;

import java.util.Random;

public class Main {

	public static void main(String[] args) {

		Red red = new Red();
		Random random = new Random();
		
		for(int i = 0; i < 10; i++) {
			int p = random.nextInt(100);
			System.out.print(p + " ");
			red.push(p);
		}
		System.out.println();
		
		while(!red.empty()) {
			System.out.print(red.pop() + " ");
		}
		
	}

}