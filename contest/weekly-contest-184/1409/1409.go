package main

import (
	"fmt"
)

func processQueries(queries []int, m int) []int {
	p := make([]int, 0)
	for i := 1; i <= m; i++ {
		p = append(p, i)
	}

	res := make([]int, len(queries))
	for i, q := range queries {
		for j, k := range p {
			if q == k {
				res[i] = j
				p = append(p[0:j], p[j+1:]...)
				p = append([]int{k}, p...)
				break
			}
		}
	}

	return res
}

func main() {
	queries := []int{3, 1, 2, 1}
	m := 5

	queries = []int{4, 1, 2, 2}
	m = 4

	queries = []int{7, 5, 5, 8, 3}
	m = 8

	res := processQueries(queries, m)
	fmt.Printf("%v\n", res)
}
