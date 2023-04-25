fn main(){
  let mut line = String::new();
  std::io::stdin().read_line(&mut line).unwrap();
  let t = line.split_whitespace()
        .map(|f| f.parse::<i32>().unwrap())
        .collect::<Vec<_>>();
  let (s_h, s_m, e_h, e_m) = (t[0], t[1], t[2], t[3]);
  let use_min = e_h * 60 + e_m - (s_h * 60 + s_m);
  print!("{} {}", use_min / 60, use_min % 60);
}