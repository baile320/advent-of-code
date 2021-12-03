use itertools::Itertools;

pub fn get_answer_part_a(expenses: Vec<usize>) -> usize {
    let mut result: usize = 0;
    for value in expenses.iter() {
        for second_value in expenses.iter() {
            if value + second_value == 2020 {
                result = value * second_value;
            }
        }
    }
    result
}

pub fn get_answer_part_b(expenses: Vec<usize>) -> usize {
    expenses
        .into_iter()
        .combinations(3)
        .find(|i| i.iter().sum::<usize>() == 2020)
        .map(|i| i.iter().product::<usize>())
        .unwrap()
}

fn main() {
    let test_expenses: Vec<usize> = include_str!("test.dat")
        .split('\n')
        .map(|i| i.parse::<usize>().unwrap())
        .collect();

    let real_expenses: Vec<usize> = include_str!("real.dat")
        .split('\n')
        .map(|i| i.parse::<usize>().unwrap())
        .collect();

    // part a
    println!(
        "part a, test answer: {}",
        get_answer_part_a(test_expenses.clone())
    );
    println!(
        "part a, real answer: {}",
        get_answer_part_a(real_expenses.clone())
    );

    // part b
    println!("part b, test answer: {}", get_answer_part_b(test_expenses));
    println!("part b, real answer: {}", get_answer_part_b(real_expenses));
}
