import java.util.*
import kotlin.math.*
import java.io.*

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out
@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readLong() = readLn().toLong()
fun readDouble() = readLn().toDouble()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }
fun readDoubles() = readStrings().map { it.toDouble() }

fun main() {
     val t = readInt() // number of test cases
     repeat(t) {
          solve()
     }
}

fun solve() {
     // Read input
     val n = readInt()
     val arr = readInts()
     
     // Solve the problem
     val result = calculateResult(n, arr)
     
     // Output result
     println(result)
}

fun calculateResult(n: Int, arr: List<Int>): Int {
     // Implement your solution here
     return 0
}

// Useful utility functions
fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)
fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)
fun lcm(a: Int, b: Int): Int = a / gcd(a, b) * b
fun lcm(a: Long, b: Long): Long = a / gcd(a, b) * b

// For faster I/O
class FastReader {
     var br: BufferedReader
     var st: StringTokenizer? = null
     
     constructor() {
          br = BufferedReader(InputStreamReader(System.`in`))
     }
     
     fun next(): String {
          while (st == null || !st!!.hasMoreElements()) {
               st = StringTokenizer(br.readLine())
          }
          return st!!.nextToken()
     }
     
     fun nextInt(): Int = next().toInt()
     fun nextLong(): Long = next().toLong()
     fun nextDouble(): Double = next().toDouble()
     fun nextLine(): String = br.readLine()
}

// For faster output
class FastWriter {
     val bw: BufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
     
     fun print(obj: Any) {
          bw.append(obj.toString())
     }
     
     fun println(obj: Any) {
          bw.append(obj.toString())
          bw.append("\n")
     }
     
     fun close() {
          bw.close()
     }
}