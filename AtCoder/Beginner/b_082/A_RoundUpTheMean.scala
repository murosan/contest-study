import scala.io.StdIn._

object Main extends App {
  val x = readLine().split(" ").map(_.toInt).sum / 2.0
  println(math.ceil(x).toInt)
}
