def rotate_array(nums, k):
    k = k % len(nums)  # Ensure k is within len of the nums list
    nums[:] = nums[-k:] + nums[:-k]  # I used index slicing here

# Example usage
nums = [1, 2, 3, 4, 5, 6, 7] #output becomes Rotated array: [5, 6, 7, 1, 2, 3, 4]
k = 3
rotate_array(nums, k)
print("Rotated array:", nums)
