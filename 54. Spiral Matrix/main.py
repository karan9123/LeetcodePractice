class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        left, right = 0, len(matrix[0])
        top, bottom = 0, len(matrix)
        retLst = []
        rightFlag = True
        downFlag = False
        LeftFlag = False
        x = 0
        y = 0

        while left < right and top < bottom:
        
            if rightFlag:
                if x < right:
                    retLst.append(matrix[y][x])
                    x += 1
                else:
                    rightFlag = False
                    downFlag = True
                    top +=1
                    x -= 1
                    y += 1
            elif downFlag:
                if y < bottom:
                    retLst.append(matrix[y][x])
                    y +=1
                else:
                    downFlag = False
                    LeftFlag = True
                    right -=1
                    y -=1
                    x -=1
            elif LeftFlag:
                if x >= left:
                    retLst.append(matrix[y][x])
                    x -=1
                else:
                    LeftFlag = False
                    bottom -=1
                    x +=1
                    y -=1
            else:
                if y >= top:
                    retLst.append(matrix[y][x])
                    y -=1
                else:
                    rightFlag = True
                    left +=1
                    y +=1
                    x +=1

        return retLst

# Runtime: 9 ms Beats: 95.22%
# Memory: 13.2 MB Beats: 96.11%