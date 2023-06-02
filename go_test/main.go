package main

import "fmt"

func main() {
	var a, b int
	fmt.Println("Please enter 2 num:")
	fmt.Scanf("%d %d", &a, &b)
	fmt.Printf("result of %d + %d = %d\n", a, b, a+b)
}
