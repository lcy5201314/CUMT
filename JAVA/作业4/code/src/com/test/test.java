package com.test;

//public class test {
//    public static void main(String[] args) {
//        byte b=0x55;
//        short s=0400;
//        int i=100000;
//        long l=0xff;
////        char c1="A"; string -> char
//        char c1 = 'A';
//        char c2=65;
////        float f=.25; double -> float
//        float f = .25f;
//        double d=.00001234;
//        boolean bool = true;
//        float x = 3.3f;
//        double y = 2.9;
//        byte a = 5;
//        System.out.println((int)y);
//        System.out.println(3*a);
//        System.out.println(y/3*a);
//        System.out.println(x+ (int)y/3*a);
//    }
//}


//
//public class test {
//    public static void charge(int x){
//        x = 10;
//        System.out.println(x);
//    }
//
//    public static void main(String[] args) {
//        Person p = Person.getP("zhansds");
//        p.instruction();
//        int x = 5;
//        charge(x);
//        System.out.println(x);
//    }
//}
//
//class Person{
//    String name;
//    private Person(String name){
//        this.name = name;
//    }
//
//    void  instruction(){
//        System.out.println(name);
//    }
//    public static Person getP(String name){
//        Person ptemp = new Person(name);
//        return ptemp;
//    }
//}

//class staticTest
//{
//    static int classvar;
//    int instacevar;
//
//    static void  setClassvar(int i){
//        classvar = i;
//    }
//    void setInstacevar(int i){
//        classvar = i;
//        instacevar = i;
//    }
//
//    public static void main(String[] args) {
//        setClassvar(11);
//        staticTest st = new staticTest();
//        st.setInstacevar(13);
//        System.out.println(staticTest.classvar);
//        System.out.println(st.instacevar);
//    }
//}
//
//
//class T{
//    static T tobj;
//    private T(){ }
//    public static T getInstance(){
//        if (tobj == null){
//            tobj = new T();
//        }
//        return tobj;
//    }
//}
//
//class P{
//    public static void main(String[] args) {
//        T t1 = T.getInstance();
//        T t2 = T.getInstance();
//        System.out.println(t1==t2);
//    }
//}


//class staticTest {
//    static final int m;
//    final int j;
//
//    static {
//        m = 10;
//    }
//
//    staticTest(){
//        j = 11;
//    }
//
//
//    static int classvar;
//    int instacevar;
//
//    static void setClassvar(int i) {
//        classvar = i;
//    }
//
//    void setInstacevar(int i) {
//        classvar = i;
//        instacevar = i;
//    }
//
//    public static void main(String[] args) {
//        setClassvar(11);
//        staticTest st = new staticTest();
//        st.setInstacevar(13);
//        System.out.println(staticTest.classvar);
//        System.out.println(st.instacevar);
//        System.out.println(st.j);
//    }
//}

//
//class A{
//    private int prop1 = 5;
//    private static int prop2 = 9;
//
//    class B{
//        public int i;
//        void show(){
//            System.out.println(prop2);
//            System.out.println(prop1);
//        }
//    }
//
//}
//
//class c{
//    public static void main(String[] args) {
//        A.B.show();
//        A.B ab = new A.B();
//        System.out.println(ab.i);
//    }
//}