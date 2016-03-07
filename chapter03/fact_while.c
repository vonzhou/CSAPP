int fact_while(int n){
	int result = 1;
	while(n > 1){
		result *= n;
		n -= 1;
	}
	return result;
}