use std::collections::HashMap;

impl Solution {
    pub fn longest_str_chain(words: Vec<String>) -> i32 {
        let mut words = words;
        words.sort_by_key(|a| a.len());
        let mut dp: HashMap<String, i32> = HashMap::new();
        let mut max_chain = 0;
        for word in &words {
            dp.insert(word.clone(), 1);
            for i in 0..word.len() {
                let prev_word = format!("{}{}", &word[..i], &word[i+1..]);
                if let Some(val) = dp.get(&prev_word) {
                    dp.insert(word.clone(), std::cmp::max(dp[word], val + 1));
                }
            }
            max_chain = std::cmp::max(max_chain, dp[word]);
        }
        max_chain
    }
}