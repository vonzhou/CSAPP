int switch_eg_impl(int x, int n){
	// table of code pointers
	static void *jt[7] = {
		&&loc_A, &&loc_def, &&loc_B, &&loc_C, &&loc_D, &&loc_def, &&loc_D
	};
	
	unsigned index = n - 100;
	int result;

	if(index > 6)
		goto loc_def;

	goto *jt[index];  // computed index 

	loc_def:
		result = 0;
		return ;

	loc_C: // 103
		result = 0;
		goto rest;

	loc_A: // case 100
		result = x * 13;
		goto done;

	loc_B: // case 102
		result = x + 10;
		// fall through

	rest:
		result += 11;
		goto done;

	loc_D:
		result = x * x;
		// fall through
	done:
		return result;
}