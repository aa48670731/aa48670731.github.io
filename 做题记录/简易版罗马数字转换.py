#简易版罗马数字转换
contain={1: "I",
          4:"IV",
          5:"V",
          9:"IX",
          10:"X",
          40:"XL",
          50:"L",
          90: "XC",
          100: "C",
          400:"CD",
          500:"D",
          900:"CM",
          1000:"M"
          }
num=eval(input())
box=[]
control=1
string=''
while num!=0:
    res=''
    temp = num%10
    if temp<5:
        if temp==4:
                res+=contain[control*4]
        else:
            while temp!=0:
                res+=contain[control]
                temp-=1
    elif temp==5:
        res=contain[control*5]+res
    else:
        if temp==9:
            res=contain[control*9]+res
        else:
            temp-=5
            res=contain[control*5]+res
            while temp!=0:
                res+=contain[control]
                temp-=1
    if control<1000:
        control*=10
    box+=[res]
    num//=10
for i in range(len(box)-1,-1,-1):
    string+=box[i]
print(string)



#ChatGPT写的：
def integer_to_roman(num):
    # 定义罗马数字对应的数值和符号
    roman_numerals = {
        1000: 'M',
        900: 'CM',
        500: 'D',
        400: 'CD',
        100: 'C',
        90: 'XC',
        50: 'L',
        40: 'XL',
        10: 'X',
        9: 'IX',
        5: 'V',
        4: 'IV',
        1: 'I'
    }

    roman_num = ''
    # 从最大的数值开始逐步减少并转换为对应的罗马数字
    for value, symbol in roman_numerals.items():
        while num >= value:
            roman_num += symbol
            num -= value

    return roman_num

# 测试
number = 1234
roman_number = integer_to_roman(number)
print(f"Roman number: {roman_number}")
