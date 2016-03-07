int exchange(int *xp, int y){
	int x = *xp;
	*xp = y;
	return x;
}