// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
        if (arr[i] + arr[j] == value) {
          count++;
        }
      }
    }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int right = len;
        int left = i;
        while (left < right - 1) {
            int mid = (left + right) / 2;
            if (arr[i] + arr[mid] == value) {
                count++;
                int confmid = mid + 1;
                while (arr[i] + arr[confmid] == value && confmid < right) {
                    count++;
                    confmid++;
                }
                confmid = mid - 1;
                while (arr[i] + arr[confmid] == value && confmid > left) {
                    count++;
                    confmid--;
                }
                break;
            }
            if (arr[i] + arr[mid] > value) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
    }
    return count;
}
