class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        switchPosLeft = -1
        switchPosRight = -1
        lastPos = len(nums) - 1
        #print(lastPos)

        if lastPos == 0:
            return


        tempSwitchPosLeft = lastPos - 1
        while tempSwitchPosLeft>-1:
            tempSwitchPosRight = tempSwitchPosLeft+1
            while tempSwitchPosRight<=lastPos:
                if nums[tempSwitchPosLeft]<nums[tempSwitchPosRight]:
                    if switchPosRight == -1 or nums[switchPosRight]>nums[tempSwitchPosRight]:
                        switchPosRight = tempSwitchPosRight
                        switchPosLeft = tempSwitchPosLeft


                tempSwitchPosRight += 1

            if switchPosRight != -1:
                break
            tempSwitchPosLeft -= 1


        if switchPosRight == -1:
            b = 0
            e = lastPos

            while b<e:
                tmp2 = nums[b]
                nums[b] = nums[e]
                nums[e] = tmp2
                b += 1
                e -= 1
        else:
            tmp = nums[switchPosLeft]
            nums[switchPosLeft] = nums[switchPosRight]
            nums[switchPosRight] = tmp

            nums[switchPosLeft+1:] = sorted(nums[switchPosLeft+1:])
