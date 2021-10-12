use std::collections::HashMap;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut hashMap = HashMap::new();
        for x in nums.iter() {
            match hashMap.get(x){
                Some(true) => {
                    return true;
                },
                None| Some(false) =>  {
                    hashMap.insert(x, true);
                }
            };
        }
        return false;
    }
}

struct Solution {

}
fn main() {

}
