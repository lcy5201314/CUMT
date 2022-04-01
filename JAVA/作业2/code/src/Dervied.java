class Base {
    private String name = "base";
    public Base() {
        tellName();}

    public void tellName() {
        System.out.println("Base tell name: " + name); }
}
public class Dervied extends Base {
    private String name = "dervied";
    public Dervied() {
        tellName();}

    public void tellName() {
        System.out.println("Dervied tell name: " + name);}

    public static void main(String[] args){

        new Dervied();
    }
}