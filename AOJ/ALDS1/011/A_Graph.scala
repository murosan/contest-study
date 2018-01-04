import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val graph = collection.mutable.Seq.fill(n, n)(0)

  for (i <- 1 to n) {
    val input = readLine().split(" ").toList.map(_.toInt)
    val u = input.head - 1
    val k = input(1)
    for (j <- 1 to k) {
      graph(u)(input(1 + j) - 1) = 1
    }
  }

  graph.foreach(g => println(g.mkString(" ")))
}
