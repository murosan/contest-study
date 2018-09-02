import scala.io.StdIn._

object Main extends App {
  val x = readInt()
  val a = readInt()
  val b = readInt()
  println((x - a) % b)
}
