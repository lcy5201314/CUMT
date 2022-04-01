package calculator;

import java.io.*;
import java.util.Scanner;

public class solveProblem implements Serializable {
    private int a, b, c;
    private double x1, x2;

    public void getData() throws AWrongException {
        System.out.println("please input a b c");
        Scanner scan = new Scanner(System.in);
        a = scan.nextInt();
        b = scan.nextInt();
        c = scan.nextInt();
        if (a == 0) throw new AWrongException();
        System.out.println("方程为:\t" + a + "*x^2 + " + b + "*x + " + c);
    }
    public String uiData(int a,int b,int c) throws AWrongException {
        String result;
        this.a = a;
        this.b = b;
        this.c = c;
        result = getRes();
        return result;
    }
    public String  getRes() {
        double delta = b * b - 4 * a * c;
        String result;
        if (delta < 0) {
            x1 = (double) Math.round((-1d * b) / (2d * a) * 10000) / 10000;     //保留四位小数
            x2 = (double) Math.round((Math.sqrt(-delta) / (2d * a)) * 10000) / 10000;
            System.out.println("方程有一对共轭副根:" + "x1 = " + x1 + "+" + x2 + "i"
                    + "\t" + "x2 = " + x1 + "-" + x2 + "i");
            result = "方程有一对共轭副根:" + "x1 = " + x1 + "+" + x2 + "i"
                    + "\t" + "x2 = " + x1 + "-" + x2 + "i";

        } else if (delta == 0) {
            double ans = -b / (2d * a);     //浮点上下文除法，加d
            System.out.println("方程解为x1 = x2 =" + ans);
            result = "方程解为x1 = x2 =" + ans;
        } else {
            double[] ans = new double[2];
            ans[0] = (-b + Math.sqrt(delta)) / 2 * a;
            ans[1] = (-b - Math.sqrt(delta)) / 2 * a;
            System.out.println("方程解为x1 = " + ans[0] + "\tx2 = " + ans[1]);
            result = "方程解为x1 = " + ans[0] + "\tx2 = " + ans[1];
        }
        return result;
    }

    public void saveRes() {
        solveProblem p = new solveProblem();
        evaluate(p);
        try (FileOutputStream fileout = new FileOutputStream("file1.data");
             ObjectOutputStream out = new ObjectOutputStream((fileout))) {
            out.writeObject(p);
            System.out.println("Serialized data is saved in file1.data");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public  boolean uiSaveRes(){
        saveRes();
        return true;
    }

    private void evaluate(solveProblem p) {
        p.a = a;
        p.b = b;
        p.c = c;
        p.x1 = x1;
        p.x2 = x2;
    }


}
