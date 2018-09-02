import scala.io.StdIn._

object Main extends App {
  val a = readInt()
  val b = readInt()
  val c = readInt()
  val x = readInt()

  var count = 0
  for (i <- 0 to a; j <- 0 to b; k <- 0 to c) {
    if (i * 500 + j * 100 + k * 50 == x) count += 1
  }

  println(count)
}
