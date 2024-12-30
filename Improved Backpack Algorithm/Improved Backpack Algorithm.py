# 关于背包问题的改进算法 An improved algorithm for the knapsack problem
# 思路 train of thought:
# 1.使用一个result列表来存储最后的结果，开辟的行数要多一行，第一行表示将前面0个物品装入
# 1.Use a result list to store the final results, allocate one more row,the first row indicates that no items are put in
# 2.开辟一个tran数组来当作过渡数组，负责每一次相加之后的的结果
# 2.Allocate a tran array as a transition array, responsible for storing the result after each addition.
# 3.相加的过程使用一个方法来表示，相加过程中，如果超过最大存储量就不用存储了
# 3.The process of addition is represented using a method where,during the addition process,if it exceeds the maximum
# storage capacity,it is not stored
# 4.并集的过程中，如果存在更优的情况就将劣质情况不并进去
# 4.During the process of union, if there is a better situation, the inferior situation will not be included.
# 5.顺序是先相加 后归类 最后的结束条件是结束变量到达物品数的最后一个
# 5.The order is to first add and then classify, and the final termination condition is that the termination variable
# reaches the last item number.

# 物品信息的类 Class of item information
class item(object):
    def __init__(self):
        self.weight=0  # 物品的单个重量 Individual weight of the item
        self.value=0    # 物品的单个价值 The individual value of an item

class Work(object):
    def __init__(self):
        self.infor=[]  # 存储物品的信息的列表 list for storing item information
        self.nums=0    # 存储物品的数量 The quantity of stored items
        self.weightAll=0 # 背包所能够承受的总重量 The total weight that the backpack can carry
    # 输入物品的信息的方法 Method for entering item information
    def enter(self):
        self.weightAll=int(input('输入背包所能够承受的总重量(Input the total weight that the backpack can carry):'))
        self.nums=int(input('请输入物品的数量(Please enter the quantity of the item.):'))
        print('下面开始输入物品的信息(Below is the information of the items):')
        trans=item()  # 将第0个物品存入 Store the 0th item
        self.infor.append(trans)
        for i in range(1,self.nums+1):
            trans = item()
            trans.weight,trans.value=eval(input(f"输入第{i}个物品的重量以及价值(Enter the weight and value of the {i}th item):"))
            self.infor.append(trans)
        print('测试输出输入的数据(Test the data input to the output):')
        for i in range(self.nums+1):
            print(f'第{i}个物品的重量是(The weight of the {i}th item is){self.infor[i].weight},价值是(values is){self.infor[i].value}')

# 解决问题的类 Problem-solving class
class Solve(Work):
    def __init__(self):
        self.numEnd=0  # 最后的结束条件变量 The final termination condition variable
        self.result=[] # 存储结果的列表 The list of stored results
        self.tran=[]   # 过渡列表 Transition list
        super().__init__()

    def enter(self):  # 将父类进行扩写 Expand the parent class
        super().enter()
        self.result.append([])
        self.result[0].append([self.infor[0].weight,self.infor[0].value])  # 初始化加过数组 Initialize the augmented array

    # 相加的方法 Methods of addition
    def add(self):
        # 如果加上之后的重量小于总的重量就将其进入过渡列表
        # If the weight after addition is less than the total weight, add it to the transition list.
        for i in range(len(self.result[self.numEnd-1])):
            if self.result[self.numEnd-1][i][0]+self.infor[self.numEnd].weight <= self.weightAll:
                self.tran[self.numEnd-1].append\
                    ([self.result[self.numEnd-1][i][0]+self.infor[self.numEnd].weight,self.result[self.numEnd-1][i][1]+\
                      self.infor[self.numEnd].value])
    # 进行并集的方法 Methods for performing a union operation
    def union(self):
        i=0 # 过渡变量 Transition variable
        m=0 # 过度变量 Transition variable
        self.result[self.numEnd]=self.result[self.numEnd-1]+self.tran[self.numEnd-1]  # 首先合体 First, merge
        self.result[self.numEnd].sort(key=lambda x:(x[0],-x[1]))
        while i<len(self.result[self.numEnd]):
            m=i+1
            while m<len(self.result[self.numEnd]):
                if self.result[self.numEnd][i][1] >= self.result[self.numEnd][m][1]:  # 如果后面有比他小的数 If there is a smaller number behind him
                    self.result[self.numEnd].pop(m)  # 弹出m Pop up m
                    m=m-1
                m=m+1
            i=i+1

    # 总过程的方法 The method of the whole process
    def finish(self):
        if self.numEnd==self.nums:  # 递归结束条件 base case for recursion
            return
        self.numEnd+=1
        self.tran.append([]) # 扩充过渡列表的行 Expand the rows of the transition list
        self.result.append([]) # 扩充行 Expand line
        self.add()
        self.union()
        self.finish() # 递归 recursion

work=Solve()
work.enter()
work.finish()
print(f'最后的结果是(The final result is){work.result}\n最大价值为{work.result[-1][-1][-1]}')