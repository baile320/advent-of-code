fn main() {
    let test_landscape: Vec<&[u8]> = include_str!("test.dat")
        .lines()
        .map(|i| i.as_bytes())
        .collect();

    let real_landscape: Vec<&[u8]> = include_str!("real.dat")
        .lines()
        .map(|i| i.as_bytes())
        .collect();

    // part a
    const RIGHT_MOVEMENT: usize = 3;
    const DOWN_MOVEMENT: usize = 1;
    println!(
        "part a, test answer: {}",
        (0..test_landscape.len() - 1)
            .map(|i| ((i + 1) * RIGHT_MOVEMENT, i + DOWN_MOVEMENT))
            .filter(|(x, y)| test_landscape[*y][x % test_landscape[0].len()] == b'#')
            .count()
    );

    println!(
        "part a, test answer: {}",
        (0..real_landscape.len() - 1)
            .map(|i| ((i + 1) * RIGHT_MOVEMENT, i + DOWN_MOVEMENT))
            .filter(|(x, y)| real_landscape[*y][x % real_landscape[0].len()] == b'#')
            .count()
    );

    // part b
    let movements = vec![(1, 1), (3, 1), (5, 1), (7, 1), (1, 2)];

    let mut results: Vec<usize> = vec![];
    for movement in &movements {
        let result = (0..test_landscape.len() - 1)
            .map(|i| ((i + 1) * movement.0, (i + 1) * movement.1))
            .take_while(|(_, y)| y < &test_landscape.len())
            .filter(|(x, y)| test_landscape[*y][x % test_landscape[0].len()] == b'#')
            .count();
        results.push(result);
    }
    println!(
        "results: {:?}, product: {}",
        results,
        results.iter().product::<usize>()
    );

    let mut results: Vec<usize> = vec![];
    for movement in &movements {
        let result = (0..real_landscape.len() - 1)
            .map(|i| ((i + 1) * movement.0, (i + 1) * movement.1))
            .take_while(|(_, y)| y < &real_landscape.len())
            .filter(|(x, y)| real_landscape[*y][x % real_landscape[0].len()] == b'#')
            .count();
        results.push(result);
    }
    println!(
        "results: {:?}, product: {}",
        results,
        results.iter().product::<usize>()
    );
}
