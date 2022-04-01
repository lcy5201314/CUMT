package calculator;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
//
//import calculator.AWrongException;c
//import calculator.solveProblem;

public class calculator {

    private JTextField texta;
    private JTextField textb;
    private JButton Empty_Button;
    private JButton Quit_Button;
    private JButton Serialized_Result_Button;
    private JButton Solve_Button;
    private JTextField textc;
    private JPanel mainPanel;
    private JTextField textRes;
    private JPanel panelRes;

    public calculator() {
        Solve_Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e){
                int data_a = Integer.parseInt(texta.getText());
                int data_b = Integer.parseInt(textb.getText());
                int data_c = Integer.parseInt(textc.getText());
                // 清空
//                texta.setText("");
//                textb.setText("");
//                textc.setText("");
                try {
                    if(data_a == 0){
                        textRes.setText("[error]不是一元二次方程!a不能为0");
                    }
                    else {
                        solveProblem solveProblem = new solveProblem();
                        String res = solveProblem.uiData(data_a, data_b, data_c);
                        textRes.setText(res);
                    }
                } catch (AWrongException ex) {
                    ex.printStackTrace();
                }
            }
        });
        Serialized_Result_Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });
        Empty_Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // 清空
                texta.setText("");
                textb.setText("");
                textc.setText("");
                textRes.setText("");
            }
        });
        Serialized_Result_Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                solveProblem solveProblem = new solveProblem();
                boolean flag = solveProblem.uiSaveRes();
                if (flag){
                    textRes.setText("Serialized data is saved in file1.data");
                }
            }
        });
        Quit_Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("GoodBye");
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("一元二次方程求解器");
        frame.setContentPane(new calculator().mainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 300);
        //frame.pack();
        frame.setVisible(true);
    }

    private void createUIComponents() {
        // TODO: place custom component creation code here
    }
}
