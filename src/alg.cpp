// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      left++;
      right--;
      while (left < right && arr[left] == arr[left - 1])
        left++;
      while (left < right && arr[right] == arr[right + 1])
        right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int binarySearch(int* arr, int left, int right, int x) {
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] == x)
            return middle;
        else if (x < arr[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len - 1; i++) {
        int result = value - arr[i];
        int index = binarySearch(arr, i + 1, len - 1, result);
        while (index != -1) {
            count++;
            while (index + 1 < len && arr[index] == arr[index + 1]) {
                count++;
                index++;
            }
        }
    }
    return count;
}
