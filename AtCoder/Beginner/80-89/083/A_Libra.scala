import scala.io.StdIn._

object Main extends App {
  val Array(a, b, c, d) = readLine().split(" ").map(_.toInt)
  if (a + b == c + d) println("Balanced")
  else if (a + b > c + d) println("Left")
  else println("Right")
}
