import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val d = List.fill(n)(readInt()).sorted.toSet
  println(d.size)
}
