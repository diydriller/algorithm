# algorithm

* DFS

  그래프 순회 알고리즘으로 깊이를 우선으로 해서 탐색한다. 탐색시 backtracking을 사용하고 재귀를 이용해 구현한다.
  
  응용 - 순열 , 조합 


* BFS

  그래프 순회 알고리즘으로 너비를 우선으로 해서 탐색한다. queue를 이용해 구현한다.
  
  응용 - 최적화문제 


* STRING

  응용 - TRIE(문자열을 빠르게 탐색하기위한 트리형태의 자료구조로 생성시 O(N*L) 탐색시 O(L)) 


* SEGMENT TREE(구간트리)

  query에 빠르게 응답하기위한 트리형태의 자료구조로 update시 O(logN)이며 binary tree로 구현한다.

  응용 - 특정구간의 data 처리 , lazy propagation(update시 대표node에 값을 저장하고 필요할때 propagation)
  
  
* TWO POINER 

  2개의 포인터를 이용해 특정구간의 data를 처리할때 빠르게 할수있다. 


* SHORTEST PATH

  최단거리 알고리즘으로 dijkstra와 floyd warshall가 있다. 전자는 한 정점에서부터 다른 정점들까지의 최단거리를
  구할때 사용하고 구현시 priority_queue를 사용할시 O(VlogE)가 걸린다.
  후자는 모든 정점에서부터 모든 정점까지의 최단거리를 구할때 사용하고 구현시 3중 for문을 이용해서 구현한다.
  
* DP

  문제가 반복적이고 하위문제의 최적해로 상위문제의 최적해를 구할수있을때 사용한다. 구현시 dp table을 정의하고 점화식을
  찾는다. dp table을 초기화하고 topdown 또는 bottomup으로 점화식을 사용해 dp table을 채워나간다.
