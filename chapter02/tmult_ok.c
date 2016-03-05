
int tmult_ok(int x, int y){
    int p = x * y;
    return !x || p / x == y;
}

