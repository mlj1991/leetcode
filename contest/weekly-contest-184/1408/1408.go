package main

import (
	"fmt"
	"strings"
)

func stringMatching(words []string) []string {
	res := make([]string, 0)
	for _, w := range words {
		for _, p := range words {
			if (p != w) && (strings.Index(p, w) != -1) {
				res = append(res, w)
				break
			}
		}
	}
	return res
}

func main() {
	n := 0
	words := []string{}
	fmt.Scanf("%d\n", &n)
	for i := 1; i <= n; i++ {
		w := ""
		fmt.Scanf("%s\n", &w)
		words = append(words, w)
	}
	words = []string{"mass", "as", "hero", "superhero"}
	words = []string{"leetcode", "et", "code"}
	words = []string{"blue", "green", "bu"}
	res := stringMatching(words)
	fmt.Printf("%v\n", res)
	//for _, w := range res {
	//	fmt.Printf("%s\n", w)
	//}
}
