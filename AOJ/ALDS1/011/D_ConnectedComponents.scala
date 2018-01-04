import scala.collection.mutable
import scala.io.StdIn._

object Main extends App {
  val Array(n, m) = readLine().split(" ").map(_.toInt)
  val group: mutable.Seq[Int] = mutable.Seq.fill(n)(-1)
  var graph: mutable.Seq[Seq[Int]] = mutable.Seq.fill(n)(Seq())

  for (i <- 1 to m) {
    val Array(v1, v2) = readLine().split(" ").map(_.toInt)
    graph(v1) :+= v2
    graph(v2) :+= v1
  }

  var id = 0
  for (i <- 0 until n) {
    val queue: mutable.Queue[Int] = mutable.Queue()
    if (group(i) == -1) queue.enqueue(i)

    while (queue.nonEmpty) {
      val x = queue.dequeue()
      group(x) = id
      for (j <- graph(x).indices) {
        if (group(graph(x)(j)) == -1) queue.enqueue(graph(x)(j))
      }
    }

    id += 1
  }

  for (i <- 1 to readInt()) {
    val Array(v1, v2) = readLine().split(" ").map(_.toInt)
    if (group(v1) != -1 && group(v1) == group(v2)) println("yes") else println("no")
  }

}
