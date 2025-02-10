


def mergeAndSort(ara, l, mid, r) -> int:
    
    """
        Merges two sorted halves of an array while counting inversions.

        This function is used in the Merge Sort-based inversion counting algorithm.
        It compares elements from two sorted halves of the array and counts how many 
        elements from the left half are greater than elements from the right half. 

        Algorithm:
        1. Two pointers are placed at the beginning of the left and right halves.
        2. If the left element is smaller, it is placed in the merged array.
        3. If the right element is smaller, an inversion is counted because all remaining 
        elements in the left half are greater than the current right element.
        4. The process continues until all elements are merged.
        5. Any leftover elements are appended at the end.

        Returns:
        - Total count of inversions found during merging.
        - List of inversion pairs where each pair (x, y) represents an inversion where 
        x appears before y in the original array but x > y.
    """
    
    left = ara[l:mid+1]  # Left half
    right = ara[mid+1:r+1]  # Right half
    i, j, k = 0, 0, l
    cnt = 0
    inversion_pairs = []

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:  # No inversion
            ara[k] = left[i]
            i += 1
        else:  # Inversion found
            ara[k] = right[j]
            cnt += len(left) - i  # Count inversions
            
            # Store inversion pairs
            for x in range(i, len(left)):
                inversion_pairs.append((left[x], right[j]))
            
            j += 1
        k += 1

    # Copy remaining elements (if any)
    while i < len(left):
        ara[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        ara[k] = right[j]
        j += 1
        k += 1

    return cnt, inversion_pairs


def invCount(ara: list[int], l: int, end: int):
    res = 0
    inversion_list = []
    
    if l < end:
        mid = (l + end) // 2  # Integer division

        left_count, left_pairs = invCount(ara, l, mid)
        right_count, right_pairs = invCount(ara, mid + 1, end)
        merge_count, merge_pairs = mergeAndSort(ara, l, mid, end)

        res = left_count + right_count + merge_count
        inversion_list = left_pairs + right_pairs + merge_pairs
    
    return res, inversion_list


if __name__ == "__main__":
    a = [4, 3, 9, 6, 13, 2, 5, 7, 11, 22, 23, 2312, 12]
    inversion_count, inversion_pairs = invCount(a, 0, len(a) - 1)
    
    print("Number of inversions:", inversion_count)
    print("Inversion pairs:", inversion_pairs)
