[ 문제 1 ] (이진탐색-재귀버전) 정렬되어 있는 n개의 정수 키(사전)와 탐색할 키 k를 입력받아, 사전에서 k의 위치를 출력하는 프로그램을 작성하시오.
 
◦ 구현 조건
- 크기가 n인 배열을 동적 할당하여, 입력된 사전의 키 저장(중복 키는 없다고 가정)
- 이진탐색을 이용하여 탐색 키의 위치 찾기 – O(log n) 시간 필요
- 재귀 버전으로 구현
- 가능하면 교재의 의사코드를 보지 말고 구현해볼 것을 권장 (단, 구현 후 본인의 코드를 교재의 코드와 꼭 비교해 볼 것)
◦ 출력
- x ≤ k 를 만족하는 사전의 키 x 중 가장 큰 값의 위치(즉, 인덱스) 출력 (위치는 0부터 시작한다고 가정하고, 위 조건을 만족하는 x가 없는 경우 –1 출력)
- 즉, 키 k가 존재하는 경우에는 k의 위치를 출력하면 되고,
그렇지 않은 경우 k보다 작으면서 가장 큰 수의 위치를 출력하면 된다.

[ 문제 2 ] (이진탐색-비재귀버전) 정렬되어 있는 n개의 정수 키(사전)와 탐색할 키 k를 입력받아, 사전에서 k의 위치를 출력하는 프로그램을 작성하시오.
 
◦ 구현 조건
- 비재귀 버전(즉, 반복 버전)으로 구현
- 나머지 조건은 문제 1과 동일
◦ 출력 (문제 1과 약간 다름에 주의)
- x ≥ k 를 만족하는 사전의 키 x 중 가장 작은 값의 위치(즉, 인덱스) 출력
(위치는 0부터 시작한다고 가정하고, 위 조건을 만족하는 x가 없는 경우 n 출력)