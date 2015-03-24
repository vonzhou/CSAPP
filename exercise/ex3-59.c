/*
 * 3.59
 */
int switch_prob(int x, int n)
{
    int result = x;

    switch (n) {
    case 42:
    case 40:
            result = x << 3;
            break;
    case 41:
            result += 17;
            break;
    case 43:
            result = x >> 3;
            break;
    case 45:
            result = x * x + 17;
            break;
    case 44:
            result = 49 * x * x;
            break;
    default:
            result += 17;
    }
    return result;
}
