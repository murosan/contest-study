import scala.io.StdIn._

object Main extends App {
  val Array(a, b) = readLine().split(" ").map(_.toInt)
  val s = readLine()

  if (s.length != a + b + 1) {
    println("No")
  } else {
    val (before, after) = s.splitAt(a)
    if (after.head == '-' && before.forall(_.isDigit) && after.tail.forall(_.isDigit)) {
      println("Yes")
    } else {
      println("No")
    }
  }
}
