fun main(args: Array<String>) {
    val n = (1..10).map{
        readLine()!!.toInt() % 42
    }.toSet()
    .size
    System.out.print(n);
}