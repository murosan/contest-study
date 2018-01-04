import scala.collection.mutable
import scala.io.StdIn._

case class UnionFind(parent: mutable.Seq[Int], rank: mutable.Seq[Int]) {

  def root(i: Int): Int = {
    if (parent(i) == i) return i
    parent(i) = root(parent(i))
    parent(i)
  }

  def same(x: Int, y: Int): Boolean = root(x) == root(y)

  def unite(x: Int, y: Int): Unit = {
    val _x = root(x)
    val _y = root(y)
    if (_x == _y) return

    if (rank(_x) < rank(_y)) parent(_x) = _y
    else {
      parent(_y) = _x
      if (rank(_x) == rank(_y)) rank(_x) += 1
    }
  }

}

object Main extends App {
  val Array(n, q) = readLine().split(" ").map(_.toInt)
  val uf = UnionFind(mutable.Seq.fill(n)(0), mutable.Seq.fill(n)(0))

  for (i <- 0 until n) {
    uf.parent(i) = i
  }

  for (i <- 1 to q) {
    val Array(com, x, y) = readLine().split(" ").map(_.toInt)
    com match {
      case 0 => uf.unite(x, y)
      case _ => if (uf.same(x, y)) println(1) else println(0)
    }
  }
}
