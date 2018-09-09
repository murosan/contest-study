import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  var l = readLine().split(" ").map(_.toInt).toList

  var count = 0
  while (l forall (n => n >= 2 && n % 2 == 0)) {
    l = l.map(_ / 2)
    count += 1
  }

  println(count)
}
