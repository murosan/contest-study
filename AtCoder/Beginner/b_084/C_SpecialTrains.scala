import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val inputs = List.fill(n - 1)(readLine().split(" ").map(_.toInt).toList)

  for (i <- 0 until n - 1) {
    var time = 0
    for (j <- i until n - 1) {
      val c = inputs(j).head
      val s = inputs(j)(1)
      val f = inputs(j)(2)
      if (time < s)
        time = s
      else if (time % f != 0)
        time += f - (time % f)
      time += c
    }
    println(time)
  }

  println(0)
}
