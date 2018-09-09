import scala.io.StdIn._

object Main extends App {
  val d = readLine().split("/").toList
  val y = d.head.toInt + 1
  println((y :: d.tail).mkString("/"))
}
