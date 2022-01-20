
fn first_word(str:&String) -> &str{
    let bytes = str.as_bytes();
    for (index, &b) in bytes.into_iter().enumerate(){
        if b == b' ' {
            return &str[..index]
        }
    }
    &str[..]
}

fn main() {
    let string = String::from("hello world");
    println!("{}", first_word(&string));
}
