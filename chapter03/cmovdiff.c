int cmovdiff(int x, int y){
	int tval = y - x;
	int rval = x - y;
	int test = x < y;
	if(test)
		rval = tval;
	return rval;
}