int fact_while_goto(int n){
	int result = 1;
	if(n <= 1)
		goto done;
	loop:
		result *= n;
		n -= 1;
		if(n > 1)
			goto loop;
	done:
		return result;
}