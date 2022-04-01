package StudentSystem;

import java.util.ArrayList;
import java.util.Scanner;


public class StudentInfoManage {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //定义一个集合，用于存储学生对象
        ArrayList<Student> list = new ArrayList<Student>();
        while (true) {
            //操作界面
            System.out.println("*****************欢迎来到学生管理系统*****************");
            System.out.println("[0] 退出");
            System.out.println("[1] 添加学生");
            System.out.println("[2] 删除学生");
            System.out.println("[3] 修改学生");
            System.out.println("[4] 查看学生");
            System.out.println("[5] 查询学生");
            System.out.println("请输入您的选择:");
            String choice = sc.next();
            switch (Integer.parseInt(choice)) {//这里需要一个int型，jdk11可以直接使用String
                case 0:
                    System.out.println("感谢的使用");
                    System.exit(0);
                case 1:
                    //System.out.println("添加学生");
                    addStuInfo(list);
                    break;
                case 2:
                    //System.out.println("删除学生");
                    deleteStuInfo(list);
                    break;
                case 3:
                    //System.out.println("修改学生");
                    editStuInfo(list);
                    break;
                case 4:
                    //System.out.println("查看学生");
                    showStuInfo(list);
                    break;
                case 5:
                    QueryStuInfo(list);
                default:
                    System.out.println("你的操作有误，请重新输入");
                    break;
            }
            System.out.println("***************************************************");
        }
    }

    /*
        添加学生信息
     */
    public static void addStuInfo(ArrayList<Student> list) {
        Scanner sc = new Scanner(System.in);
        int sid;
        while (true) {//判断学生是否存在
            System.out.println("请输入学生编号：");
            sid = sc.nextInt();
            int index = isSidExist(list, sid);//调用方法
            if (index == -1) {
                //不存在可以使用
                break;
            }
            System.out.println("该学号已存在，不能继续使用该学号");
        }
        System.out.println("请输入学生姓名：");
        String sname = sc.next();
        System.out.println("请输入学生年龄：");
        int sage = sc.nextInt();
        System.out.println("请输入学生专业：");
        String birthday = sc.next();
        Student stu = new Student(sid, sname, sage, birthday);
        list.add(stu);
        System.out.println("添加成功");
    }

    /*
    判断学生学号是否已经存在
     */
    public static int isSidExist(ArrayList<Student> list, Integer sid) {
        //当传入的学号在集合中不存在
        int index = -1;
        for (int i = 0; i < list.size() ; i++) {
            Student student = list.get(i);
            int id = student.getSid();
            if (sid == id){
                return index = i;
            }
        }
        return index;
    }

    /*
        删除学生信息
     */
    public static void deleteStuInfo(ArrayList<Student> list) {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入要删除的学号");
        int id = sc.nextInt();
        int index = isSidExist(list, id);
        if (index == -1) {//不存在该学号
            System.out.println("该信息不存在");
        } else {
            list.remove(index);
            System.out.println("删除成功");
        }

    }

    /*
        修改学生
     */
    public static void editStuInfo(ArrayList<Student> list) {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入学号");
        int id = sc.nextInt();
        //判断该信息是否存在
        int index = isSidExist(list, id);
        if (index == -1){
            System.out.println("该学号不存在");
        }
        System.out.println("请输入姓名");
        String sname = sc.next();
        System.out.println("请输入年龄");
        int sage = sc.nextInt();
        System.out.println("请输入专业");
        String birthday = sc.next();
        //将输入的信息添加到学生对象中
        Student student =new Student(id,sname,sage,birthday);
        //修改集合中的数据
        list.set(index,student);
        System.out.println("修改成功");
    }
    /*
        查看学生信息
     */
    public static void showStuInfo(ArrayList<Student> list) {
        //判断集合中是否已经存在数据
        if (list.size() == 0) {
            System.out.println("无信息，请先添加信息");
        }
        System.out.println(String.format("%-15s","学号" )
                + String.format("%-15s", "姓名" )
                + String.format("%-15s", "年龄")
                + String.format("%-15s", "专业" ));
        for (Student student : list) {
            System.out.println(String.format("%-16s", student.getSid() )
                            + String.format("%-16s", student.getSname() )
                            + String.format("%-16s", student.getSage() )
                            + String.format("%-16s", student.getBirthday() ));
        }
    }

    /*
        查询学生信息
     */
    public static void QueryStuInfo(ArrayList<Student> list) {
        //判断集合中是否已经存在数据
        if (list.size() == 0) {
            System.out.println("无信息，请先添加信息");
        }
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入学号");
        int id = sc.nextInt();
        //判断该信息是否存在
        int index = isSidExist(list, id);
        if (index == -1){
            System.out.println("该学号不存在");
        }
        else {
            System.out.println(String.format("%-15s","学号" )
                    + String.format("%-15s", "姓名" )
                    + String.format("%-15s", "年龄")
                    + String.format("%-15s", "专业" ));
            Student student = list.get(index);
            System.out.println(String.format("%-16s", student.getSid() )
                    + String.format("%-16s", student.getSname() )
                    + String.format("%-16s", student.getSage() )
                    + String.format("%-16s", student.getBirthday() ));
        }
    }
}