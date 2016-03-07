int gotodiff(int x, int y){
	int result;
	if(x >= y)
		goto x_ge_y;
	result = y - x;
	goto done;
	x_ge_y:
	result = x - y;
	done:
	return result;
}