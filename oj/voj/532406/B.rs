fn main(){
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).unwrap();
  let w:i128 = input.parse().unwrap();
  if w % 2 == 0 && w > 2 {
    print!("YES")
  }else{
    print!("NO")
  }
}