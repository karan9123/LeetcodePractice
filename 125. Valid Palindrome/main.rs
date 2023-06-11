impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let ss = s.to_lowercase().chars().collect::<Vec<char>>();
        let mut right = ss.len() - 1;
        let mut left = 0;
        while left < right {
            if ss[left].is_alphanumeric() && ss[right].is_alphanumeric() {
                if ss[left] != ss[right] {
                    return false;
                } else {
                    left += 1;
                    right -= 1;
                }
            } else if !ss[left].is_alphanumeric() {
                left += 1;
                continue;
            } else if !ss[right].is_alphanumeric() {
                right -= 1;
                continue;
            }
        }
        true
    }
}

// Runtime: 0 ms
// Memory: 2.6 MB
// O(n)