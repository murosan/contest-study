import scala.io.StdIn._

object Main extends App {
  val Array(n, a, b) = readLine().split(" ").map(_.toInt)
  println(math.min(a * n, b))
}
