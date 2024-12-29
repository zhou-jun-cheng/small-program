# 关于0--1背包问题的求解 regarding the 0-1 Backpack Problem Solution
# 思路  way of thinking
# 1.动态规划解决问题  1.Dynamic Programming for Problem Solving
# 2.用户自己输入每个物品重量以及对应的价值 2.Users input the weight and corresponding value of each item themselves
# 3.用户自己输入总承受的重量 3.The user inputs the total weight they bear themselves
# 4.使用继承的方法来解决此问题 4.Use inheritance to solve this problem
# 5.最后存储的列表  列表示所承受的重量  行表示存放的物品的
# 5.The last stored list column represents the weight borne, while the row represents the weight of the stored items
# 6.从左到右依次填充 熟练的应用公式 列的数量应该比重量多一个  第一列表示重量为零
# 6.The number of proficient application formula columns filled from left to right should be one more than the weight.
# The first column represents zero weight
# 7.递归按照行来进行递归  第一行必须在赋值的时候就直接赋值了
# 7.Recursion is done by line. The first line must be assigned directly during the assignment process
# 改进算法


# 父类  物品的信息类 Information class of parent items
class item(object):
    def __init__(self):
        self.weights=0  # 物品的单个重量 Individual weight of the item
        self.value=0    # 物品的单个价值 The individual value of an item

# 解决问题的类
class Work(object):
    def __init__(self):
        self.nums=0    # 物品数量的变量 Attribute of item quantity
        self.weight=0  # 背包承受的重量 The attribute of the weight that the backpack can bear
        self.infor=[]  # 物品信息的列表 List of item information
        self.result=[] # 存储结果的列表 List of stored results

    # 用户输入的方法
    def enter(self):
        self.weight=int(input('背包所能够承受的总重量为(The total weight that the backpack can withstand is):'))
        self.nums=int(input('物品的数量为(The quantity of items is):'))
        print('下面开始输入物品的信息(Start inputting the information of the item below)')
        for i in range(1,self.nums+1):
            infors=item()
            infors.weights,infors.value=eval(input(f'输入第(Enter the number){i}个物品的信息(逗号隔开)(Information of individual items (separated by commas)):'))
            self.infor.append(infors)  # 存入数据 Deposit data
        print('测试输出(test output)')
        for i in range(1,self.nums+1):
            print(f'第{i}个物品的重量是(weight is){self.infor[i-1].weights},价值是(value is){self.infor[i-1].value}')
        for i in range(self.nums):  # 开辟结果的行 Open up the line of results
            self.result.append([])

# 关于第一行的赋值   继承 Regarding the assignment (inheritance) of the first line
class One(Work):
    def __init__(self):
        self.row=1   # 初始化行 Initialization line
        super().__init__()
    def enter(self):  # 直接扩写父类 Directly expand the parent class
        Work.enter(self)
        for i in range(self.weight+1):
            self.result[0].append(0)  # 初始化价值赋值为零 Initialize value assignment to zero
            # 如果找到比第一个更大的重量就可以直接将第一个价值赋值过去 If you find a weight larger than the first one, you can directly assign the value of the first one
            if i >= self.infor[0].weights:
                self.result[0][-1]=self.infor[0].value

    # 解决问题的方法 从第二个物品开始 The solution to the problem starts with the second item
    def solve(self):
        if self.row==self.nums:  # 递归的结束的条件 The conditions for the end of recursion
            return
        for i in range(self.weight+1):
            # 如果物品的重量比此时总重量小就直接继承上一行的物品
            # If the weight of the item is less than the total weight at this time, it will directly inherit the items in the previous row
            if self.infor[self.row].weights > i :
                self.result[self.row].append(self.result[self.row-1][i])
            else:  # 如果大就进行比较选取大值者 If it is large, compare and select the one with the highest value
                if self.infor[self.row].value + self.result[self.row-1][i-self.infor[self.row].weights] > self.result[self.row-1][i]:
                    self.result[self.row].append(self.infor[self.row].value + self.result[self.row-1][i-self.infor[self.row].weights])
                else:
                    self.result[self.row].append(self.result[self.row-1][i])
        self.row+=1
        self.solve() # 递归 recursion


work=One()# 创建对象  create object
work.enter()
work.solve()
print(f'最后的结果的列表是(The final list of results is):{work.result}')
print(f'能够存储的最大价值为(The maximum value that can be stored is):{work.result[-1][-1]}')