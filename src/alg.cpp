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

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    int i = 0;
    while (i < len - 1) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            int x = value - arr[i];
            if (x >= 0) {
                int left = i + 1;
                int right = len - 1;
                int found_pos = -1;
                while (left <= right) {
                    int middle = left + (right - left) / 2;
                    if (arr[middle] == x) {
                        if (middle > left && arr[middle - 1] == x) {
                            right = middle - 1;
                        }
                        else {
                            found_pos = middle;
                            break;
                        }
                    }
                    else if (arr[middle] < x) {
                        left = middle + 1;
                    }
                    else {
                        right = middle - 1;
                    }
                }
                if (found_pos != -1) {
                    count++;
                    while (found_pos + 1 < len && arr[found_pos + 1] == x) {
                        count++;
                        found_pos++;
                    }
                }
            }
        }
        i++;
    }
    return count;
}
