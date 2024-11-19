import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Cloudy_Days {
    static ArrayList<ArrayList<Integer>> adj_list = new ArrayList<>();
    static ArrayList<ArrayList<Integer>> rev_adj_list = new ArrayList<>();
    static ArrayList<ArrayList<Integer>> Components = new ArrayList<>();
    static int vertices;
    static int edges;
    static boolean[] vis;
    static Stack<Integer> st = new Stack<>();
    static int[] indegree;
    static ArrayList<Integer> Component = new ArrayList<>();
    static int NumComponents;
    static Queue<Integer> queue;

    static void init_queue() {
        queue = new LinkedList<>();
    }



    static void init_adj_list(int n) {
        adj_list.clear(); 
        for (int i = 0; i < n; i++) {
            adj_list.add(new ArrayList<>());
        }
    }


    static void init_vis(int n) {
        vis = new boolean[n];
    }

    static int count = 0;

    static void BFS(int start, int k) {
        vis[start] = true;
        queue.add(start);
        int reachableCities = 1; 
    
        while (!queue.isEmpty() && k > 0) {
            int size = queue.size();  
            k--;  
    
            for (int i = 0; i < size; i++) {
                int Var = queue.poll();
                for (var neighbor : adj_list.get(Var)) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = true;
                        queue.add(neighbor);
                        reachableCities++;  
                    }
                }
            }
        }
    
        count = reachableCities;  
    }
    
    

    public static void main(String[] args) throws FileNotFoundException 
    {
        Scanner sc = new Scanner((System.in));
        int n,m,k,c;
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();
        c = sc.nextInt();

        init_adj_list(n+1);
        init_queue();
        init_vis(n+1);

        for(int i = 0 ; i < m;i++)
        {
            int u = sc.nextInt();
            int v = sc.nextInt();

            adj_list.get(u).add(v);
            adj_list.get(v).add(u);
        }
        BFS(c, k);
        System.out.println(count);
    }
}

