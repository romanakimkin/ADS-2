// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int result = 0;
    for (int i=0; i < len-1; i++)
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                result++;
        }
    }
   return result;
}

int countPairs2(int *arr, int len, int value) {
  int result = 0;
    int left = 0;
    int right = len - 1;
    while (arr[right] > value) right--;
    while (right > 0) {
        while (left < right) {
            if (arr[right]+arr[left] == value) {
                result++;
            }
        left++;
        }
        right--;
        left = 0;
    }
  return result;
}

int countPairs3(int *arr, int len, int value) {
  int result = 0;
    for (int i = 0; i < len-1; i++) {
        int left = i+1, right = len;
        while (left < right) {
            int middle = (left + right)/2;
            if (arr[middle] == (value - arr[i])) {
                while (arr[middle-1] == (value - arr[i]) && (middle > left)) {
                    middle--;
                }
                while (arr[middle] == (value - arr[i])) {
                    middle++;
                    result++;
                }
                break;
            } else if (arr[middle] > (value - arr[i])) {
                right = middle;
            } else {
                left = middle+1;
            }
        }
    }
  return result;
}
