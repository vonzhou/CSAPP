
int acccum = 0;
int sum(int x, int y){
	int t = x + y;
	acccum += t;
	return t;
}