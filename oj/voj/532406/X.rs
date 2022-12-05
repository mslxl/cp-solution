use std::io::stdin;
fn main() {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    let t = line
        .split_whitespace()
        .map(|f| f.parse::<i32>().unwrap())
        .collect::<Vec<_>>();
    let (d, mut total_time) = (t[0], t[1]);

    let mut f = vec![vec![0; 2]; d as usize];

    let mut ans = vec![0; d as usize];
    for i in 0..d {
        line = String::new();
        stdin().read_line(&mut line).unwrap();
        let t = line
            .split_whitespace()
            .map(|f| f.parse::<i32>().unwrap())
            .collect::<Vec<_>>();
        let (min_time, max_time) = (t[0], t[1]);
        f[i as usize][0] = min_time;
        f[i as usize][1] = max_time;
        ans[i as usize] = min_time;
        total_time -= min_time;
        if total_time < 0 {
            println!("NO");
            return;
        }
    }
    for i in 0..d {
        let diff = f[i as usize][1] - f[i as usize][0];
        if total_time > diff {
            total_time -= f[i as usize][1] - f[i as usize][0];
            ans[i as usize] = f[i as usize][1];
        } else {
            ans[i as usize] = f[i as usize][0] + total_time;
            total_time = 0;
            break;
        }
    }
    if total_time <= 0 {
        println!("YES");
        for i in ans {
            print!("{} ", i);
        }
    } else {
        println!("NO");
    }
}
