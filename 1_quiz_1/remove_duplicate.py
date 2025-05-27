def sort_arr(nums):
    n = len(nums)
    for i in range(n - 1):
        swapped = False 
        for j in range(n - i - 1):
            if nums[j] > nums[j + 1]:  
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
                swapped = True
        if not swapped: 
            break

def removeDuplicates(nums):
    if not nums:
        return 0

    i = 0
    for j in range(1, len(nums)):
        if nums[j] != nums[i]:
            i += 1
            nums[i] = nums[j]
    return i + 1 

# Example usage
nums = [4, 2, 5, 1, 2, 3, 4, 1]
sort_arr(nums)  
print("Sorted array:", nums)

new_length = removeDuplicates(nums)  
print("New length:", new_length)
print("Array after removing duplicates:", nums[:new_length])


#Output
#Sorted array: [1, 1, 2, 2, 3, 4, 4, 5]
#New length: 5
#Array after removing duplicates: [1, 2, 3, 4, 5] """