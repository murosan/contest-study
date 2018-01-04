import scala.collection.mutable
import scala.io.StdIn._

sealed abstract class Piece
case object Queen extends Piece
case object Danger extends Piece
case object Empty extends Piece

object Main extends App {
  type Pos = mutable.Seq[mutable.Seq[Piece]]
  val k = readInt()
  val pos: Pos = mutable.Seq.fill(8, 8)(Empty)

  val next = List(
    (r: Int, c: Int) => (r - 1, c),
    (r: Int, c: Int) => (r + 1, c),
    (r: Int, c: Int) => (r, c - 1),
    (r: Int, c: Int) => (r, c + 1),
    (r: Int, c: Int) => (r - 1, c - 1),
    (r: Int, c: Int) => (r - 1, c + 1),
    (r: Int, c: Int) => (r + 1, c - 1),
    (r: Int, c: Int) => (r + 1, c + 1)
  )

  for (i <- 1 to k) {
    val Array(r, c) = readLine().split(" ").map(_.toInt)
    pos(r)(c) = Queen
    next.foreach(f => {
      var row = r
      var col = c
      while (isOnBoard(row, col)) {
        if (pos(row)(col) == Empty) pos(row)(col) = Danger
        val n = f(row, col)
        row = n._1
        col = n._2
      }
    })
  }

  solve(0)

  pos.foreach(r => {
    r.foreach {
      case Queen => print("Q")
      case _ => print(".")
    }
    println
  })

  def isOnBoard(r: Int, c: Int): Boolean = 0 <= r && r <= 7 && 0 <= c && c <= 7

  def isSafe(r: Int, c: Int): Boolean = {
    next foreach (f => {
      var row = r
      var col = c
      while (isOnBoard(row, col)) {
        if (pos(row)(col) == Queen) return false
        val n = f(row, col)
        row = n._1
        col = n._2
      }
    })
    true
  }

  def solve(r: Int): Boolean = {
    if (pos(r) contains Queen) {
      if (r == 7) return true
      else return solve(r + 1)
    }

    for (c <- pos(r).indices) {
      if (pos(r)(c) == Empty && isSafe(r, c)) {
        pos(r)(c) = Queen
        if (r == 7 || solve(r + 1)) return true
        else pos(r)(c) = Empty
      }
    }
    false
  }
}
