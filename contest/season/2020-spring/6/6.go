package main

import (
	"fmt"
)

func maxWeight(edges [][]int, value []int) int {
	ans := 0

	//for _, e := range edges {
	//	a := e[0]
	//	b := e[1]
	//	aEdge := make([]bool, len(value))
	//	bEdge := make([]bool, len(value))
	//	now := value[a] + value[b]
	//	for _, p := range edges {
	//		if p[0] == a {
	//			aEdge[p[1]] = true
	//		}
	//		if p[1] == a {
	//			aEdge[p[0]] = true
	//		}
	//		if p[0] == b {
	//			bEdge[p[1]] = true
	//		}
	//		if p[1] == b {
	//			bEdge[p[0]] = true
	//		}
	//	}
	//	max1 := -1
	//	max2 := -1
	//	for i := range value {
	//		if (i != a) && (i != b) && (aEdge[i]) && (bEdge[i]) {
	//			if value[i] > max1 {
	//				max2 = max1
	//				max1 = value[i]
	//			} else if value[i] > max2 {
	//				max2 = value[i]
	//			}
	//		}
	//	}
	//	if max1 > -1 {
	//		now = now + max1
	//		if max2 > -1 {
	//			now = now + max2
	//		}
	//		if now > ans {
	//			ans = now
	//		}
	//	}
	//}

	for i := range value {
		now := value[i]
		iEdge := make([]bool, len(value))
		for _, p := range edges {
			if p[0] == i {
				iEdge[p[1]] = true
			}
			if p[1] == i {
				iEdge[p[0]] = true
			}
		}

		max := -1
		maxE := -1
		for e, p := range edges {
			if (p[0] != i) && (p[1] != i) && (iEdge[p[0]]) && (iEdge[p[1]]) {
				v := value[p[0]] + value[p[1]]
				if v > max {
					max = v
					maxE = e
				}
			}
		}
		if max == -1 {
			continue
		}
		now = now + max

		for _, p := range edges {
			if (p[0] != i) && (p[1] != i) && (iEdge[p[0]]) && (iEdge[p[1]]) {
				v := 0
				if (p[0] != edges[maxE][0]) && (p[0] != edges[maxE][1]) {
					v = v + value[p[0]]
				}
				if (p[1] != edges[maxE][0]) && (p[1] != edges[maxE][1]) {
					v = v + value[p[1]]
				}
				if now+v > ans {
					ans = now + v
				}
			}
		}
	}

	return ans
}

func main() {
	edges := [][]int{{0, 1}, {1, 2}, {0, 2}}
	value := []int{1, 2, 3}
	edges = [][]int{{0, 2}, {2, 1}}
	value = []int{1, 2, 5}
	edges = [][]int{{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}}
	value = []int{7, 8, 6, 8, 9, 7}
	res := maxWeight(edges, value)
	fmt.Printf("%v\n", res)
}
