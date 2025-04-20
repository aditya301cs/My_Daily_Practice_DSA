class Solution {
public:
    void merge(vector<int>& arr, int start, int mid, int end) {
        vector<int> temp(end - start + 1);
        int left = start, right = mid + 1, index = 0;

        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                temp[index] = arr[left];
                index++, left++;
            } else {
                temp[index] = arr[right];
                index++, right++;
            }
        }
        // left array is not empty yet
        while (left <= mid) {
            temp[index] = arr[left];
            index++, left++;
        }

        // right array is not empty yet
        while (right <= end) {
            temp[index] = arr[right];
            index++, right++;
        }

        index = 0;
        // put these value in array
        while (start <= end) {
            arr[start] = temp[index];
            start++, index++;
        }
    }

    void mergesort(vector<int>& arr, int start, int end) {
        if (start == end) {
            return;
        }
        int mid = start + (end - start) / 2;
        // left side
        mergesort(arr, start, mid);
        // right side
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};