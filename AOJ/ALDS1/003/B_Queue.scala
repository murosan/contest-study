import scala.io.StdIn

case class Process(name: String, time: Int)

object Main extends App {
  val nq = StdIn.readLine().split(" ").toList.map(_.toInt)
  val n = nq.head
  val q = nq.last

  val queue = new scala.collection.mutable.Queue[Process]
  for (i <- 1 to n) {
    val tmp = StdIn.readLine().split(" ").toList
    queue += Process(tmp.head, tmp.last.toInt)
  }

  var sumOfTime = 0

  while (queue.nonEmpty) {
    val p = queue.dequeue()
    if (p.time > q) {
      sumOfTime += q
      queue += Process(p.name, p.time - q)
    } else {
      sumOfTime += p.time
      println(s"${p.name} $sumOfTime")
    }
  }
}
