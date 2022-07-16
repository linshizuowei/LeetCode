def findkth(nums, k, low, high):
    if low >= high:
        return nums[high]
    left = low - 1
    pivot = nums[high]
    for i in range(low, high):
        if nums[i] < pivot:
            left += 1
            nums[left], nums[i] = nums[i], nums[left]
    nums[left + 1], nums[high] = nums[high], nums[left + 1]
    if left + 1 == k:
        return nums[left + 1]
    elif left + 1 < k:
        return findkth(nums, k, left + 2, high)
    else:
        return findkth(nums, k, low, left)


if __name__ == '__main__':
    nums = [0,0]
    idx = len(nums) / 2
    mid = findkth(nums, idx, 0, len(nums) - 1)
    p = findkth(nums, idx-1, 0, len(nums)-1)
    print(mid, p)

