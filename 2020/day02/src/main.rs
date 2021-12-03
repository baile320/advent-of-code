use regex::Regex;

struct PasswordInfoA {
    password: String,
    required_char: String,
    min: usize,
    max: usize,
}

pub fn get_answer_part_a(password_info: &str) -> usize {
    let re = Regex::new(r"^(\d+)-(\d+) ([a-z]): ([a-z]+)$").unwrap();

    let mut info = vec![];
    for line in password_info.split('\n') {
        let groups = re.captures(line).unwrap();
        info.push(PasswordInfoA {
            min: groups[1].parse::<usize>().unwrap(),
            max: groups[2].parse::<usize>().unwrap(),
            required_char: groups[3].to_string(),
            password: groups[4].to_string(),
        })
    }

    info.into_iter()
        .filter(|password| is_password_valid_part_a(password))
        .count()
}

fn is_password_valid_part_a(password_info: &PasswordInfoA) -> bool {
    let letter_count = password_info
        .password
        .chars()
        .filter(|p| p.to_string() == password_info.required_char)
        .count();
    letter_count >= password_info.min && letter_count <= password_info.max
}

#[derive(Debug)]
struct PasswordInfoB {
    password: String,
    required_char: String,
    position_1: usize,
    position_2: usize,
}

pub fn get_answer_part_b(password_info: &str) -> usize {
    let re = Regex::new(r"^(\d+)-(\d+) ([a-z]): ([a-z]+)$").unwrap();

    let mut info = vec![];
    for line in password_info.split('\n') {
        let groups = re.captures(line).unwrap();
        info.push(PasswordInfoB {
            position_1: groups[1].parse::<usize>().unwrap(),
            position_2: groups[2].parse::<usize>().unwrap(),
            required_char: groups[3].to_string(),
            password: groups[4].to_string(),
        })
    }

    info.into_iter()
        .filter(|password| is_password_valid_part_b(password))
        .count()
}

fn is_password_valid_part_b(password_info: &PasswordInfoB) -> bool {
    let first_char = password_info
        .password
        .chars()
        .nth(password_info.position_1 - 1)
        .unwrap()
        .to_string();

    let second_char = password_info
        .password
        .chars()
        .nth(password_info.position_2 - 1)
        .unwrap()
        .to_string();

    (first_char == password_info.required_char || second_char == password_info.required_char)
        && !(first_char == password_info.required_char
            && second_char == password_info.required_char)
}

fn main() {
    let test_password_info = include_str!("test.dat");
    let real_password_info = include_str!("real.dat");

    println!(
        "part a, test answer: {}",
        get_answer_part_a(test_password_info)
    );

    println!(
        "part a, real answer: {}",
        get_answer_part_a(real_password_info)
    );

    println!(
        "part b, test answer: {}",
        get_answer_part_b(test_password_info)
    );

    println!(
        "part b, real answer: {}",
        get_answer_part_b(real_password_info)
    );
}
