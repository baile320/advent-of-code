// TODO: this problem has a bit-shifting solution
// TODO: could collapse get_seat_row and get_seat_col into one function with an appropriate struct input
// and matching on enums (F/B, L/R) and their associated min/maxes
fn get_seat_row(directions: &str) -> usize {
    let mut current_min_row = 0;
    let mut current_max_row = 127;
    for letter in directions.chars() {
        if letter == 'F' {
            current_max_row = (current_max_row - current_min_row) / 2 + current_min_row;
        } else if letter == 'B' {
            current_min_row = (current_max_row - current_min_row) / 2 + current_min_row + 1;
        }
    }
    current_min_row
}

fn get_seat_col(directions: &str) -> usize {
    let mut current_min_col = 0;
    let mut current_max_col = 7;
    for letter in directions.chars() {
        if letter == 'L' {
            current_max_col = (current_max_col - current_min_col) / 2 + current_min_col;
        } else if letter == 'R' {
            current_min_col = (current_max_col - current_min_col) / 2 + current_min_col + 1;
        }
    }
    current_min_col
}

fn get_seat_id(row: usize, col: usize) -> usize {
    row * 8 + col
}

// TODO: can probably use max_by_key here?
fn get_highest_seat_id(directions: &str) -> usize {
    let mut highest_seat_id = 0;
    for passport_direction in directions.lines() {
        let current_seat_id = get_seat_id(
            get_seat_row(passport_direction),
            get_seat_col(passport_direction),
        );
        if current_seat_id > highest_seat_id {
            highest_seat_id = current_seat_id
        }
    }
    highest_seat_id
}

fn create_seat_list(directions: &str) -> Vec<usize> {
    let mut seat_list = vec![];
    for passport_direction in directions.lines() {
        seat_list.push(get_seat_id(
            get_seat_row(passport_direction),
            get_seat_col(passport_direction),
        ));
    }
    seat_list
}

fn find_seat(sorted_seat_list: Vec<usize>) -> usize {
    // TODO: should use .windows(2).find(|arr| arr[1] - arr[0] > 1)!
    for (idx, seat_num) in sorted_seat_list.iter().enumerate() {
        if sorted_seat_list[idx + 1] - sorted_seat_list[idx] > 1 {
            return seat_num + 1;
        }
    }
    0
}

fn main() {
    let test_directions = include_str!("test.dat");
    let real_directions = include_str!("real.dat");

    // part a
    let seat_id = get_seat_id(get_seat_row(test_directions), get_seat_col(test_directions));
    println!("part a, test data: {}", seat_id);

    let highest_seat_id = get_highest_seat_id(real_directions);
    println!("part a, real data: {}", highest_seat_id);

    // part b
    let mut seat_list = create_seat_list(real_directions);
    seat_list.sort_unstable();
    let found_seat = find_seat(seat_list);

    println!("part b, real data: {}", found_seat);
}
