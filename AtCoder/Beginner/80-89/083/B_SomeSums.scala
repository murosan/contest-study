import scala.io.StdIn._

object Main extends App {
  val Array(n, a, b) = readLine().split(" ").map(_.toInt)

  var sum = (1 to n).foldLeft(0)((acc, i) => {
    // !!notice!!: .tail
    val sumOfDigits = i.toString.split("").tail.map(_.toInt).sum
    if (a <= sumOfDigits && sumOfDigits <= b) acc + i
    else acc
  })

  println(sum)
}
