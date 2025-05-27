def check_duplicate(nums):
    seen = set()  

    for number in nums:
        if number in seen: 
            return True  
        
        seen.add(number)  # Add the number to the set
    
    return False  # If no duplicates are found, return False

# Example lists
without_dup = [1, 2, 3, 4, 5]  # without duplicates
mynums = [1, 1, 1, 2, 2, 3, 4, 5]  # with duplicates

result1 = check_duplicate(mynums)
result2 = check_duplicate(without_dup)

print("There is a duplicate:", result1)  # Output "there is a duplicate: True"
print("There is a duplicate:", result2)  # Output "there is a duplicate: False"
