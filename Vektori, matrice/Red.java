import java.util.NoSuchElementException;
import java.util.Stack;

public class Red {

	private Stack<Integer> s1, s2;
	
	public Red() {
		this.s1 = new Stack<>();
		this.s2 = new Stack<>();
	}
	
	public void push(int val) {
		s1.push(val);
	}
	
	public int pop() {
		if(empty())
			throw new NoSuchElementException("Red je prazan");
		
		while(!s1.empty()) {
			s2.push(s1.pop());
		}
		int val = s2.peek();
		s2.pop();
		
		while(!s2.empty()) {
			s1.push(s2.pop());
		}
		
		return val;
	}
	
	public boolean empty() {
		return s1.empty();
	}
	
}