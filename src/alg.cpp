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

    while (arr[left] + arr[right] < value && left != right) {
        left++;
    }
    while (arr[right] > value && right != left) {
        right--;
    }
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j <= right; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int x = value - arr[i];
        if (x < 0) continue;
        int l = i + 1;
        int hight = len - 1;
        int first = -1;
        while (l <= hight) {
            int middle = l + (hight - l) / 2;
            if (arr[middle] >= x) {
                if (arr[middle] == x) first = middle;
                hight = middle - 1;
            }
            else {
                l = middle + 1;
            }
        }
        if (first != -1) {
            l = first;
            hight = len - 1;
            int last = first;
            while (l <= hight) {
                int middle = l + (hight - l) / 2;
                if (arr[middle] <= x) {
                    if (arr[middle] == x) last = middle;
                    l = middle + 1;
                }
                else {
                    hight = middle - 1;
                }
            }
            count += (last - first + 1);
        }
    }
    return count;
}
