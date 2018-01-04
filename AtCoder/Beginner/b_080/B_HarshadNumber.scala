import scala.io.StdIn._

object Main extends App {
  val n: Int = readInt()
  // AtCoderではなぜか .tail が必要
  val sum: Int = n.toString.split("").tail.toList.map(_.toInt).sum

  if (n % sum == 0) println("Yes") else println("No")
}
