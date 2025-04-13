class Solution {
public:
    bool isPerfectSquare(int num) {
        // Handle the edge case where the number is 1, which is always a perfect square
        if(num == 1){
            return true;
        }

        // Initialize the binary search range. The square root of num is between 1 and num / 2
        int low = 1;
        int high = num / 2;

        // Binary search loop to find the integer square root
        while(low <= high){
            // Find the middle value of the current range [low, high]
            int mid = low + (high - low) / 2;

            // Check if mid is the integer square root of num
            // This avoids overflow that might happen when calculating mid * mid
            if(mid == num / mid && num % mid == 0){   
                return true;  // If mid * mid == num, it's a perfect square
            } 
            // If mid * mid is less than num, move the low pointer up
            else if(mid < num / mid){
                low = mid + 1;  // Search in the upper half
            } 
            // Otherwise, move the high pointer down
            else {
                high = mid - 1;  // Search in the lower half
            }
        }
        
        // If no integer square root is found, return false
        return false;
    }
};
