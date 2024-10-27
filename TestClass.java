import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class TestClass {
    static ArrayList<ArrayList<Integer>> adj_list = new ArrayList<>();
    static ArrayList<ArrayList<Integer>> rev_adj_list = new ArrayList<>();
    static int vertices;
    static int edges;
    static boolean[] vis;
    static Stack<Integer> st = new Stack<>();
    static int[] sccIds; // To track SCC id of each node
    static int sccCount; // Number of SCCs found
    static ArrayList<ArrayList<Integer>> sccComponents = new ArrayList<>(); // List of SCCs

    // Initialize adjacency list and reverse adjacency list
    static void init_adj_list(int n) {
        adj_list.clear();
        rev_adj_list.clear();
        for (int i = 0; i <= n; i++) {
            adj_list.add(new ArrayList<>());
            rev_adj_list.add(new ArrayList<>());
        }
    }

    static void init_vis(int n) {
        vis = new boolean[n + 1];
    }

    // First DFS to fill the stack in order of finish times
    static void dfs1(int vertex) {
        vis[vertex] = true;
        for (var neighbor : adj_list.get(vertex)) {
            if (!vis[neighbor]) {
                dfs1(neighbor);
            }
        }
        st.push(vertex);
    }

    // Second DFS to collect SCCs from the reverse graph
    static void dfs2(int vertex) {
        vis[vertex] = true;
        sccIds[vertex] = sccCount; // Assign current SCC ID to the node
        sccComponents.get(sccCount).add(vertex); // Add to the current SCC list

        for (var neighbor : rev_adj_list.get(vertex)) {
            if (!vis[neighbor]) {
                dfs2(neighbor);
            }
        }
    }

    static void findSCCs() {
        init_vis(vertices);

        // Step 1: Perform DFS on original graph to fill stack by finish times
        for (int i = 1; i <= vertices; i++) {
            if (!vis[i]) {
                dfs1(i);
            }
        }

        // Step 2: Reverse the graph edges
        init_vis(vertices);
        sccIds = new int[vertices + 1];
        sccCount = 0;

        // Step 3: Process nodes in decreasing order of finish time
        while (!st.isEmpty()) {
            int vertex = st.pop();
            if (!vis[vertex]) {
                sccComponents.add(new ArrayList<>()); // New SCC
                dfs2(vertex);
                sccCount++;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        vertices = sc.nextInt();
        edges = sc.nextInt();

        init_adj_list(vertices);

        // Input graph edges
        for (int i = 0; i < edges; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            adj_list.get(x).add(y);
            rev_adj_list.get(y).add(x); // Build reverse graph
        }

        // Find SCCs
        findSCCs();

        // Output: Check if each SCC has size > 1
        int[] result = new int[vertices + 1];
        for (var scc : sccComponents) {
            if (scc.size() > 1) { // SCC with a cycle
                for (int vertex : scc) {
                    result[vertex] = 1;
                }
            }
        }

        // Print the result
        for (int i = 1; i <= vertices; i++) {
            System.out.print(result[i] + " ");
        }
    }
}
