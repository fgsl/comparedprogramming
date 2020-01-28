/**
 * Go implementation of Eudoxo Algorithm for square root
 * @author Flávio Gomes da Silva Lisboa <flavio.lisboa@fgsl.eti.br>
 **/
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"	
    "time"
)

func microtime() float64 {
    return float64(time.Now().UnixNano() / int64(time.Microsecond))
}

func main(){
    argv := os.Args
    if (len(argv)<2){
        fmt.Println("Type: java Eudoxo [number to extract root square] [number of iterations]")
        os.Exit(0);
    }
 
    p,err := strconv.ParseFloat(argv[1], 64)
    if err != nil { // square
        fmt.Println("type error conversion")
	fmt.Println(err)
        os.Exit(0);
    } 	
    n,err := strconv.ParseInt(argv[2], 10, 64)
    if err != nil { // iterations
        fmt.Println("type error conversion")
	fmt.Println(err)
        os.Exit(0);
    }

    start := microtime();

    x := ((1 + p)/2);

    fmt.Println("n=0; x=",x);

    for i := int64(1) ;i < n; i++ {
        x = (((p/x) + x)/2);
        fmt.Println("n=",i,"; x=",x,";x^2=",(x * x));
    }

    elapsedtime := (microtime() - start);

    fmt.Printf("Elapsed time:%.4fms\n", elapsedtime/1000)

    fmt.Println("Value of language function:", math.Sqrt(p))
}
