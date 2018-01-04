import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readLine().split(" ").map(_.toInt)
  val maxAbsIndex = a.indexOf(a maxBy math.abs)

  println(2 * n - 1)
  for (i <- 1 to a.length) println(s"${maxAbsIndex+1} $i")

  if (a(maxAbsIndex) < 0)
    for (i <- n to 2 by -1) println(s"$i ${i - 1}")
  else
    for (i <- 1 until a.length) println(s"$i ${i + 1}")
}
