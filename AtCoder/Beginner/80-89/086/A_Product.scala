import scala.io.StdIn._

object Main extends App {
  val Array(a, b) = readLine().split(" ").map(_.toInt)
  if (a * b % 2 == 1) println("Odd") else println("Even")
}
