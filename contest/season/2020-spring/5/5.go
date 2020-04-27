package main

import (
	"fmt"
	"math"
)

var used []bool

func getFirst(points [][]int) int {
	k := 0
	for i, p := range points {
		if (p[0] < points[k][0]) || ((p[0] == points[k][0]) && p[1] < points[k][1]) {
			k = i
		}
	}
	return k
}

func getCos(x1, y1, x2, y2 int) float64 {
	return float64(x1*x2+y1*y2) / math.Sqrt(float64(x1*x1+y1*y1)) / math.Sqrt(float64(x2*x2+y2*y2))
}

func findMin(a []int, b []int, points [][]int) int {
	k := -1
	mincos := float64(2)
	for i, p := range points {
		if !used[i] {
			cos := getCos(a[0]-b[0], a[1]-b[1], p[0]-b[0], p[1]-b[1])
			//fmt.Printf("%v %v %v %v\n", a[0]-b[0], a[1]-b[1], p[0]-b[0], p[1]-b[1])
			//fmt.Printf("%v %v\n", i, cos)
			if cos < mincos {
				k = i
				mincos = cos
			}
		}
	}

	return k
}

func findMax(a []int, b []int, points [][]int) int {
	k := -1
	maxcos := float64(-2)
	for i, p := range points {
		if !used[i] {
			cos := getCos(a[0]-b[0], a[1]-b[1], p[0]-b[0], p[1]-b[1])
			if cos > maxcos {
				k = i
				maxcos = cos
			}
		}
	}

	return k
}

func visitOrder(points [][]int, direction string) []int {
	ans := make([]int, 0)
	used = make([]bool, len(points))
	for i := range used {
		used[i] = false
	}

	now := getFirst(points)
	ans = append(ans, now)
	used[now] = true
	prev := []int{points[now][0], points[now][1] + 1}
	prevD := 'L'

	for _, d := range direction {
		next := -1
		if d == prevD {
			next = findMin(prev, points[now], points)
		} else {
			next = findMax(prev, points[now], points)
		}
		//fmt.Printf("%v \n", next)
		prev = points[now]
		prevD = d
		now = next
		ans = append(ans, now)
		used[now] = true
	}

	for i := range used {
		if !used[i] {
			ans = append(ans, i)
		}
	}

	return ans
}

func main() {
	points := [][]int{{1, 1}, {1, 4}, {3, 2}, {2, 1}}
	direction := "LL"
	points = [][]int{{1, 3}, {2, 4}, {3, 3}, {2, 1}}
	direction = "RR"
	res := visitOrder(points, direction)
	fmt.Printf("%v\n", res)
}
