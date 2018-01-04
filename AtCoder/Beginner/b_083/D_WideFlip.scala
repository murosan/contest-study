import scala.io.StdIn._

object Main extends App {
  val s = readLine()
  val len = s.length

  var min = len

  for (i <- 1 until len) {
    if (s(i - 1) != s(i))
      min = math.min(min, math.max(i, len - i))
  }

  println(min)
}
