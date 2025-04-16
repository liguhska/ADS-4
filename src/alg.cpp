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
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
          count += n * (n - 1) / 2;
          break;
        }
      int left_dup = 1;
      while (left + 1 < right && arr[left] == arr[left + 1]) {
        left++;
        left_dup++;
      }
      int right_dup = 1;
      while (right_dup - 1 < left && arr[right] == arr[right - 1]) {
        right--;
        right_dup++;
      }
      count += left_dup * right_dup;
      left++;
      right--;
    }
    else if (sum < value) {
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
      int temp = index + 1;
      while (temp < len && arr[temp] == result) {
        count++;
        temp++;
      }
      break;
      }
    }
  return count;
}
