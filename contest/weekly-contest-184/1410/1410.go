package main

import (
	"fmt"
	"strings"
)

func entityParser(text string) string {
	res := text
	res = strings.ReplaceAll(res, "&quot;", "\"")
	res = strings.ReplaceAll(res, "&apos;", "'")
	res = strings.ReplaceAll(res, "&gt;", ">")
	res = strings.ReplaceAll(res, "&lt;", "<")
	res = strings.ReplaceAll(res, "&frasl;", "/")
	res = strings.ReplaceAll(res, "&amp;", "&")

	return res
}

func main() {
	text := "&amp; is an HTML entity but &ambassador; is not."
	text = "and I quote: &quot;...&quot;"
	text = "Stay home! Practice on Leetcode :)"
	text = "x &gt; y &amp;&amp; x &lt; y is always false"
	text = "leetcode.com&frasl;problemset&frasl;all"
	entityParser(text)

	res := entityParser(text)
	fmt.Printf("%v\n", res)
}
