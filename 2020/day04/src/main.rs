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

fn main() {
    // part a
    let required_fields = ["ecl", "pid", "eyr", "hcl", "byr", "iyr", "hgt"];

    let test_passports: Vec<&str> = include_str!("test.dat").split("\n\n").collect();
    let test_results = calculate_valid_passports_part_a(&test_passports, &required_fields);
    println!("part a, test results: {}", test_results);

    let real_passports: Vec<&str> = include_str!("real.dat").split("\n\n").collect();
    let real_results = calculate_valid_passports_part_a(&real_passports, &required_fields);
    println!("part a, real results: {}", real_results);
}
