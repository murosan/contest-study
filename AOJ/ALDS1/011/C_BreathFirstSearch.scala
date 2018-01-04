import scala.io.StdIn._

object Main extends App {
  val max = 1000000000
  val n = readInt()
  var graph = collection.mutable.Seq.fill(n, n)(max)

  for (i <- 1 to n) {
    val input = readLine().split(" ").toList.map(_.toInt)
    val u = input.head - 1
    val k = input(1)
    for (j <- 1 to k) {
      graph(u)(input(1 + j) - 1) = 1
    }
  }

  graph.head(0) = 0

  for (k <- 0 until n) {
    for (i <- 0 until n) {
      for (j <- 0 until n) {
        graph(i)(j) = math.min(graph(i)(j), graph(i)(k) + graph(k)(j))
      }
    }
  }

  graph.head.zipWithIndex.foreach {
    case (v, i) => println(s"${i + 1} ${if (v == max) -1 else v}")
  }
}
