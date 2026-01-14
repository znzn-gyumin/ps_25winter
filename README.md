# ps_25winter

week 1

2783(배열 연산)
입력받은 숫자 크기의 2차원 배열을 만들고 fgets()함수로 한 행씩 입력받아 같은 위치의 숫자끼리 연산

2751(정렬)
```c```
if(left<right){
    mid = (left+right)/2 // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
}
