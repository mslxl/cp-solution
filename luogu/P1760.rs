use std::io;

// fn move_block(src: &char, dst: &char, mid: &char, block: &i32, counter: &mut u128) {
//     if *block == 0 {
//         return;
//     }
//     move_block(src, mid, dst, &(block - 1), counter);
//     println!("{}:{} -> {}", block, src, dst);
//     *counter = *counter + 1;
//     move_block(mid, dst, src, &(block - 1), counter);
// }

// fn main() {
//     let A = 'A';
//     let B = 'B';
//     let C = 'C';
//     let mut counter: u128 = 0;

//     let mut n = String::new();
//     io::stdin()
//         .read_line(&mut n)
//         .expect("Fail to get input data");
//     let n: i32 = n.trim().parse().expect("Fail to parse input data");
//     move_block(&A, &C, &B, &n, &mut counter);
//     println!("{}", counter)
// }

fn solve(block: i32) -> u128 {
    if block == 1 {
        return 1;
    }
    return solve(block - 1) * 2 + 1;
}

fn main() {
    let mut n = String::new();
    io::stdin()
        .read_line(&mut n)
        .expect("Fail to get input data");
    let n: i32 = n.trim().parse().expect("Fail to parse input data");
    print!("{}", solve(n));
}
