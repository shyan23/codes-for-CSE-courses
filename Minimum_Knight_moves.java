import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Minimum_Knight_moves {
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

    static void init_Components(int n) {
        Components.clear(); // Clear Components list before initialization
        for (int i = 0; i < n; i++) {
            Components.add(new ArrayList<>());
        }
    }

    static void init_adj_list(int n) {
        adj_list.clear(); // Clear adj_list before initialization
        for (int i = 0; i < n; i++) {
            adj_list.add(new ArrayList<>());
        }
    }

    static void init_rev_adj_list(int n) {
        rev_adj_list.clear(); // Clear rev_adj_list before initialization
        for (int i = 0; i < n; i++) {
            rev_adj_list.add(new ArrayList<>());
        }
    }

    static void init_vis(int n) {
        vis = new boolean[n];
    }


    static int getX(String sc)
    {
        return sc.charAt(0) - 'a';
    }
    static int getY(String sc)
    {
        return sc.charAt(1) - '0';         
    }
    static void Bfs(String sc , String dest)
    {
        int ScX = getX(sc);
        int ScY = getY(sc);

        int desX = getX(dest);
        int desY = getY(dest);

        
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i = 0 ; i < t;i++)
        {
            String source = sc.nextLine();
            String dest = sc.nextLine();

        }
    }
}