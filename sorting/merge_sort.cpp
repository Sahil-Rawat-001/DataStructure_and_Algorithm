// Why merge sort over bubble sort, selection sort and insertion sort ?
// because the time complexity is goes down to the O(nlogbase2n);
// It is much more optimized sorting algorithm and sort any kind of data.
// Concept of merge sort - divide and merge


#include<iostream>
#include<vector>

using namespace std;
void mergeArr(vector<int>& arr,int l,int mid,int h){
    vector<int> temp;
    int left = l;
    int right = mid+1;

    while(left <= mid && right <= h){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= h){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = l; i <= h; i++){
        arr[i] = temp[i-l];
    }

}

void mergeSort(vector<int>& arr,int l, int h){
    if(l >= h) return;
    int mid = (l+h)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    mergeArr(arr,l,mid,h);
}

int main(){
    vector<int> arr = {3,1,2,4,1,5,2,6,4};
    int l = 0;
    int h = arr.size() -1;

    mergeSort(arr,l,h);

    for(auto val : arr){
        cout << val << " ";
    }
    return 0;
}