import scala.io.StdIn._

object Main extends App {
  var loop = true
  while (loop) {
    var s = readLine().toString
    if (s == "-") loop = false
    else {
      val m = readInt()
      for (i <- 1 to m) {
        val (l, r) = s.splitAt(readInt())
        s = r + l
      }
      println(s)
    }
  }
}
