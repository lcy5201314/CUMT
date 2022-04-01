# JAVA复习

## 概论

![image-20220108113930919](https://s2.loli.net/2022/01/08/ukUm73nIr1jVTOa.png)

![image-20220108114135639](https://s2.loli.net/2022/01/08/15wRe23HSYvonip.png)

![image-20220108114149490](https://s2.loli.net/2022/01/08/YkJ18Ginb2StBWM.png)

![image-20220108114204311](https://s2.loli.net/2022/01/08/LJqZVUuzDX1IFrH.png)

![image-20220108114214062](https://s2.loli.net/2022/01/08/fb47YCErGv6wMZJ.png)

![image-20220108114229353](https://s2.loli.net/2022/01/08/Ddb4yevOroMEL3m.png)

![image-20220108114254109](https://s2.loli.net/2022/01/08/tPSwzmuHvQ38rxK.png)



![](https://s2.loli.net/2022/01/08/qnKG9vTzV31PHtp.png)





## JAVA语法

![image-20220108115455722](https://s2.loli.net/2022/01/08/NiuDUGEc1snZh2O.png)



![image-20220108115524654](https://s2.loli.net/2022/01/08/o6BRnm1bywfgvZc.png)

![image-20220108115535870](https://s2.loli.net/2022/01/08/QDRScOUh4rbo2df.png)

![image-20220108115559512](https://s2.loli.net/2022/01/08/Q3YeBtKyW9uDXd7.png)

## 自动类型转换

**整型、实型（常量）、字符型数据可以混合运算。运算中，不同类型的数据先转化为同一类型，然后进行运算。**

转换从低级到高级。

```
低  ------------------------------------>  高

byte,short,char—> int —> long—> float —> double 
```

数据类型转换必须满足如下规则：

- \1. 不能对boolean类型进行类型转换。

- \2. 不能把对象类型转换成不相关类的对象。

- \3. 在把容量大的类型转换为容量小的类型时必须使用强制类型转换。

- \4. 转换过程中可能导致溢出或损失精度，例如：

  ```
  int i =128;   
  byte b = (byte)i;
  ```

  因为 byte 类型是 8 位，最大值为127，所以当 int 强制转换为 byte 类型时，值 128 时候就会导致溢出。

- \5. 浮点数到整数的转换是通过舍弃小数得到，而不是四舍五入，例如：

  ```
  (int)23.7 == 23;        
  (int)-45.89f == -45
  ```

### 自动类型转换

必须满足转换前的数据类型的位数要低于转换后的数据类型，例如: short数据类型的位数为16位，就可以自动转换位数为32的int类型，同样float数据类型的位数为32，可以自动转换为64位的double类型。

![image-20220108115826957](https://s2.loli.net/2022/01/08/Epn2ZR9VlbQweYo.png)

### 强制类型转换

- \1. 条件是转换的数据类型必须是兼容的。
- \2. 格式：(type)value type是要强制类型转换后的数据类型 实例：

### 隐含强制类型转换

- 1、 整数的默认类型是 int。
- \2. 小数默认是 double 类型浮点型，在定义 float 类型时必须在数字后面跟上 F 或者 f。

![image-20220108120432994](https://s2.loli.net/2022/01/08/V234ChB9kAQInEP.png)

![image-20220108120451369](https://s2.loli.net/2022/01/08/HLKTlbAGfF4Bs8W.png)

![image-20220108120507855](https://s2.loli.net/2022/01/08/bwHUAzp2LPIleFg.png)

```java
package com.test;

public class test {
    public static void main(String[] args) {
        byte b=0x55;
        short s=0400;
        int i=100000;
        long l=0xff;
//        char c1="A"; string -> char
        char c1 = 'A';
        char c2=65;
//        float f=.25; double -> float
        float f = .25f;
        double d=.00001234;
        boolean bool = true;

    }
}
```

![image-20220108121410277](https://s2.loli.net/2022/01/08/rUPsk7BcD3zTQZ4.png)

![image-20220108121433180](https://s2.loli.net/2022/01/08/r2sbYnozhq6KC9t.png)

![image-20220108121451860](https://s2.loli.net/2022/01/08/UR95jLs7aixkdKN.png)

![image-20220108121603201](https://s2.loli.net/2022/01/08/gVUtkmyLlAhxZMq.png)

![image-20220108121615864](https://s2.loli.net/2022/01/08/SsuTlMV91igZKXJ.png)

![image-20220108121628942](https://s2.loli.net/2022/01/08/ywsKFhcRfTJMCz3.png)

```java
float x = 3.3f;
        double y = 2.9;
        byte a = 5;
        System.out.println(x+ (int)y/3*a);
        
        //这里int强制转换了后面的，先运算后转换2/3为0，0*a = 0,
```

![image-20220108122851348](https://s2.loli.net/2022/01/08/a5RU6vNYijeFZ3L.png)

![image-20220108123058102](https://s2.loli.net/2022/01/08/Mc4YSs7g5CBvJLU.png)

![image-20220108123112558](https://s2.loli.net/2022/01/08/KIcVLjZ81xyMCli.png)

![image-20220108123135791](https://s2.loli.net/2022/01/08/Le4IiQbAuoSYJtG.png)

![image-20220108123311584](https://s2.loli.net/2022/01/08/gzJZoyAscTC146F.png)

![image-20220108123654047](https://s2.loli.net/2022/01/08/BhSmV7nCEM31asW.png)

instanceof

![image-20220108123722203](https://s2.loli.net/2022/01/08/w7Tkdg4vNuPczmb.png)

![image-20220108123741195](https://s2.loli.net/2022/01/08/ZE9OauXJqhMQm7A.png)

![image-20220108123858764](https://s2.loli.net/2022/01/08/6MUCEdO5cKwjxLv.png)

![image-20220108123911199](https://s2.loli.net/2022/01/08/cFAbkfpJHXeL7mD.png)

![image-20220108123922254](https://s2.loli.net/2022/01/08/NxEPB5V7nkOqaR4.png)

![image-20220108123932519](https://s2.loli.net/2022/01/08/QkinW7DzoJLlXm5.png)



![image-20220108124052486](https://s2.loli.net/2022/01/08/seoHXOBtV8NYnur.png)

![image-20220108124100379](https://s2.loli.net/2022/01/08/8UL4Fbkv2NwXOl7.png)

![image-20220108124115040](https://s2.loli.net/2022/01/08/3HSdiIW8vVeyLEZ.png)

![image-20220108124126822](https://s2.loli.net/2022/01/08/MYj6J783cTfLahC.png)

![image-20220108124302373](https://s2.loli.net/2022/01/08/eNDasgm2C7yIKQ5.png)

## 面向对象

![image-20220108150320889](https://s2.loli.net/2022/01/08/QHUSdqklYR9m1yK.png)

![image-20220108150351171](https://s2.loli.net/2022/01/08/dq4oEs1YZFbQpcn.png)

![image-20220108150454478](https://s2.loli.net/2022/01/08/tOYTzj6lhi9FdpW.png)

![image-20220108150504762](https://s2.loli.net/2022/01/08/XmHs9ctnDC163F7.png)

![image-20220108150544583](https://s2.loli.net/2022/01/08/b86sTHBjJMXPu4p.png)

![image-20220108150709070](https://s2.loli.net/2022/01/08/7IPo2wW3qVUkXpc.png)

![image-20220108150729765](https://s2.loli.net/2022/01/08/VLskAWKpC3hBJZq.png)

![image-20220108150822529](https://s2.loli.net/2022/01/08/QIviqVjzrBmWu1f.png)

![image-20220108151620083](https://s2.loli.net/2022/01/08/4xEGRp7NuarmZDT.png)

![image-20220108152651907](https://s2.loli.net/2022/01/08/vVjWLYcDR1m5I8x.png)

![image-20220108152702343](https://s2.loli.net/2022/01/08/xe4M5IPJGFjTWnp.png)

变长的参数

![image-20220108152732898](https://s2.loli.net/2022/01/08/RBw9DThF4jVf1bv.png)

![image-20220108152837370](https://s2.loli.net/2022/01/08/Yb3fGx29JW7e1gn.png)

![image-20220108153028468](https://s2.loli.net/2022/01/08/im8BYQFCxrEDP3u.png)

![image-20220108153107233](https://s2.loli.net/2022/01/08/C2wZP5RXqbu3HQT.png)

![image-20220108153133223](https://s2.loli.net/2022/01/08/JpR1rOG8N3MnFK6.png)

![image-20220108153142069](https://s2.loli.net/2022/01/08/mrdVQ8BDsqNAvzO.png)

![image-20220108153151311](https://s2.loli.net/2022/01/08/RhaBtCEImkVJ5KX.png)

![image-20220108153224601](https://s2.loli.net/2022/01/08/gU1WCzHyNOBt3ov.png)

![image-20220108153532088](https://s2.loli.net/2022/01/08/LVuyGAlkrJqgovS.png)

<img src="https://s2.loli.net/2022/01/08/IALwFxNG8PHn5Jp.png" alt="image-20220108153744138" style="zoom:150%;" />

````

public class test {
    public static void charge(int x){
        x = 10;
        System.out.println(x);
    }

    public static void main(String[] args) {
        Person p = Person.getP("zhansds");
        p.instruction();
        int x = 5;
        charge(x);
        System.out.println(x);
    }
}

class Person{
    String name;
    private Person(String name){
        this.name = name;
    }

    void  instruction(){
        System.out.println(name);
    }
    public static Person getP(String name){
        Person ptemp = new Person(name);
        return ptemp;
    }
}
````

```
class staticTest
{
    static int classvar;
    int instacevar;

    static void  setClassvar(int i){
        classvar = i;
    }
    void setInstacevar(int i){
        classvar = i;
        instacevar = i;
    }

    public static void main(String[] args) {
        setClassvar(11);
        staticTest st = new staticTest();
        st.setInstacevar(13);
        System.out.println(staticTest.classvar);
        System.out.println(st.instacevar);
    }
}

13
13
```

![](https://s2.loli.net/2022/01/08/2CQoSIAb8Da9lZ5.png)

静态化赋值

![image-20220108163813969](https://s2.loli.net/2022/01/08/7NT9mJu8EsSzty3.png)

![image-20220108163910657](https://s2.loli.net/2022/01/08/JQevmVs6b2Z9A4R.png)

![image-20220108164125311](https://s2.loli.net/2022/01/08/YHzBWDJrwt7xXg6.png)

![image-20220108164254000](https://s2.loli.net/2022/01/08/Foyg9MYNJdBb7Ht.png)

![image-20220108164334585](https://s2.loli.net/2022/01/08/rVHcJ1pdETR2YFO.png)

![image-20220108164445210](https://s2.loli.net/2022/01/08/qiV1vn5pPWUtjEe.png)

![image-20220108170654865](https://s2.loli.net/2022/01/08/l7tzpWPaju9QIJm.png)

![image-20220108170757812](https://s2.loli.net/2022/01/08/EkGRwghobOYPpVs.png)

![image-20220108170817847](https://s2.loli.net/2022/01/08/oiYjnSpqIeKQzwT.png)

![image-20220108170832446](https://s2.loli.net/2022/01/08/c3PCadWubD8GVZl.png)

应用父类的

@Override

![image-20220108170900327](https://s2.loli.net/2022/01/08/O2kmTYUENzroIxs.png)

![image-20220108170941013](https://s2.loli.net/2022/01/08/gscv9F1tCfdlayb.png)

![image-20220108171025392](https://s2.loli.net/2022/01/08/gDEpUhPQu3q8K2L.png)

![image-20220108171519781](https://s2.loli.net/2022/01/08/sCkmYWdu4GLpRUF.png)

![image-20220108171530830](https://s2.loli.net/2022/01/08/7DGdOaqf9SuCcnJ.png)

![image-20220108171555886](https://s2.loli.net/2022/01/08/fsx9vMX5tVaJr6C.png)

![image-20220108171632145](https://s2.loli.net/2022/01/08/TFvZwiAzRdDahON.png)

![image-20220108171649404](https://s2.loli.net/2022/01/08/DxlAn2Mgwmhur1q.png)

![image-20220108171713728](https://s2.loli.net/2022/01/08/Z7UEhH2A6Gd45mW.png)

![image-20220108171751668](https://s2.loli.net/2022/01/08/jdw6ENim2RZvAnt.png)

![image-20220108171816557](https://s2.loli.net/2022/01/08/26kWrQnLFhaE3uH.png)

![image-20220108171858066](https://s2.loli.net/2022/01/08/mhy4FlcA1Y5LHGW.png)

![image-20220108171902999](https://s2.loli.net/2022/01/08/ouv3S9mqby6IEwD.png)

![image-20220108171949361](https://s2.loli.net/2022/01/08/ciXjW9r46RS7tD3.png)

![image-20220108172403808](https://s2.loli.net/2022/01/08/ShDJcgBz5A1pkOf.png)

这里static独立类了

![image-20220108172450414](https://s2.loli.net/2022/01/08/Dtvoqb7U3PzwpAf.png)

![image-20220108172646291](https://s2.loli.net/2022/01/08/s7UictVyY8qT13L.png)

![image-20220108173139048](https://s2.loli.net/2022/01/08/WiSQxKHFd4vw9Nq.png)

![image-20220108173237504](https://s2.loli.net/2022/01/08/gCVtaBOdsIQwe7m.png)

![image-20220108173339904](https://s2.loli.net/2022/01/08/2LeY4yiFgUkqWBs.png)

## 异常处理

![image-20220108173454495](https://s2.loli.net/2022/01/08/XcRY37KxwjTvkCu.png)

![image-20220108173508809](https://s2.loli.net/2022/01/08/2kRptdhm3sON5KJ.png)

![image-20220108173615143](https://s2.loli.net/2022/01/08/15eMxsrwcXqp7U8.png)

![image-20220108173600608](https://s2.loli.net/2022/01/08/zPkIw6iKNTOQZrY.png)

![image-20220108173659827](../AppData/Roaming/Typora/typora-user-images/image-20220108173659827.png)

![image-20220108173915765](https://s2.loli.net/2022/01/08/fsHuIPBC8yjLtx3.png)

![image-20220108174010965](https://s2.loli.net/2022/01/08/mplBZ4kYDyatu2g.png)

![image-20220108174033690](https://s2.loli.net/2022/01/08/Hk3IJ8OhnqSlMuf.png)

![image-20220108174052367](https://s2.loli.net/2022/01/08/Kga38ikNnqt4Bwc.png)

## 核心类

![image-20220108185530742](https://s2.loli.net/2022/01/08/ilKczw96e2xqsmH.png)

![image-20220108185544404](https://s2.loli.net/2022/01/08/NxoqwjACgrtnYsT.png)

![image-20220108185601604](https://s2.loli.net/2022/01/08/qRP1GB6Qc4ekFWr.png)

![image-20220108185622354](https://s2.loli.net/2022/01/08/fZck3D2oaguIJ4p.png)

![image-20220108195619368](https://s2.loli.net/2022/01/08/A53echuaWGOyibj.png)

![image-20220108195630400](https://s2.loli.net/2022/01/08/nxNY6fWTtScv3DG.png)

![image-20220108195705469](https://s2.loli.net/2022/01/08/TVi6IScJKMwPRD9.png)

![image-20220108195711705](https://s2.loli.net/2022/01/08/O6kV4h1mZFIls7j.png)

![image-20220108195756724](https://s2.loli.net/2022/01/08/SvDuqJ7eaOkGKT8.png)

![image-20220108195817336](https://s2.loli.net/2022/01/08/XhUFNWQLsvDoI3k.png)

![image-20220108195858376](https://s2.loli.net/2022/01/08/Rr18G9WSuPxXEgy.png)

![image-20220108195911781](https://s2.loli.net/2022/01/08/7tZcnSU6il1C4sg.png)

![image-20220108195941813](https://s2.loli.net/2022/01/08/Y4Sp35GzwLAflB1.png)

![image-20220108200055265](https://s2.loli.net/2022/01/08/PXcDRWuFQxHS17M.png)

![image-20220108200127883](https://s2.loli.net/2022/01/08/yGhlsc8BHzb45RW.png)

![image-20220108200143414](https://s2.loli.net/2022/01/08/1stp63m2zlAiMZg.png)

![image-20220108200240716](https://s2.loli.net/2022/01/08/32sPWJRxqltUjYz.png)

![image-20220108200340117](https://s2.loli.net/2022/01/08/hL7ZluF6gXnGzOa.png)

![image-20220108200431606](../AppData/Roaming/Typora/typora-user-images/image-20220108200431606.png)

![image-20220108200601892](https://s2.loli.net/2022/01/08/8aQVs9bmfXOzGnH.png)

![image-20220108201142058](https://s2.loli.net/2022/01/08/egpq1wFXNI648Ul.png)

## 图形化界面

![image-20220108201756543](https://s2.loli.net/2022/01/08/RnmbGr41piUDeqV.png)

![image-20220108201820822](https://s2.loli.net/2022/01/08/xbQoJVt1qHadAPI.png)

![image-20220108201841705](https://s2.loli.net/2022/01/08/5OEntwMNbHYRmIU.png)

![image-20220108202012718](https://s2.loli.net/2022/01/08/dG9g2mAqRiNIOK8.png)

![image-20220108202716377](https://s2.loli.net/2022/01/08/sAbPLSeyYRljDZK.png)

![image-20220108202851106](https://s2.loli.net/2022/01/08/UPc2ZsJvbmqE1iM.png)

![image-20220108202928463](https://s2.loli.net/2022/01/08/xhb2YBj5V6HypRI.png)

![image-20220108202939617](https://s2.loli.net/2022/01/08/DYq4I3jJ2tz8pbW.png)

![image-20220108203516094](https://s2.loli.net/2022/01/08/3RdkPaGEvQYXsbl.png)

![image-20220108203521795](https://s2.loli.net/2022/01/08/k69ltgisacoRFr7.png)

![image-20220108203818187](https://s2.loli.net/2022/01/08/WIVQ3OiK2LzsAER.png)

![image-20220108203839576](../AppData/Roaming/Typora/typora-user-images/image-20220108203839576.png)

![image-20220108203942936](https://s2.loli.net/2022/01/08/ct5xYZElBfapkhQ.png)

![image-20220108204001355](https://s2.loli.net/2022/01/08/WZQ2XyYcxfKJplL.png)

![image-20220108204015677](https://s2.loli.net/2022/01/08/xL2fYApern5V1bX.png)

![image-20220108204049980](https://s2.loli.net/2022/01/08/1mNbdlzfCykGuvx.png)

![image-20220108204102263](https://s2.loli.net/2022/01/08/iXgnhMdLU9Vy6ZO.png)

![image-20220108204118237](https://s2.loli.net/2022/01/08/17NdU2GrMWqYkeQ.png)
