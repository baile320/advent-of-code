use std::collections::HashMap;
use std::i64;

fn calculate_valid_passports_part_a(passports: &[&str], required_fields: &[&str]) -> usize {
    passports
        .iter()
        .filter(|passport| {
            required_fields
                .iter()
                .fold(true, |acc, field| passport.contains(field) && acc)
        })
        .count()
}

fn calculate_valid_passports_part_b(passports: &[&str], required_fields: &[&str]) -> usize {
    passports
        .iter()
        .map(|passport| {
            passport
                .split_ascii_whitespace()
                .map(|entry| entry.split_once(':').unwrap())
                .collect::<HashMap<_, _>>()
        })
        .filter(|passport| {
            required_fields
                .iter()
                .fold(true, |acc, field| passport.contains_key(field) && acc)
        })
        .filter(|passport| {
            passport
                .iter()
                .fold(true, |acc, (key, value)| validate_field(key, value) && acc)
        })
        .count()
}

fn validate_field(field: &str, value: &str) -> bool {
    let valid_eyecolors = vec!["amb", "blu", "brn", "gry", "grn", "hzl", "oth"];

    match field {
        "ecl" => {
            for color in valid_eyecolors {
                if value == color {
                    return true;
                }
            }
            false
        }
        "pid" => value.len() == 9 && value.parse::<usize>().is_ok(),
        "eyr" => value.parse::<usize>().unwrap() <= 2030 && value.parse::<usize>().unwrap() >= 2020,
        "hcl" => {
            value.len() == 7
                && value.starts_with('#')
                && i64::from_str_radix(value.trim_start_matches('#'), 16).is_ok()
        }
        "byr" => value.parse::<usize>().unwrap() <= 2002 && value.parse::<usize>().unwrap() >= 1920,
        "iyr" => value.parse::<usize>().unwrap() >= 2010 && value.parse::<usize>().unwrap() <= 2020,
        "hgt" => {
            if value.contains("cm") {
                let height = value.split("cm").next().unwrap().parse::<usize>().unwrap();
                (150..=193).contains(&height)
            } else if value.contains("in") {
                let height = value.split("in").next().unwrap().parse::<usize>().unwrap();
                (59..=76).contains(&height)
            } else {
                false
            }
        }
        "cid" => true,
        _ => panic!("bad field: {}", field),
    }
}

fn main() {
    // part a
    let required_fields = ["ecl", "pid", "eyr", "hcl", "byr", "iyr", "hgt"];

    let test_passports: Vec<&str> = include_str!("test.dat").split("\n\n").collect();
    let test_results = calculate_valid_passports_part_a(&test_passports, &required_fields);
    println!("part a, test results: {}", test_results);

    let real_passports: Vec<&str> = include_str!("real.dat").split("\n\n").collect();
    let real_results = calculate_valid_passports_part_a(&real_passports, &required_fields);
    println!("part a, real results: {}", real_results);

    // part b
    let test_passports: Vec<&str> = include_str!("test.dat").split("\n\n").collect();
    let test_results = calculate_valid_passports_part_b(&test_passports, &required_fields);
    println!("part b, test results: {}", test_results);

    let real_passports: Vec<&str> = include_str!("real.dat").split("\n\n").collect();
    let real_results = calculate_valid_passports_part_b(&real_passports, &required_fields);
    println!("part b, real results: {}", real_results);
}
