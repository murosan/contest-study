import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readInt()

  if (n % 500 <= a) println("Yes")
  else println("No")
}
