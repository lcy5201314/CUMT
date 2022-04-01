class A {
    public String Show(D obj) {	return ("A and D");	}
    public String Show(A obj) {	return ("A and A");	}
}
class B extends A {
    public String Show(B obj) {	return ("B and B");	}
    public String Show(A obj) {	return ("B and A");	}
}
class C extends B {
    public String Show(C obj) {	return ("C and C");	}
    public String Show(B obj) {	return ("C and B");	}
}
class D extends B {
    public String Show(D obj) {	return ("D and D");	}
    public String Show(B obj) {	return ("D and B");	}
}

public class mainTest {
    public static void main(String args[]){
        A a1 = new A();
        A a2 = new B();
        B b = new B();
        C c = new C();
        D d = new D();
        System.out.println(a1.Show(b));
        System.out.println(a1.Show(c));
        System.out.println(a1.Show(d));
        System.out.println(a2.Show(b));
        System.out.println(a2.Show(c));
        System.out.println(a2.Show(d));
        System.out.println(b.Show(b));
        System.out.println(b.Show(c));
        System.out.println(b.Show(d));
    }
}