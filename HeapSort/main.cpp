//
//  main.cpp
//  HeapSort
//
//  Created by adeeb mohammed on 30/03/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

void swap(int fromIdx, int toIdx, std::vector<int> &numbers){
    int temp = numbers.at(fromIdx);
    numbers.at(fromIdx) = numbers.at(toIdx);
    numbers.at(toIdx) = temp;
}

void shiftdown(int currentIdx, int endIdx, std::vector<int> &numbers){
    int firstChildIdx = (currentIdx*2) +1;
    while (firstChildIdx <= endIdx) {
        int secondChildIdx = firstChildIdx + 1;
        int idxToSwap = firstChildIdx;
        if (secondChildIdx <= endIdx && numbers.at(secondChildIdx) > numbers.at(firstChildIdx)) {
            idxToSwap = secondChildIdx;
        }
        if (numbers.at(idxToSwap) > numbers.at(currentIdx) ) {
            swap(currentIdx, idxToSwap, numbers);
            currentIdx = idxToSwap;
            firstChildIdx = (currentIdx *2) +1;
        }else{
            return;
        }
        
    }
}

void buildHeap(std::vector<int> &numbers){
    int firstParentIdx = ((int)numbers.size()-2)/2;
    for (int currIdx = firstParentIdx; currIdx >= 0; currIdx--) {
        shiftdown(currIdx, (int)numbers.size()-1, numbers);
    }
}

std::vector<int> heapSort(std::vector<int> numbers){
    std::vector<int> result;
    buildHeap(numbers);
    for (int i = (int)numbers.size()-1; i > 0 ; i --) {
        swap(0, i, numbers);
        shiftdown(0, i - 1, numbers);
    }
    return numbers;
}

std::vector<int> heapSortAsc(std::vector<int> array){
    std::vector<int> result;
    // heapify function
    std::priority_queue<int,std::vector<int>,std::greater<int> > pq;
    for (auto num: array) {
        pq.push(num);
    }
    // getting the min element every time
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}

int main(int argc, const char * argv[]) {
    auto result = heapSortAsc({33,554,1,4,100,-2});
    for (auto num: result) {
        std::cout<< num << " ";
    }
    
    std::cout << std::endl;
    
    std::vector<int> arr = {33,554,1,4,100,-2};
    auto res = heapSort(arr);
    for (auto num: res) {
        std::cout<< num << " ";
    }
    std::cout<<std::endl;
    return 0;
}
