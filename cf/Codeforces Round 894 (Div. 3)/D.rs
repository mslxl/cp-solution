use std::io;
 
fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: i64 = input.trim().parse().unwrap();
 
    let mut i = ((2 * n) as f64).sqrt() as i64;
    while i * (i + 1) <= 2 * n {
        i += 1;
    }
    print!("{}\n", i + n - i * (i - 1)/ 2)
}
 
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: i64 = input.trim().parse().unwrap();
    for _ in 0..t {
        solve();
    }
}