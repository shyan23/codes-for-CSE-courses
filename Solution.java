import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class TestClass {
    static ArrayList<ArrayList<Integer>> adj_list = new ArrayList<>();
    static int vertices;
    static int edges;
    static boolean[] vis;
    static Queue<Integer> queue;
    static int count;

    static void init_adj_list(int n) {
        adj_list.clear();
        for (int i = 0; i <= n; i++) { // Adjusting for 1-based indexing
            adj_list.add(new ArrayList<>());
        }
    }

    static void init_vis(int n) {
        vis = new boolean[n + 1]; // Adjusting for 1-based indexing
    }

    static void BFS(int k, int startCity) {
        count = 1; // Starting city is already counted
        vis[startCity] = true;
        queue.add(startCity);

        while (!queue.isEmpty() && k > 0) { // Run while fuel is available
            int cityCount = queue.size();
            if (k == 0) break; // If fuel is out, stop

            // Process all cities at the current distance
            for (int j = 0; j < cityCount; j++) {
                int city = queue.poll();

                for (int neighbor : adj_list.get(city)) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = true;
                        queue.add(neighbor);
                        count++; // Increment reachable city count
                    }
                }
            }
            k--; // Decrement fuel after moving to the next "layer" of cities
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m, k, startCity;
        n = sc.nextInt(); // Number of vertices (cities)
        m = sc.nextInt(); // Number of edges (roads)
        k = sc.nextInt(); // Fuel available
        startCity = sc.nextInt(); // Starting city

        init_adj_list(n);
        init_vis(n);
        queue = new LinkedList<>();

        // Reading edges (roads) and creating the adjacency list
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            adj_list.get(x).add(y);
            adj_list.get(y).add(x);
        }

        BFS(k, startCity);
        System.out.println(count); // Output the count of reachable cities
    }
}
