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

  var foundTime = List.fill(n)(-1)
  var finishedTime = List.fill(n)(-1)

  var time = 0

  def search(id: Int): Unit = {
    for (i <- graph(id).indices) {
      if (graph(id)(i) == 1 && foundTime(i) == -1) {
        time += 1
        foundTime = foundTime.updated(i, time)
        search(i)
      }
    }
    time += 1
    finishedTime = finishedTime.updated(id, time)
  }

  while (foundTime contains -1) {
    time += 1
    val index = foundTime indexOf -1
    foundTime = foundTime.updated(index, time)
    search(index)
  }

  for (i <- graph.indices) {
    println(s"${i + 1} ${foundTime(i)} ${finishedTime(i)}")
  }
}
