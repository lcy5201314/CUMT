package MultiProgress;

public class MultiProgress {
    public static void main(String[] args) {
        myFrame[] myThread = new myFrame[3];
        System.out.println(myThread.length);
        myThread[0] = new huitu1();
        myThread[1] = new huitu2();
        myThread[2] = new huitu3();
        for (int i = 0; i < myThread.length; i++) {
            myThread[i].setTitle("第 " + (i + 1) + " 个图形");
            myThread[i].setBounds((1 + i) * 300, 300, 300, 300);
            myThread[i].setVisible(true);
        }
    }
}
