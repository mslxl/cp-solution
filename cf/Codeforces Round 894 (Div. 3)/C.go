package main
 
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
 
func solve(in *bufio.Reader) {
	n := readInt(in)
	a := readArrInt(in)
	alen := n
	for i := 0; i < n; i++ {
		for alen > 0 && a[alen-1] <= i {
			alen--
		}
		if a[i] != alen {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}
func main() {
	in := bufio.NewReader(os.Stdin)
	T := readInt(in)
 
	for i := 0; i < T; i++ {
		solve(in)
	}
}
 
func readInt(in *bufio.Reader) int {
	nStr, _ := in.ReadString('\n')
	nStr = strings.ReplaceAll(nStr, "\r", "")
	nStr = strings.ReplaceAll(nStr, "\n", "")
	n, _ := strconv.Atoi(nStr)
	return n
}
 
func readLineNumbs(in *bufio.Reader) []string {
	line, _ := in.ReadString('\n')
	line = strings.ReplaceAll(line, "\r", "")
	line = strings.ReplaceAll(line, "\n", "")
	numbs := strings.Split(line, " ")
	return numbs
}
 
func readArrInt(in *bufio.Reader) []int {
	numbs := readLineNumbs(in)
	arr := make([]int, len(numbs))
	for i, n := range numbs {
		val, _ := strconv.Atoi(n)
		arr[i] = val
	}
	return arr
}
 
func readArrInt64(in *bufio.Reader) []int64 {
	numbs := readLineNumbs(in)
	arr := make([]int64, len(numbs))
	for i, n := range numbs {
		val, _ := strconv.ParseInt(n, 10, 64)
		arr[i] = val
	}
	return arr
}