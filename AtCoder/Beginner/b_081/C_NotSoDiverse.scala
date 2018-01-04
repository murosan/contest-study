import scala.collection.mutable
import scala.io.StdIn._

object Main extends App {
  val Array(n, k) = readLine().split(" ").map(_.toInt)
  val a = readLine().split(" ").map(_.toInt)
  var seq = mutable.Seq.fill(n)(0)

  a.foreach(i => seq(i - 1) += 1)
  seq = seq.filterNot(_ == 0).sorted
  println(seq.slice(0, seq.length - k).sum)
}
