int calculate_speed(int distance, int time) {
    if (time == 0) return -1;  // Evitar división por cero
    return distance / time;
}

//vectorCast stm32 software
void test_calculate_speed() {
    int result = calculate_speed(100, 5);
    assert(result == 20);

    result = calculate_speed(100, 0);
    assert(result == -1);  // Manejo de error
}
