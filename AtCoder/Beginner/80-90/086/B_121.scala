import scala.io.StdIn._

object Main extends App {
  val Array(a, b) = readLine().split(" ")
  val sqrt = math.sqrt((a + b).toInt)
  val int = sqrt.toInt
  if (sqrt - int == 0) println("Yes") else println("No")
}
