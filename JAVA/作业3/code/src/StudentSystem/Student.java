package StudentSystem;

import java.io.Serializable;

public class Student implements Serializable {
    private int sid;//学生id
    private String sname;//学生姓名
    private int sage;//学生年龄
    private String professional;//学生专业

    public Student() {
    }

    public Student(int sid, String sname, int sage, String  professional) {
        this.sid = sid;
        this.sname = sname;
        this.sage = sage;
        this.professional = professional;
    }

    public int getSid() {
        return sid;
    }

    public void setSid(int sid) {
        this.sid = sid;
    }

    public String getSname() {
        return sname;
    }

    public void setSname(String sname) {
        this.sname = sname;
    }

    public int getSage() {
        return sage;
    }

    public void setSage(int sage) {
        this.sage = sage;
    }

    public String getBirthday() {
        return professional;
    }

    public void setBirthday(String professional) {
        this.professional = professional;
    }
}
