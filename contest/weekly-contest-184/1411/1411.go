package main

import (
	"fmt"
)

var state = make([][]int, 27)
var f = make([][]int, 6000)
var mod = 1000000007

func judge(x, y int) bool {
	p := make([]int, 3)
	for i := 0; i < 3; i++ {
		p[i] = x % 3
		x = x / 3
	}
	q := make([]int, 3)
	for i := 0; i < 3; i++ {
		q[i] = y % 3
		y = y / 3
	}
	if p[0] == q[0] {
		return false
	}
	for i := 1; i < 3; i++ {
		if p[i] == q[i] {
			return false
		}
		if p[i] == p[i-1] {
			return false
		}
		if q[i] == q[i-1] {
			return false
		}
	}
	return true
}

func initState() {
	for x := 0; x < 27; x++ {
		ok := make([]int, 0)
		for y := 0; y < 27; y++ {
			if judge(x, y) {
				ok = append(ok, y)
			}
		}
		state[x] = ok
	}
}

func judgeX(x int) bool {
	p := make([]int, 3)
	for i := 0; i < 3; i++ {
		p[i] = x % 3
		x = x / 3
	}
	for i := 1; i < 3; i++ {
		if p[i] == p[i-1] {
			return false
		}
	}

	return true
}

func initF() {
	f[0] = make([]int, 27)
	f[1] = make([]int, 27)
	for x := 0; x < 27; x++ {
		if judgeX(x) {
			f[1][x] = 1
		} else {
			f[1][x] = 0
		}
	}
}

func numOfWays(n int) int {
	initState()
	initF()
	for i := 2; i <= n; i++ {
		f[i] = make([]int, 27)
		for x := 0; x < 27; x++ {
			for _, y := range state[x] {
				f[i][x] = (f[i][x] + f[i-1][y]) % mod
			}
		}
	}

	res := 0
	for x := 0; x < 27; x++ {
		res = (res + f[n][x]) % mod
	}
	return res
}

func main() {
	n := 1
	n = 2
	n = 3
	n = 7
	n = 5000
	res := numOfWays(n)
	fmt.Printf("%v\n", res)
}
