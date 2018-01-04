import scala.collection.mutable
import scala.io.StdIn._

case class Edge(to: Int, cost: Int)

object Main extends App {
  val n = readInt()
  val edges = for (i <- 0 until n) yield {
    val (_ :: k :: rest) = readLine().split(" ").map(_.toInt).toList
    for (j <- 0 until k) yield {
      Edge(rest(j * 2), rest(j * 2 + 1))
    }
  }

  val que = mutable.PriorityQueue(Edge(0, 0))(Ordering.by((e: Edge) => e.cost).reverse)
  val d = mutable.Seq.fill(n)(Int.MaxValue)
  d(0) = 0

  while (que.nonEmpty) {
    val edge = que.dequeue()
    if (d(edge.to) >= edge.cost) {
      edges(edge.to).foreach(e => {
        if (d(e.to) > d(edge.to) + e.cost) {
          d(e.to) = d(edge.to) + e.cost
          que.enqueue(e)
        }
      })
    }
  }

  d.zipWithIndex.foreach { case (x, i) => println(s"$i $x") }
}
