import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    static ArrayList<ArrayList<Integer>>arr = new ArrayList<>();

    static boolean[]vis;

    static void init_arrylist(ArrayList<ArrayList<Integer>>arr,int n)
    {
        for(int i = 0 ; i < n;i++)
        {
            arr.add(new ArrayList<Integer>());
        }
    }   

    static void init_vis(int n)
    {
        vis = new boolean[n];
    }


	public static void main (String[] args) throws java.lang.Exception
	{
        Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

        for(int i = 0 ; i < t; i++)
        {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int q = sc.nextInt();

            init_arrylist(arr,n);
            init_vis(n);

            for(int j = 0 ; j < m;j++)
            {
                int u = sc.nextInt();
                int v = sc.nextInt();
                arr.get(u).add(v);
                arr.get(v).add(u);
            }

            for(int r = 0 ; r < q;r++)
            {
                int a = sc.nextInt();
                int b = sc.nextInt();
            }
        }
        

	}
}