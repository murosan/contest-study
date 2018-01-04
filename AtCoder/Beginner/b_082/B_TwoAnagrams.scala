import scala.io.StdIn._

object Main extends App {
  val s = readLine().sorted
  val t = readLine().sortWith(_ > _)
  if (s < t) println("Yes") else println("No")
}
