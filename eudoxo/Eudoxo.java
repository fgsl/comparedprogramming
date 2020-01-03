/**
 * Java implementation of Eudoxo Algorithm for square root
 * @author Flávio Gomes da Silva Lisboa <flavio.lisboa@fgsl.eti.br>
 **/
class Eudoxo {
	private static double microtime(){
		long mstime = System.currentTimeMillis();
		long seconds = mstime / 1000;
		return (mstime - (seconds * 1000)) / 1000d;		
	}

	public static void main(String args[]){
		if (args.length<2){
			System.out.println("Type: java Eudoxo [number to extract root square] [number of iterations]");
			System.exit(0);
		}

		float p = Float.parseFloat(args[0]); // square
		int n = Integer.parseInt(args[1]); // iterations

		double start = Eudoxo.microtime();

		float x = ((1 + p)/2);

		System.out.println("n=0; x=" + x);

		for (int i=1;i<n;i++){
			x = (((p/x) + x)/2);
			System.out.println("n=" + i + "; x=" + x + "; x^2=" + (x * x));
		}	

		double elapsedtime = microtime() - start;

		System.out.println("Elapsed time: " + Math.round(elapsedtime/1000) + "ms");

		System.out.println("Value of language function:" + Math.sqrt(p) + "\n"); 
	}
}
