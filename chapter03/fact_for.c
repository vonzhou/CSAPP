int fact_for(int n){
	int i;
	int result = 1;
	for(i = 2; i <= n; i ++){
		result *= i;
	}
	return result;
}