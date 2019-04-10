class Solution:
    def strStr(self, source, target):

        # 判空
        if source is None or target is None:
            return -1
        # 遍历原字符串
        for i in range(len(source) - len(target) + 1):
            print('i: ',i)
            # 遍历目标字符串
            for j in range(len(target)):
                print('j: ', j)
                if source[i + j] != target[j]:
                    break
                else:
                    return i

        return -1


source = '23123'
target = '123'
run = Solution()
result = run.strStr(source, target)
print(result)
