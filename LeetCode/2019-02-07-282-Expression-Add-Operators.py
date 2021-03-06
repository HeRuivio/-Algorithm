# -*- coding: utf-8 -*-
# @Author:             何睿
# @Create Date:        2019-02-07 09:14:58
# @Last Modified by:   何睿
# @Last Modified time: 2019-02-13 12:06:39


class Solution:
    def addOperators(self, num: 'str', target: 'int') -> 'List[str]':
        # 声明解说数组
        res = []
        # 表达式，n个数字最多增加n-1个符号，所以表达式长度最长为2*n-1
        expression = [0] * (2 * len(num) - 1)
        # 使用深度优先搜索进行遍历搜索
        self.__dfs(num, target, 0, expression, 0, 0, 0, res)
        return res

    def __dfs(self, num, target, start, exp, vaild, prev, curr, res):
        # 递归结束条件，如果已经没有剩余的数字
        if start == len(num):
            # 如果当前已求得的和和目标相等，我们把有效的字符添加到结果中
            if curr == target:
                res.append("".join(exp[0:vaild]))
            return
        # n表示当前拆分的数字
        n = 0
        # l表示当前的有效位数
        l = vaild
        # index记录起始位置
        index = start
        if index: vaild += 1
        while start < len(num):
            # 获取数字
            n = n * 10 + (ord(num[start]) - ord('0'))
            # 如果当前起始数字为'0'(注意单独一个 0 是合法的) 则后面的所有数字都不会合法
            # 直接退出循环
            if num[index] == "0" and start != index : break
            # 将当前数字添加到表达式字符串中
            exp[vaild] = num[start]
            # 有效位数自增一次
            vaild += 1
            # 起始位置自增一次
            start += 1
            # 如果是给定字符串的第一个位置，不需要进行计算
            if index == 0:
                self.__dfs(num, target, start, exp, vaild, n, n, res)
                continue
            # 当前符号置为 「+」
            exp[l] = "+"
            self.__dfs(num, target, start, exp, vaild, n, curr + n, res)
            # 当前符号置为 「-」
            exp[l] = "-"
            self.__dfs(num, target, start, exp, vaild, -n, curr - n, res)
            # 当前符号置为 「*」
            exp[l] = "*"
            self.__dfs(num, target, start, exp, vaild, prev * n,curr - prev + prev * n, res)
