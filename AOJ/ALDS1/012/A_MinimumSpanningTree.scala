import scala.collection.mutable
import scala.io.StdIn._

case class Edge(from: Int, to: Int, cost: Int)

object Main extends App {
  val n = readInt()
  val d = mutable.Seq.fill(n, n)(Int.MaxValue)
  var edges = mutable.Seq.fill(n)(Seq.empty[Edge])

  for (i <- 0 until n) {
    val costs = readLine().tail.split(" ")
    for (j <- costs.indices) {
      if (costs(j) != "-1") {
        d(i)(j) = costs(j).toInt
        edges(i) :+= Edge(i, j, costs(j).toInt)
      }
    }
  }

  val searched = mutable.Seq.fill(n)(false)
  val parents = mutable.Seq.fill(n)(-1)
  val distances = mutable.Seq.fill(n)(Int.MaxValue)
  distances(0) = 0
  val que = mutable.PriorityQueue(0)(Ordering.by((x: Int) => distances(x)).reverse)

  while (que.nonEmpty) {
    val from = que.dequeue()
    if (!searched(from)) {
      searched(from) = true
      edges(from).foreach(e => {
        val to = e.to
        if (!searched(to) && distances(to) > d(from)(to)) {
          distances(to) = d(from)(to)
          parents(to) = from
        }
        que.enqueue(to)
      })
    }
  }

  val s = parents.zipWithIndex
    .foldLeft(0)((acc, z) =>
      z match {
        case (p, i) if p != -1 => acc + d(i)(p)
        case _ => acc
      })

  println(s)
}
