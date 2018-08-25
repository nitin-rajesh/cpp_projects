
public class Fibonacci {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	    int fibo=0;
	    String method="";
	    if (args != null) {
	    	if (args.length >=2) {
	    		fibo = new Integer(args[0]);
	    		method = args[1];
	    	}
	    }
	    long t1 = System.currentTimeMillis();
    	if (method.equals("R") || method.equals("r")) {
    		System.out.println("Calling Recurssive function");
    	}  else {
    		System.out.println("Calling Loop function");
    	}
	    for (int i=0;i<fibo;i++){
	    	
	    	if (method.equals("R") || method.equals("r")) {
	    		System.out.print(badFibo(i) + " ");
	    	} else {
	    		System.out.print(goodFibo(i) + " ");
	    	}
        }
	    long t2 = System.currentTimeMillis();
	    System.out.println("\nExec Time: " + (t2 - t1) + " milli secs");
	}
	
	private static long badFibo(int x){
	    if(x==0) {
	        return 0;
	    }    
	    if (x==1)
	        return 1;
	    return badFibo(x-1) + badFibo(x-2);
	}

	private static long goodFibo(int x){
	    long a=0, b=1;
	    
	    for(int C=1;C<=x/2;C++){
	        a=a+b;
	        b=b+a;
	    }
	    if(( x % 2) != 0)
	        return b;
	    else
	        return a;
	}
	
}
