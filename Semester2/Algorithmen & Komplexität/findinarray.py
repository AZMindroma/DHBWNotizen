def search_in_array(array, bottom, top, key):
    mid = (bottom + top) // 2

    if key not in array:
        return None
    if array[mid] == key:
        return mid
    else:
        if array[mid] < key:
            return search_in_array(array, bottom+1, mid, key)
        else:
            return search_in_array(array, mid, top-1, key)


baseArray = [1, 3, 4, 7, 10, 11, 16, 20, 28, 60]
for i in baseArray:
    print(search_in_array(baseArray, 0, len(baseArray), i))


