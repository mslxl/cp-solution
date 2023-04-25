fn open_or_senior(data: Vec<(i32,i32)>) -> Vec<String> {
    data.into_iter().map(|(age,handicap)| if age >= 55 && handicap > 7 { "Senior" } else{ "Open"}.to_string()).collect()
}

fn main() {
    let ret = open_or_senior(vec![(45, 12), (55,21), (19, -2), (104, 20)]);
    println!("{:?}", ret);
}
