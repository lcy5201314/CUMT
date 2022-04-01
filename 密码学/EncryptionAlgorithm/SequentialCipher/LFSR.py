"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : LFSR.py
@Introduce: LFSR 线性移位寄存器
"""

# 选择一个15次以上的不可约多项式，
# 编写一个线性反馈移位寄存器。验证生成序列的周期。

def feedback(reg, fb):
    """
    反馈函数
    :param reg: 移位寄存器的内容
    :param fb: 由抽头构成的列表
    :return: 最左端的输入
    """
    res = reg[fb[0] - 1]
    for i in range(1, len(fb)):
        res = int(res) ^ int(reg[fb[i] - 1])
    return res


def lfsr(p):
    """
    线性反馈移位寄存器
    :param p: 由本原多项式次数构成的列表
    :return:
    """
    reg_len = max(p)
    # 初始寄存器状态:00000....001
    shift_reg = '1'.zfill(reg_len)
    regs = [shift_reg]  # 存放寄存器的各个状态
    output_ = []  # 存放输出序列
    for i in range(pow(2, reg_len) - 1):
        # 输出寄存器最右端的值
        output_.append(shift_reg[-1])
        # 计算抽头异或的值
        input_ = str(feedback(shift_reg, p))
        shift_reg = input_ + shift_reg[:-1]
        # 如果寄存器当前状态已经出现过了,说明一个周期结束
        # if shift_reg in regs:
        #     break
        # else:
        regs.append(shift_reg)
    return output_, regs


if __name__ == "__main__":

    print("请输入本原多项式(例如x^5+x^2+1,输入5 2 1)")
    num_str = str(input()).split(" ")
    num = []
    for i in num_str:
        num.append(int(i))
    print(num)
    outputs, regs = lfsr(num)
    # print(regs)

    for i in range(len(regs)):
        print("第{0}次:".format(i),regs[i])
    print("序列周期为:", len(regs)-1)
    with open('regs.txt', 'w') as f:
        for i in regs:
            f.write(i + "\n")


"""
2^16-1 = 65535 序列周期
16 5 3 2
x^16+x^5+x^3+x^2+1
x16+x5+x3+x2+1

https://wims.univ-cotedazur.fr/wims/wims.cgi?session=QO6082C26F.3&+lang=cn&+module=tool%2Falgebra%2Fprimpoly.cn&+cmd=reply&+job=menu
"""
