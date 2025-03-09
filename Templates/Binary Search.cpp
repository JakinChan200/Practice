

int binarySearch(vector<int> list, int target){
    int left = 0;
    int right = list.size()-1;

    while(left <= right){
        mid = (right - left) / 2 + right;
        if(list[mid] == target){
            return mid;
        }

        if(list[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }

    return -1;
}