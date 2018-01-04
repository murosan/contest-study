import scala.io.StdIn._

object Main extends App {
  val Array(x, y) = readLine().split(" ").map(BigInt(_))

  var count = BigInt(1)
  var n = x

  while (n * 2 <= y) {
    count += 1
    n *= 2
  }

  println(count)
}
